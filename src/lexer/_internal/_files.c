/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _files.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/27 10:06:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_lexer.h"

/* -----| Modules   |----- */
#include "lexer.h"

#pragma endregion Header
#pragma region Fonctions

// /**
//  * @brief	Checks the type of a file at the given path.
//  * 
//  * @param	path		The path to the file to check.
//  * @param	access_mode	The access mode to check (F_OK, R_OK, W_OK, X_OK).
//  * 
//  * @return	Returns the type of the file.
//  * @retval		0, not_found if the file does not exist.
//  * @retval		1, file if the file is a regular file.
//  * @retval		2, directory if the file is a directory.
//  * @retval		3, symlink if the file is a symbolic link.
//  * @retval		4, unknown if the file type is unknown.
//  * 
//  * @version	1.0
//  */
// __attribute__((always_inline, used)) static inline t_file_type	check_path(
// 	const char *const restrict path,
// 	const int access_mode
// )
// {
// 	struct stat	file_stat;

// 	if (_UNLIKELY(!path))
// 		return (0);
// 	else if (access(path, access_mode))
// 		return (e_not_found);
// 	else
// 	{
// 		if (stat(path, &file_stat) < 0)
// 			return (perror("check_file(): stat() failed\n"), 0);
// 		else if (S_ISREG(file_stat.st_mode))
// 			return (e_file);
// 		else if (S_ISDIR(file_stat.st_mode))
// 			return (e_directory);
// 		else if (S_ISLNK(file_stat.st_mode))
// 			return (e_symlink);
// 		else
// 			return (e_unknown);
// 	}
// }

/**
 * @brief	Searches for a command in the PATH environment variable.
 * 
 * @param	name	The name of the command to search for.
 * 
 * @return	Returns the full path of the command if found, NULL otherwise.
 * @retval		NULL if the command is not found or if an error occurs.
 * 
 * @version	1.0
 */
__attribute__((always_inline, used)) static inline char	*get_in_path(
	const char *const restrict name
)
{
	char			**paths;
	char			*full_path;
	register int	i;

	paths = ft_split(getenv("PATH"), ':');
	if (_UNLIKELY(!paths))
		return (perror("get_in_path(): ft_split() failed"), NULL);
	i = -1;
	while (paths[++i])
	{
		full_path = path_join(paths[i], name, ft_strlen(name));
		if (_UNLIKELY(!full_path))
			return (perror("get_in_path(): path_join() failed"), NULL);
		if (check_path(full_path, F_OK | X_OK) == e_executable)
			return (free_tab(paths), full_path);
		else
			mm_free(full_path);
	}
	return (free_tab(paths), NULL);
}

__attribute__((used)) inline char	*_get_bin(
	char *name
)
{
	char	*path;
	int		file_type;

	if (get_builtins(name))
		return (name);
	path = get_in_path(name);
	if (_LIKELY(path != NULL))
		return (path);
	file_type = check_path(name, F_OK | X_OK);
	if (_UNLIKELY(file_type == e_directory))
		return (ft_fprintf(STDERR_FILENO,
				SHELL_NAME ": %s: is a directory\n", name), NULL);
	else if (_UNLIKELY(file_type == e_not_found))
		return (ft_fprintf(STDERR_FILENO,
				SHELL_NAME ": %s: command not found\n", name), NULL);
	else
		return (name);
}

#pragma endregion Fonctions