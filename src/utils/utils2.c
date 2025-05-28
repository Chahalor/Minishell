/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:04:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/28 17:04:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
#include "utils.h"

/* -----| Modules  |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((used)) int	ft_atoi(
	const char *restrict str
)
{
	register int	result;
	register int	sign;

	if (__builtin_expect(!str, unexpected))
		return (0);
	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		++str;
	}
	return (result * sign);
}

#pragma endregion Fonctions