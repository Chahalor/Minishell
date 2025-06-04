/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _outfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/04 16:19:28 by nduvoid          ###   ########.fr       */
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

/**
 * @brief	Redirects the output to a file, truncating it if it exists.
 * 
 * @param	file	The file to redirect output to.
 * 
 * @return	Returns the file descriptor of the redirected output.
 * @retval		<0 the opened file descriptor.
 * @retval		-1 if no file was specified.
 * @retval		-2 if the open() failed.
 * @retval		-3 if the dup2() failed.
 *
 * @version	1.0
*/
__attribute__((always_inline, used)) inline int	_outtrunc(
	const char *const restrict file
)
{
	int	fd;

	if (_UNLIKELY(!file))
		return (ft_perror("outfile: no file specified"), -1);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (_UNLIKELY(fd < 0))
		return (ft_perror("outfile: open() failed"), -2);
	else if (_UNLIKELY(_redirect(fd, STDOUT_FILENO) < 0))
	{
		close(fd);
		return (ft_perror("outfile: dup2() failed"), -3);
	}
	fdm_register(fd);
	return (fd);
}

/**
 * @brief	Redirects the output to a file, appending to it if it exists.
 * 
 * @param	file	The file to redirect output to.
 *
 * @return	Returns the file descriptor of the redirected output.
 * @retval		<0 the opened file descriptor.
 * @retval		-1 if no file was specified.
 * @retval		-2 if the open() failed.
 * @retval		-3 if the dup2() failed.
 *
 * @version	1.0
*/
__attribute__((always_inline, used)) inline int	_outappend(
	const char *const restrict file
)
{
	int	fd;

	if (_UNLIKELY(!file))
		return (ft_perror("outfile: no file specified"), -1);
	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (_UNLIKELY(fd < 0))
		return (ft_perror("outfile: open() failed"), -2);
	else if (_UNLIKELY(_redirect(fd, STDOUT_FILENO) < 0))
	{
		close(fd);
		return (ft_perror("outfile: dup2() failed"), -3);
	}
	fdm_register(fd);
	return (fd);
}

#pragma endregion Fonctions