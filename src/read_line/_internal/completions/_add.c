/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _add.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:43:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/29 13:50:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Functions

int	_rl_completion_add(
	t_rl_completion *completion,
	const char *const restrict word,
	struct dirent *entry
)
{
	register int	i;

	if (_UNLIKELY(!completion || !word))
		return (-1);
	if (ft_strncmp(entry->d_name, word, ft_strlen(word)) != 0)
		return (1);
	i = -1;
	while (++i < completion->nb_entries)
		if (ft_strncmp(completion->entry[i]->d_name, entry->d_name, ft_strlen(entry->d_name)) == 0)
			return (1);
	completion->entry[completion->nb_entries++] = memdup(entry, sizeof(t_dirent));
	return (0);
}

#pragma endregion Functions