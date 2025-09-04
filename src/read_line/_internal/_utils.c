/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:57:20 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/04 14:08:44 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
#include "_read_line.h"

/* -----| Modules  |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Sets the terminal to raw mode.
 * 
 * @param	t The termios structure to modify.
 * 
 * @return	Void
*/
__attribute__((always_inline, used)) inline void	_set_raw(
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
__attribute__((always_inline, used)) inline void	_set_default(
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

/**
 * @brief	Move the cursor to the specified position.
 * 
 * @param	row The row to move the cursor to.
 * @param	col The column to move the cursor to.
 * 
 * @return	None
 * 
 * @note	Use ANSI escape codes to move the cursor.
*/
__attribute__((always_inline, used)) inline void	move_cursor(
	const int row,
	const int col
)
{
	printf("\033[%d;%dH", row, col);
}

/**
 * @brief	Saves the current cursor position.
 *
 * @return	None
 *
 * @note	Use ANSI escape codes to save the cursor position.
 *			This is useful for restoring the cursor position later.
 */
__attribute__((always_inline, used)) inline void	save_cursor(void)
{
	write(STDOUT_FILENO, "\033[s", 3);
}

/**
 * @brief	Restores the saved cursor position.
 *
 * @return	None
 *
 * @note	Use ANSI escape codes to restore the cursor position.
 */
__attribute__((always_inline, used)) inline void	restore_cursor(void)
{
	write(STDOUT_FILENO, "\033[u", 3);
}

#pragma endregion Fonctions