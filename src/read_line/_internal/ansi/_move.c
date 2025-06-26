/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _move.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:19:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/26 16:32:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

static inline int	_is_whitespace(const char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

static inline int	_skip(
	t_rl_data *const restrict data,
	const char action
)
{
	register int	i = data->cursor_pos;

	// ft_fprintf(STDERR_FILENO, "i=%d, action=%c\n", i, action);
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


static inline void	_simple(
	t_rl_data *const restrict data,
	const char action
)
{
	if (action == 'D')
	{
		if (data->cursor_pos > 0)
		{
			--(data->cursor_pos);
			write(STDOUT_FILENO, "\b", 1);
		}
	}
	else if (action == 'C')
	{
		if (data->cursor_pos < data->line_length)
		{
			++(data->cursor_pos);
			write(STDOUT_FILENO, "\033[C", 3);
		}
	}
	else if (data->cursor_pos > 0 && action == 'H')
	{
		ft_printf("\r\033[%dC", data->prompt_length);
		data->cursor_pos = 0;
	}
	else if (action == 'F') // END
	{
		int move = data->line_length - data->cursor_pos;
		if (move > 0)
			ft_printf("\033[%dC", move);
		data->cursor_pos = data->line_length;
	}

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
	if (cmd[2] == 'D' || cmd[2] == 'C' || cmd[2] == 'H' || cmd[2] == 'F')
	{
		_simple(data, cmd[2]);
		return (1);
	}
	else if (ft_strncmp(cmd, "\033[1;5D", 7) == 0 || ft_strncmp(cmd, "\033[1;5C", 7) == 0)
	{
		_skip(data, cmd[5]);
		return (1);
	}
	else
		return (0);
}

#pragma endregion Fonctions