/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _files.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/16 16:08:30 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_parser.h"

/* -----| Modules   |----- */
#include "parser.h"
#include "env.h"

#pragma endregion Header
#pragma region Fonctions

extern volatile sig_atomic_t	g_last_signal;

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

	paths = ft_split(env_find("PATH"), ':');
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

	if (_UNLIKELY(!name))
		return (NULL);
	else if (get_builtins(name))
		return (name);
	path = get_in_path(name);
	if (_LIKELY(path != NULL))
		return (path);
	file_type = check_path(name, F_OK | X_OK);
	if (_UNLIKELY(file_type == e_not_found))
	{
		ft_fprintf(2, SHELL_NAME ": %s: command not found\n", name);
		return (NULL);
	}
	else if (file_type == e_perm_denied)
	{
		ft_fprintf(2, SHELL_NAME ": %s: Permission denied\n", name);
		g_last_signal = 126;
		return (NULL);
	}
	else
		return (name);
}

extern inline int	_check_dir(
	const char *const restrict path
)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) != 0)
		return (0);
	else if (S_ISDIR(path_stat.st_mode))
	{
		ft_fprintf(2, SHELL_NAME ": %s: Is a directory\n", path);
		g_last_signal = 126;
		return (1);
	}
	return (0);
}

#pragma endregion Fonctions