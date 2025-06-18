/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 10:16:36 by nduvoid          ###   ########.fr       */
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
	register int	i;

	if (data->line_length == 0)
		return (0);
	else if (data->cursor_pos == data->line_length)
	{
		(data->result)[data->line_length - 1] = '\0';
		return (data->line_length - 1);
	}
	else
	{
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

/**
 * @brief	Refresh the line by writing all char after the cursor position.
 * 
 * @param	data The data structure containing the line and cursor position.
 * 
 * @return	1 on success, -1 on failure.
*/
__attribute__((used)) int	refresh_line(
	t_rl_data *const restrict data
)
{
	const int						move = data->line_length - data->cursor_pos;
	const char *const	restrict	to_write = data->result + data->cursor_pos
		- 1;

	ft_printf("%s", to_write);
	if (move > 0)
		ft_printf("\033[K\033[%dD", move);
	return (1);
}

/**
 * @brief	Handle special characters (ANSI, Ctrl+D, Ctrl+C, etc.).
 * 
 * @param	data The data structure containing the line and cursor position.
 * @param	c The character to handle.
 * 
 * @return	1 on success, -1 on failure.
 * 
 * @version 2.0
*/
__attribute__((used)) static int	handle_special(
	t_rl_data *const restrict data,
	const char c
)
{
	if (c == '\033')
		return (handle_ansi(data));
	else if ((c == 127 || c == 8))
	{
		if (!data->cursor_pos)
			return (0);
		--data->cursor_pos;
		_remove(data);
		return (write(STDOUT_FILENO, "\033[D\033[P", 6));
	}
	else if (c == 4)
	{
		if (data->line_length == 0)
			return (data->result[data->line_length] = '\0',
				data->status = eof, 0);
	}
	else if (c == 3)
		return (data->status = interr);
	else if (c == '\t')
		return (completion(data));
	else if (c == 28)
		return (write(STDOUT_FILENO, &c, 1));
	else
		return (_rl_add(data, &c, rl_chr), refresh_line(data));
	return (1);
}

/**
 * @brief	Read a line from the standard input and refresh the displayed line.
 * 
 * @param	data The data structure containing the line and cursor position.
 * 
 * @return	The length of the line read.
 * 
 * @note	The function will block until a newline is received or an error
 * 				occurs.
 * 
 * @version 2.0
*/
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
			data->status = interr;
		else if (!bytes_read)
			data->status = eof;
		else if (data->status != past && (c == '\r' || c == '\n'))
			break ;
		else if (c < 32 || c > 126)
			handle_special(data, c);
		else
		{
			_rl_add(data, &c, rl_chr);
			refresh_line(data);
		}
	}
	return (data->line_length);
}

#pragma endregion Fonctions