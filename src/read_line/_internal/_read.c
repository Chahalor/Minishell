/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/16 13:33:06 by nduvoid          ###   ########.fr       */
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
		if (data->line_length > 0)
			--data->line_length;
		data->result[data->line_length] = '\0';
		return (data->line_length);
	}
	else
	{
		i = data->cursor_pos;
		while (i < data->line_length)
		{
			data->result[i] = data->result[i + 1];
			++i;
		}
		--data->line_length;
		data->result[data->line_length] = '\0';
		return (data->line_length);
	}
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
	const int	move = data->line_length - data->cursor_pos;

	ft_printf("\r\033[J");
	ft_printf("%s", data->prompt);
	if (data->line_length > 0)
		write(STDOUT_FILENO, data->result, data->line_length);
	if (move > 0)
		ft_printf("\033[%dD", move);
	return (1);
}

/** */
__attribute__((used, always_inline)) static inline int	back_move(
	t_rl_data *const restrict data
)
{
	const int		start = data->cursor_pos;
	int				len;
	unsigned char	c;
	int				i;
	int				j;

	i = start;
	while (i > 0 && ((unsigned char)data->result[i - 1] & 0xC0) == 0x80)
		--i;
	if (i <= 0 || start <= 0)
		return (0);
	c = (unsigned char)data->result[i - 1];
	len = 1 + (c >= 0xC0) + (c >= 0xE0) + (c >= 0xF0);
	i = i * (len <= start);
	if (len > start)
		len = start;
	else
		i = start - len;
	j = i + len;
	while (j <= data->line_length)
		data->result[i++] = data->result[j++];
	data->cursor_pos -= len;
	data->line_length -= len;
	return (refresh_line(data));
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
		return (back_move(data));
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
		else if ((unsigned char)c < 32 || (unsigned char)c > 126)
			handle_special(data, c);
		else
		{
			_rl_add(data, (char [2]){c, '\0'}, rl_chr);
			refresh_line(data);
		}
	}
	return (data->line_length);
}

#pragma endregion Fonctions