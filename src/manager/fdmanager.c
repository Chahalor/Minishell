/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdmanager.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:11:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/29 11:06:29 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Interface |----- */
#include "mmanager.h"

/* -----| Internal  |----- */
#include "_internal/files/_files.h"

#pragma endregion Headers
#pragma region Functions

/**
 * @brief	Opens a file descriptor and registers it in the file descriptor
 * 			manager.
 * 
 * @param	path	The path to the file to open.
 * @param	flags	The flags to use when opening the file.
 * @param	mode	The mode to use when creating the file (if applicable).
 * 
 * @return	the opened file descriptor
 * @retval		>= 0 if the file descriptor is successfully opened and
 * 				registered.
 * @retval		-1 if the file descriptor is invalid (less than 0).
 * @retval		-2 if the file descriptor could not be registered
 * 				due to an internal error.
 *
 * @version	1.0
*/
__attribute__(()) int	fdm_open(
	const char *restrict path,
	const int flags,
	const int mode
)
{
	const int	fd = open(path, flags, mode);

	if (_UNLIKELY(fd < 0))
		return (-1);
	else if (_fdm_store(fd, fd_add) < 0)
	{
		close(fd);
		return (-2);
	}
	return (fd);
}

/**
 * @brief	Closes a file descriptor managed by the file descriptor manager.
 * 
 * @param	fd The file descriptor to close.
 * 
 * @return	The closing result.
 * @retval		0 if the file descriptor is closed successfully.
 * @retval		-1 if the file descriptor is invalid.
 * @retval		-2 if the file descriptor could not be removed from the manager.
 * 
 * @version	1.0
*/
int	fdm_close(
	const int fd
)
{
	if (_UNLIKELY(fd < 0))
		return (-1);
	if (_fdm_store(fd, fd_rm) < 0)
		return (-2);
	return (close(fd));
}

/**
 * @brief	Closes all file descriptors managed by the file descriptor manager.
 * 
 * @return	Returns 0 if successful, -1 if an error occurs.
 * @retval		0 if all file descriptors are closed successfully.
 * @retval		-1 if an error occurs while closing the file descriptors.
 * 
 * @version	1.0
*/
int	fdm_close_all(void)
{
	return (_fdm_store(-1, fd_close_all));
}

/**
 * @brief	Registers a file descriptor in the file descriptor manager.
 * 
 * @param	fd The file descriptor to register.
 * 
 * @return	Returns the file descriptor if successful, -1 if the file descriptor
 * 			is invalid, and -2 if the file descriptor could not be registered.
 * @retval		>= 0 if the file descriptor is successfully registered.
 * @retval		-1 if the file descriptor is invalid (less than 0).
 * @retval		-2 if the file descriptor could not be registered
 * 				due to an internal error.
 * 
 * @version	1.0
 */
int	fdm_register(
	const int fd
)
{
	if (_UNLIKELY(fd < 0))
		return (-1);
	if (_fdm_store(fd, fd_add) < 0)
		return (-2);
	return (fd);
}

/**
 * @brief	Checks if a file descriptor is open in the file descriptor manager.
 * 
 * @param	fd The file descriptor to check.
 * 
 * @return	Returns 1 if the file descriptor is open, 0 otherwise.
 * @retval		1 if the file descriptor is open.
 * @retval		0 if the file descriptor is not open
 * 			or if the file descriptor is invalid.
 * 
 * @version	1.0
 */
int	fdm_is_open(
	const int fd
)
{
	if (_UNLIKELY(fd < 0))
		return (0);
	else
		return (_fdm_store(fd, fd_is_open));
}

#pragma endregion Functions