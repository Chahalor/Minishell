/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _in.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/04 16:21:14 by nduvoid          ###   ########.fr       */
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
 * @brief	Redirects the input from a file to the standard input (STDIN).
 * 
 * @param	char	*file The file to redirect input from.
 * 
 * @return	Returns the file descriptor of the redirected input.
 * * @retval		<0 the opened file descriptor.
 * * @retval		-1 if no file was specified.
 * * @retval		-2 if the file does not exist.
 * * @retval		-3 if the open() failed.
 * * @retval		-4 if the dup2() failed.
 * 
 * @version	1.0
*/
__attribute__((always_inline, used)) inline int	_infile(
	const char *const restrict file
)
{
	int	fd;

	if (_UNLIKELY(!file))
		return (ft_perror("infile: no file specified"), -1);
	else if (_UNLIKELY(access(file, F_OK)))
		return (ft_perror("infile: file does not exist"), -2);
	fd = open(file, O_RDONLY);
	if (_UNLIKELY(fd < 0))
		return (ft_perror("infile: open() failed"), -3);
	else if (_UNLIKELY(_redirect(fd, STDIN_FILENO) < 0))
	{
		close(fd);
		return (ft_perror("infile: dup2() failed"), -4);
	}
	fdm_register(fd);
	return (fd);
}

#pragma endregion Fonctions