/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:57:20 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/23 18:04:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "interraction__.h"

/* -----| Modules  |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Sets the terminal to raw mode.
 * 
 * @param	t The termios structure to modify.
 * 
 * @return	Void
*/
__attribute__((always_inline, used))
inline void	_rl_set_raw__(
	struct termios *t
)
{
	t->c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	t->c_oflag &= ~(OPOST);
	t->c_cflag |= (CS8);
	t->c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	t->c_cc[VMIN] = 1;
	t->c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, t);
}

/**
 * @brief	Sets the terminal to default mode.
 * 
 * @param	t The termios structure to modify.
 * 
 * @return	Void
*/
__attribute__((always_inline, used))
inline void	_rl_set_default__(
	struct termios *t
)
{
	t->c_iflag |= (BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	t->c_oflag |= (OPOST);
	t->c_cflag &= ~(CSIZE);
	t->c_cflag |= (CS8);
	t->c_lflag |= (ECHO | ICANON | IEXTEN | ISIG);
	t->c_cc[VMIN] = 1;
	t->c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, t);
}

#pragma endregion Fonctions