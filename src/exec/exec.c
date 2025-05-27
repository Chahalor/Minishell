/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/27 16:31:41 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_exec.h"

/* -----| Modules   |----- */
#include "exec.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Redirects the output of a file descriptor to another file descriptor.
 * 
 * @param	fd		The file descriptor to redirect.
 * @param	new_fd	The file descriptor to redirect to.
 * 
 * @return	Returns the status of the redirection.
 * @retval		~0 if the redirection was successful.
 * @retval		-1 if the file descriptor is invalid.
 * @retval		-2 if the dup2() failed.
 * @retval		-3 if the close() failed.
 * 
 * @version	1.0
*/
__attribute__((always_inline, used)) static inline int	_redirect(
	const int fd,
	const int new_fd
)
{
	return (((fd < 0 || new_fd < 0) * -1)
		|| ((dup2(fd, new_fd) < 0) * -2)
		|| ((close(fd) < 0) * -3));
}

__attribute__((always_inline, used)) static inline int	_analyse(
	const int status
)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	else
		return (-1);
}

__attribute__((always_inline, used)) static inline int	_wait_childrens(
	t_exec_data *const restrict data
)
{
	int						status;
	t_exec_data	*restrict	current;

	current = data;
	while (current)
	{
		if (current->pid)
		{
			waitpid(data->pid, &status, 0);
			data->status = _analyse(status);
		}
		current = data->next;
	}
	return (0);
}

/**
 * @brief	Executes a command with its arguments. And if it need to execute
 * 			another command after it, it will do so.
 * 
 * @param	data	Execution data structure containing the command and its
 * 				arguments.
 * @param	envp	Environment variables to pass to the command.
 * @param	fd		File descriptor to redirect the output of the command.
 * 
 * @return	Returns the status of the command execution.
 * @retval		~0 if the command executed successfully.
 * @retval		-1 if the execve() failed.
 * @retval		-2 if the fork() failed.
 * 
 * @version	1.1
*/
__attribute__((hot))	int	exec_bin(
	t_exec_data *const restrict data,
	char *const envp[],
	const int prev_read,
	const int out_fd
)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (prev_read != STDIN_FILENO && prev_read != -1)
			_redirect(prev_read, STDIN_FILENO);
		if (out_fd != STDOUT_FILENO && out_fd != -1)
			_redirect(out_fd, STDOUT_FILENO);
		execve(data->cmd, data->args, envp);
		return (exit_program(127, "exec_bin(): execve() failed"), -1);
	}
	else if (pid < 0)
		return (perror("exec_bin(): fork() failed"), -2);
	else
	{
		data->pid = pid;
		set_last_child(pid);
		return (0);
	}
}

/**
 * @brief	Executes all commands in the order of data.
 * 				If a command has a pipe, it will create the pipe and
 * 				redirect the output of the previous command to the input of the
 * 				next command. It will execut all pipe one by one.
 * @param	data	Execution data structure containing the commands and their
 * 				arguments.
 * @param	envp	Environment variables to pass to the commands.
 * 
 * @return	Returns the status of the command execution.
 * @retval		~0 if the command executed successfully.
 * @retval		-1 if the pipe() failed.
 * 
 * @version	1.0
 */
int	full_exec(
	t_exec_data *const restrict data,
	char *const envp[]
)
{
	t_exec_data	*current;
	int			pipe_fd[2];
	int			prev_read;
	int			out_fd;

	register int i = 0;

	prev_read = -1;
	current = data;
	while (current && i++ < 10)
	{
		out_fd = STDOUT_FILENO;
		if (current->pipe)
		{
			if (_UNLIKELY(pipe(pipe_fd) < 0))
				return (perror("pipe() failed"), -1);
			out_fd = pipe_fd[1];
			current->fd_out = pipe_fd[1];
		}
		if (get_builtins(current->args[0]))
			exec_builtin(current, envp, prev_read, out_fd);
		else
			exec_bin(current, envp, prev_read, out_fd);
		if (prev_read > 0 && prev_read != STDIN_FILENO)
			close(prev_read);
		if (current->pipe)
		{
			close(pipe_fd[1]);
			prev_read = pipe_fd[0];
			current = current->pipe;
		}
		else
			current = NULL;
	}
	_wait_childrens(data);
	return (0);
}

#pragma endregion Fonctions
