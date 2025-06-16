/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/16 11:50:42 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_exec.h"
#include "_redirections.h"

/* -----| Modules   |----- */
#include "exec.h"

#pragma endregion Header
#pragma region Fonctions

extern volatile sig_atomic_t	g_last_signal;

/** */
__attribute__((always_inline, used)) static inline char	_check_perms(
	const char *const restrict path
)
{
	if (access(path, X_OK) == 0)
		return (1);
	else if (access(path, F_OK) == 0)
		perror("exec_bin(): Permission denied");
	else
		perror("exec_bin(): Command not found");
	return (0);
}

/**
 * @brief	Closes the previous read file descriptor and returns the next command
 * 			to execute. If the current command has a pipe, it will close the
 * 			output file descriptor and set the previous read file descriptor to
 * 			the input file descriptor of the pipe.
 * 
 * @param	prev_read	Pointer to the previous read file descriptor.
 * @param	out_fd		Output file descriptor to close if the current
 * 							command has a pipe.
 * @param	current		Current execution data structure.
 * @param	pipe_fd		File descriptors of the pipe.
 * 
 * @return	Returns the next command to execute.
 * @retval		NULL if there is no next command.
 * @retval		next if there is a next command.
 * 
 * @version 1.0
 */
__attribute__((always_inline, used)) static inline t_exec_data	*_closing(
	int *const prev_read,
	const int out_fd,
	t_exec_data *const restrict current,
	const int *const pipe_fd
)
{
	t_exec_data	*next;

	if (*prev_read > 0 && *prev_read != STDIN_FILENO)
		close(*prev_read);
	if (current->pipe)
	{
		close(out_fd);
		*prev_read = pipe_fd[0];
		next = current->pipe;
	}
	else
		next = NULL;
	return (next);
}

__attribute__((always_inline, used)) static inline char	_exec_one(
	t_exec_data *const restrict current,
	char *const envp[]
)
{
	int	in_fd;
	int	out_fd;

	in_fd = -1;
	out_fd = STDOUT_FILENO;
	out_fd += (current->fd_out > 0) * (current->fd_out - STDOUT_FILENO);
	if (current->fd_in > 0)
		in_fd = current->fd_in;
	if (get_builtins(current->args[0]))
		exec_builtin(current, envp, in_fd, out_fd);
	else
		exec_bin(current, envp, in_fd, out_fd);
	_wait_childrens(current);
	return (0);
}

__attribute__((always_inline, used)) static inline char	_exec_pipes(
	t_exec_data *const restrict data,
	char *const envp[]
)
{
	t_exec_data	*current;
	int			pipe_fd[2];
	int			prev_read;
	int			out_fd;

	prev_read = -1;
	current = data;
	while (current)
	{
		out_fd = STDOUT_FILENO;
		out_fd += (current->fd_out > 0) * (current->fd_out - STDOUT_FILENO);
		if (current->pipe)
			if (_UNLIKELY(_piping(pipe_fd, &out_fd) < 0))
				return (-1);
		if (get_builtins(current->args[0]))
			exec_builtin_fork(current, envp, prev_read, out_fd);
		else
			exec_bin(current, envp, prev_read, out_fd);
		current = _closing(&prev_read, out_fd, current, pipe_fd);
	}
	_wait_childrens(data);
	return (0);
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
 * @version	1.1
 */
int	full_exec(
	t_exec_data *const restrict data,
	char *const envp[]
)
{
	if (data->pipe)
		return (_exec_pipes(data, envp));
	else
		return (_exec_one(data, envp));
}

#pragma endregion Fonctions