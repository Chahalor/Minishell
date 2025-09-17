/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pipe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 10:47:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Internals |----- */
#include "_redirections.h"

/* -----| Modules   |----- */
#include "exec.h"

/**
 * @brief	Creates a pipe and registers its file descriptors.
 * 
 * @param	pipe_fd		Array to store the file descriptors of the pipe.
 * @param	out_fd		Pointer to store the output file descriptor.
 * 
 * @return	Returns the status of the pipe creation.
 * @retval		~0 if the pipe was created successfully.
 * @retval		-1 if the pipe() failed.
 * 
 * @version	2.0
 */
__attribute__((always_inline, used)) inline int	_piping(
	int pipe_fd[2],
	int *const restrict out_fd
)
{
	if (_UNLIKELY(pipe(pipe_fd) < 0))
		return (perror("full_exec(): pipe failed"), -1);
	if (_LIKELY(out_fd != NULL))
		*out_fd = pipe_fd[1];
	fdm_register(pipe_fd[0]);
	fdm_register(pipe_fd[1]);
	return (0);
}
