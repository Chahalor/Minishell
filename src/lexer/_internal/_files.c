/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _files.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/29 15:53:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_lexer.h"

/* -----| Modules   |----- */
#include "lexer.h"

#pragma endregion Header
#pragma region Fonctions

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