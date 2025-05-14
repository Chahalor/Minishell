/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/14 14:49:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"
#include "formating.h"
#include "ft_printf.h"
#include "exit.h"

/* -----| Modules  |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((used)) static int	_add(
	const char c,
	t_rl_data *const restrict data
)
{
	register int	i;

	if (data->line_length == _RL_ALLOC_SIZE - 1)
	{
		data->result = mm_realloc(data->result,
			data->line_length, data->line_length + _RL_ALLOC_SIZE + 1);
		if (!data->result)
			return (-1);
	}
	if (data->cursor_pos == data->line_length)
		data->result[data->line_length] = c;
	else
	{
		i = data->line_length;
		while (i-- > data->cursor_pos)
			(data->result)[i + 1] = (data->result)[i];
		data->result[data->cursor_pos] = c;
	}
	data->result[data->line_length + 1] = '\0';
	++(data->cursor_pos);
	return (1);
}

/**
 * @brief	Remove the character at the cursor position.
 * 
 * @param	data The data structure containing the line and cursor position.
 * 
 * @return	The new cursor position after the removal.
 * 
 * @note	Yes it decreases the line length by 1.
 */
__attribute__((used)) int	_remove(
	t_rl_data *const restrict data
)
{
	if (data->line_length == 0)
		return (0);
	else if (data->cursor_pos == data->line_length)
	{
		(data->result)[data->line_length - 1] = '\0';
		return (data->line_length - 1);
	}
	else
	{
		int	i;

		i = data->cursor_pos;
		while (i < data->line_length)
		{
			(data->result)[i] = (data->result)[i + 1];
			++i;
		}
		(data->result)[data->line_length - 1] = '\0';
		--data->line_length;
		return (data->line_length - 1);
	}
	return (0);
}

/** */
__attribute__((used)) int	refresh_line(
	t_rl_data *const restrict data
)
{
	const int					move = data->line_length - data->cursor_pos;
	const char	*const restrict	to_write = data->result + data->cursor_pos - 1;

	ft_printf("%s", to_write);
	if (move > 0)
	{
		ft_printf("\033[K");
		ft_printf("\033[%dD", move);
	}

	// ft_printf("\r\033[?2004h%s%s\033[K", data->prompt, data->result);
	// if (move > 0)
	// 	ft_printf("\033[%dD", move);
	return (1);
}

/** */
__attribute__((used)) static int	handle_backspace(
	t_rl_data *const restrict data
)
{
	if (data->cursor_pos > 0)
	{
		data->cursor_pos--;
		_remove(data);
		refresh_line(data);
	}
	return (1);
}

/** */
__attribute__((used)) static int	handle_ctrl_d(
	t_rl_data *const restrict data
)
{
	data->result[data->line_length] = '\0';
	data->status = eof;
	return (1);
}

/** */
__attribute__((used)) static int	handle_special(
	t_rl_data *const restrict data,
	const char c
)
{
	if (c == '\033')
		handle_ansi(data);
	else if (c == 127 || c == 8)
		handle_backspace(data);
	else if (c == 4 && data->line_length == 0)
		handle_ctrl_d(data);
	else if (c == 3)
	{
		write(STDOUT_FILENO, "^C", 2);
		data->status = interr;
	}
	else
	{
		data->line_length += _add(c, data);
		refresh_line(data);
	}
	return (1);
}

/** */
__attribute__((hot)) int	_read(
	t_rl_data *const restrict data
)
{
	int		bytes_read;
	char	c;

	data->line_length = 0;
	data->cursor_pos = 0;
	while (data->status > exiting)
	{
		bytes_read = read(STDIN_FILENO, &c, 1);
		if (bytes_read < 0)
			data->status = error;
		else if (data->status != past && (c == '\r' || c == '\n'))
			break ;
		else if (c < 32 || c > 126)
			handle_special(data, c);
		else if (c >= 32 && c <= 126)
		{
			data->line_length += _add(c, data);
			refresh_line(data);
		}
	}
	return (data->line_length);
}

#pragma endregion Fonctions