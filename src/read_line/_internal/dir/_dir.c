/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dir.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/27 12:56:47 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Get the directory part of a path.
 * 
 * @param	path The path to extract the directory from.
 * 
 * @return	A dynamically allocated string containing the directory part
 * 			of the path.
 * @retval	NULL if the path is NULL or empty.
*/
__attribute__((used, visibility("hidden"))) char	*_get_dir(
	const char *const restrict path
)
{
	register int	i;
	char			*result;

	if (_UNLIKELY(!path || !*path))
		return (NULL);
	i = ft_strlen(path);
	while (i > 0 && path[i - 1] != '/')
		--i;
	if (!path[i])
		++i;
	else if (!i)
		return (memdup("./", 3));
	result = mm_alloc(i + 1);
	if (_UNLIKELY(!result))
		return (NULL);
	ft_memcpy(result, path, i);
	result[i] = '\0';
	return (result);
}

/**
 *  @brief	Get the file part of a path.
 * 
 *  @param	path The path to extract the file from.
 * 
 * @return	A dynamically allocated string containing the file part
 * 			of the path.
 * @retval	NULL if the path is NULL or empty.
 * @retval	A pointer to the file name part of the path.
*/
__attribute__((used, visibility("hidden"))) char	*_get_file(
	const char *const restrict path
)
{
	register int	i;
	char			*result;

	if (_UNLIKELY(!path || !*path))
		return (NULL);
	i = ft_strlen(path);
	while (i > 0 && path[i - 1] != '/')
		--i;
	result = mm_alloc(ft_strlen(path) - i + 1);
	if (_UNLIKELY(!result))
		return (NULL);
	ft_memcpy(result, path + i, ft_strlen(path) - i);
	result[ft_strlen(path) - i] = '\0';
	return (result);
}

__attribute__((used, visibility("hidden"))) void	_add_builtin(
	t_rl_completion *const restrict completion,
	const char *const restrict path_file
)
{
	static const char	*builtins[] = {
		"cd", "echo", "env", "exit", "export",
		"pwd", "unset", "history", NULL};
	t_dirent			entry;
	register int		i;

	i = -1;
	while (builtins[++i])
	{
		if (ft_strncmp(builtins[i], path_file, ft_strlen(path_file)) == 0)
		{
			_neutral(entry.d_name, sizeof(entry.d_name));
			entry.d_type = DT_REG;
			ft_memcpy(entry.d_name, builtins[i], ft_strlen(builtins[i]));
			completion->entry[completion->nb_entries++]
				= memdup(&entry, sizeof(t_dirent));
		}
	}
}

#pragma endregion Fonctions