/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/22 13:55:39 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_builtin.h"

/* -----| Modules   |----- */
#include "builtin.h"
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief Show the history.
 * 
 * @param args The arguments
 * 
 * @return 0 on success, -1 on error
*/
__attribute__((used)) char	bltin_history(
	const char *const restrict *const restrict args
)
{
	int			i;
	char	**history = rl_get_history();

	(void)args;
	if (_UNLIKELY(!history))
		return (perror("Error: rl_get_history() failed"), -1);
	i = -1;
	while (++i < 1024)
		ft_printf("%d: <%s>\n", i, history[i]);
	return (0);
}

#pragma endregion Fonctions