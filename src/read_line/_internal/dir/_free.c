/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _free.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/03 10:23:43 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"
#include <dirent.h>

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/** 
 * @brief	Free the memory allocated for the completion entries.
 * 
 * @param	data The completion data structure containing the entries.
 * 
 * @return	None
 */
__attribute__((always_inline, used)) inline void	_free_completion(
	t_rl_completion *const restrict data
)
{
	register int	i;

	if (_UNLIKELY(!data))
		return ;
	i = -1;
	while (++i < data->nb_entries)
	{
		if (_UNLIKELY(!data->entry[i]))
			continue ;
		mm_free(data->entry[i]);
		data->entry[i] = NULL;
	}
	data->nb_entries = 0;
}

#pragma endregion Fonctions