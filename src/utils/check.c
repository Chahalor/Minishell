/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 08:32:59 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/16 08:33:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
#include "utils.h"

/* -----| Modules  |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

extern inline int	ft_is_space(
	const char c
)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

#pragma endregion Fonctions