/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdmanager.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:11:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/28 16:25:30 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Interface |----- */
#include "mmanager.h"

/* -----| Internal  |----- */
#include "_files.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__(()) int	fdm_open(
	const char *restrict path,
	const int flags,
	const int mode
)
{
	const int	fd = open(path, flags, mode);

	if (_UNLIKELY(fd < 0))
		return (-1);
	else if (_mfd_store(fd, fd_add) < 0)
	{
		close(fd);
		return (-2);
	}
	return (fd);
}

/** */
int	fdm_close(
	const int fd
)
{
	if (_UNLIKELY(fd < 0))
		return (-1);
	if (_mfd_store(fd, fd_rm) < 0)
		return (-2);
	return (close(fd));
}

/** */
int	fdm_close_all(
	void
)
{
	return (_mfd_store(-1, fd_close_all));
}

int	fdm_register(
	const int fd
)
{
	if (_UNLIKELY(fd < 0))
		return (-1);
	if (_mfd_store(fd, fd_add) < 0)
		return (-2);
	return (fd);
}

int fdm_is_open(
	const int fd
)
{
	if (_UNLIKELY(fd < 0))
		return (0);
	else
		return (_mfd_store(fd, fd_is_open));
}

#pragma endregion Functions