/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dir.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/12 12:38:01 by nduvoid          ###   ########.fr       */
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

/** */
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
	result = mm_alloc(i + 1);
	if (_UNLIKELY(!result))
		return (NULL);
	ft_memcpy(result, path, i);
	result[i] = '\0';
	return (result);
}

/** */
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

#pragma endregion Fonctions