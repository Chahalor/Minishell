/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 09:31:13 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/**
 *  @brief Resets the command line settings to their default state.
 * 
 *  @note This function is intended to be used when the command line
 *  is no longer needed and should be restored to its original state.
*/
__attribute__((visibility("hidden"), used, cold)) void	_rl_reset_cmd(void)
{
	struct termios	oldt;
	struct termios	restore;

	_neutral(&restore, sizeof(struct termios));
	tcgetattr(STDIN_FILENO, &oldt);
	restore = oldt;
	_set_default(&restore);
}

/** */
__attribute__((visibility("hidden"), used, cold)) t_history	*_rl_get_all(void)
{
	return ((struct s_history *)_history_manager(rl_get_all, NULL));
}

#pragma endregion Fonctions