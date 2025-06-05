/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minrc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/05 16:50:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
#include "_signals.h"

/* -----| Modules  |----- */
#include "signals.h"

#pragma endregion Header
#pragma region Fonctions

int	load_minirc(
	const char *const restrict path
)
{
	const int fd = fdm_open(path, O_RDONLY, 0644);

}

#pragma endregion Fonctions