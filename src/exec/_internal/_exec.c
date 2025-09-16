/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _exec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/16 11:29:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_exec.h"

/* -----| Modules   |----- */
#include "exec.h"

#pragma endregion Header
#pragma region Prototypes

extern int	_analyse(const int status);

#pragma endregion Prototypes
#pragma region Fonctions

extern sig_atomic_t	g_last_signal;

/**
 * @brief	Waits for all child processes to finish and updates their status.
 * 
 * @param	data	The execution data structure containing the child processes.
 * 
 * @return	Returns 0 on success.
 * @retval		0 if all child processes have been waited for successfully.
 * 
 * @version	1.0
 */
__attribute__((always_inline, used)) inline int	_wait_childrens(
	t_exec_data *const restrict data,
	const int exit_code
)
{
	int			status;
	t_exec_data	*curr;
	int			last_exit;

	status = 0;
	curr = (t_exec_data *)data;
	if (_LIKELY(curr->pid > 0 && waitpid(curr->pid, &status, 0) != -1))
		curr->status = _analyse(status);
	last_exit = curr->status;
	if (_LIKELY(curr->pipe != NULL))
		last_exit = _wait_childrens(curr->pipe, exit_code);
	if (exit_code != -1)
		last_exit = exit_code;
	g_last_signal = last_exit;
	return (last_exit);
}

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
	if (_UNLIKELY(fd < 0))
		return (-1);
	else
	{
		dup2(fd, new_fd);
		fdm_close(fd);
		return (0);
	}
}

/**
 * @brief	All logic for the child process when executing a command.
 * 
 * @param	data	Execution data structure containing the command and its
 * 				arguments.
 * @param	envp	Environment variables to pass to the command.
 * @param	prev_read	File descriptor to redirect the input of the command.
 * @param	out_fd	File descriptor to redirect the output of the command.
 * 
 * @return	Does not return, will exit the child process with an error message
 * 			if the execve() fails.
 * 
 * @version 1.0
 */
__attribute__((always_inline, used, noreturn))
static inline int	_child(
	t_exec_data *const restrict data,
	char *const envp[],
	const int prev_read,
	const int out_fd
)
{
	if (data->fd_in != STDIN_FILENO && data->fd_in > 0)
		_redirect(data->fd_in, STDIN_FILENO);
	else if (prev_read != STDIN_FILENO && prev_read > 0)
		_redirect(prev_read, STDIN_FILENO);
	if (out_fd != STDOUT_FILENO && out_fd > 0)
		_redirect(out_fd, STDOUT_FILENO);
	fdm_close_all();
	reset_signal();
	if (_UNLIKELY(!data->cmd))
		exit_program(EXIT_FAILURE, NULL);
	execve(data->cmd, data->args, envp);
	exit_program(127, NULL);
	exit(EXIT_FAILURE);
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
 * @retval		=0 if the command executed successfully.
 * @retval		-1 if the fork() failed.
 * 
 * @version	1.2
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
		_child(data, envp, prev_read, out_fd);
	else if (pid > 0)
	{
		data->pid = pid;
		if (prev_read > 0)
			fdm_close(prev_read);
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
		return (0);
	}
	else
		return (perror("exec_bin(): fork() failed"), -1);
}

#pragma endregion Fonctions