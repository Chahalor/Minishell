/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _add.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:43:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/29 13:55:28 by nduvoid          ###   ########.fr       */
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

int	_rl_comp_add(
	t_rl_completion *comp,
	const char *const restrict word,
	struct dirent *entry
)
{
	register int	i;

	if (_UNLIKELY(!comp || !word))
		return (-1);
	if (ft_strncmp(entry->d_name, word, ft_strlen(word)) != 0)
		return (1);
	i = -1;
	while (++i < comp->nb_entries)
		if (ft_strncmp(comp->entry[i]->d_name, entry->d_name,
				ft_strlen(entry->d_name)) == 0)
			return (1);
	comp->entry[comp->nb_entries++] = memdup(entry, sizeof(t_dirent));
	return (0);
}

#pragma endregion Functions