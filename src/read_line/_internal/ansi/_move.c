/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _move.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:19:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/26 16:48:50 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((always_inline, used)) static inline int	_is_whitespace(
	const char c
)
{
	return (c == ' ' | c == '\t' | c == '\n' | c == '\r');
}

/** */
static inline int	_skip(
	t_rl_data *const restrict data,
	const char action
)
{
	register int	i;

	i = data->cursor_pos;
	if (i > 0 && action == 'D')
	{
		while (i > 0 && _is_whitespace(data->result[i - 1]))
			--i;
		while (i > 0 && !_is_whitespace(data->result[i - 1]))
			--i;
		ft_printf("\033[%dD", data->cursor_pos - i);
	}
	else if (i < data->line_length && action == 'C')
	{
		while (i < data->line_length && !_is_whitespace(data->result[i]))
			++i;
		while (i < data->line_length && _is_whitespace(data->result[i]))
			++i;
		ft_printf("\033[%dC", i - data->cursor_pos);
	}
	data->cursor_pos = i;
	return (1);
}

/**
 * @brief	Handle simple cursor movements. (Left, Right, Home, End)
 * 
 * @param	data The read line data structure containing the result\
 * 				 and prompt.
 * @param	cmd The command string containing the cursor movement\
 * 				 information.
 * 
 * @return	1 on movement, 0 on nothing.
*/
static inline int	_simple(
	t_rl_data *const restrict data,
	const char *const restrict cmd
)
{
	if (data->cursor_pos > 0 && cmd[2] == 'D')
	{
		--(data->cursor_pos);
		write(STDOUT_FILENO, "\b", 1);
		return (1);
	}
	else if (data->cursor_pos < data->line_length && cmd[2] == 'C')
	{
		++(data->cursor_pos);
		write(STDOUT_FILENO, "\033[C", 3);
		return (1);
	}
	else if (data->cursor_pos > 0 && cmd[2] == 'H')
	{
		ft_printf("\r\033[%dC", data->prompt_length);
		data->cursor_pos = 0;
		return (1);
	}
	else if (cmd[2] == 'F' && data->line_length - data->cursor_pos > 0)
	{
		ft_printf("\033[%dC", data->line_length - data->cursor_pos);
		data->cursor_pos = data->line_length;
		return (1);
	}
	return (0);
}

/**
 * @brief	Move the cursor left or right based on the action.
 * 
 * @param	data The read line data structure containing the result\
 * 				 and prompt.
 * @param	action The action to perform ('D' for left, 'C' for right).
 * 
 * @return	Void
*/
__attribute__((always_inline, used)) inline int	_move(
	t_rl_data *const restrict data,
	const char *const restrict cmd
)
{
	if (_simple(data, cmd))
		return (1);
	else if (ft_strncmp(cmd, "\033[1;5D", 7) == 0
		|| ft_strncmp(cmd, "\033[1;5C", 7) == 0)
		return (_skip(data, cmd[5]));
	else
		return (0);
}

#pragma endregion Fonctions