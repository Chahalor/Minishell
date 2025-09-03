/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:06:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/03 10:35:26 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"

/* -----| Modules  |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((always_inline, used)) inline void	_init_cmd(
	t_rl_data *const restrict data
)
{
	tcgetattr(STDIN_FILENO, &data->terms.oldt);
	data->terms.raw = data->terms.oldt;
	data->terms.resore = data->terms.oldt;
	_set_raw(&data->terms.raw);
	write(STDOUT_FILENO, "\033[?2004h", 8);
	write(STDOUT_FILENO, data->prompt, ft_strlen(data->prompt));
}

#pragma endregion Fonctions