/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _files.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:11:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/28 16:34:12 by nduvoid          ###   ########.fr       */
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
int	_fdm_store(
	const int fd,
	const t_fd_access access
)
{
	static int		_storage[FDM_MAX_FD] = {0};
	register int	i;

	if (access == fd_add)
		_storage[fd] = 1;
	else if (access == fd_rm)
		_storage[fd] = 0;
	else if (access == fd_close_all)
	{
		i = -1;
		while (++i < FDM_MAX_FD)
		{
			if (_storage[i])
			{
				close(i);
				_storage[i] = 0;
			}
		}
	}
	else if (access == fd_is_open)
		return (_storage[fd]);
	return (-1);
}

#pragma endregion Functions