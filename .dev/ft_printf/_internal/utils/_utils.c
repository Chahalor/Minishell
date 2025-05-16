/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:51:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/16 15:55:41 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_ft_printf.h"

/* -----| Modules   |----- */
#include "ft_printf.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((always_inline, used)) inline int	ft_strlen(
	const char *const restrict s
)
{
	register int	i;

	if (__builtin_expect(!s, unexpected))
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

#pragma endregion Fonctions