/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:04:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/27 10:34:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
#include "utils.h"

/* -----| Modules  |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Checks the type of a file at the given path.
 * 
 * @param	path		The path to the file to check.
 * @param	access_mode	The access mode to check (F_OK, R_OK, W_OK, X_OK).
 * 
 * @return	Returns the type of the file.
 * @retval		0, not_found if the file does not exist.
 * @retval		1, file if the file is a regular file.
 * @retval		2, directory if the file is a directory.
 * @retval		3, symlink if the file is a symbolic link.
 * @retval		4, unknown if the file type is unknown.
 * @retval		5, executable if the file is executable.
 * 
 * @version	1.0
 */
__attribute__((used)) int	check_path(
	const char *const restrict path,
	const int access_mode
)
{
	struct stat	file_stat;

	if (_UNLIKELY(!path))
		return (0);
	else if (access(path, access_mode))
		return (e_not_found);
	else
	{
		if (stat(path, &file_stat) < 0)
			return (perror("check_file(): stat() failed\n"), 0);
		else if (S_ISLNK(file_stat.st_mode))
			return (e_symlink);
		else if (S_ISREG(file_stat.st_mode))
		{
			if (access(path, X_OK) == 0)
				return (e_executable);
			else
				return (e_file);
		}
		else if (S_ISDIR(file_stat.st_mode))
			return (e_directory);
		else
			return (e_unknown);
	}
}

#pragma endregion Fonctions