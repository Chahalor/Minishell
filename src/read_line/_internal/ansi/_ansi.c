/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ansi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:19:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/26 16:45:31 by nduvoid          ###   ########.fr       */
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
 * @brief	Read an ANSI escape sequence from the input.
 * 
 * @param	buffer The buffer to store the ANSI sequence.
 * @param	buffer_size The size of the buffer.
 * 
 * @return	The number of bytes read
 *  @retval		>= 0 if the ANSI sequence is read successfully.
 *  @retval		0 if no ANSI sequence is read.
 *  @retval		-1 if an error occurs or if the buffer is too small.
*/
__attribute__((always_inline, used)) static inline int	_read_ansi(
	char *const restrict buffer,
	register int buffer_size
)
{
	int				bytes_read;
	register int	i;
	char			ch;

	if (!buffer || buffer_size < 2)
		return (-1);
	i = -1;
	buffer[++i] = '\033';
	bytes_read = read(STDIN_FILENO, &ch, 1);
	if (__builtin_expect(bytes_read <= 0 || ch != '[', unexpected))
		return (-1);
	buffer[++i] = ch;
	while (i < buffer_size - 1)
	{
		bytes_read = read(STDIN_FILENO, &ch, 1);
		if (__builtin_expect(bytes_read <= 0, unexpected))
			return (-1);
		buffer[++i] = ch;
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '~')
			break ;
	}
	buffer[++i] = '\0';
	return (i);
}

/**
 * @brief	Remove the char after the cursor position.
 * 
 * @param	data The read line data structure containing the result\
 * 				 and prompt.
 * @param	action The action to perform ('3' for delete).
 * 
 * @return	Void
*/
__attribute__((always_inline, used)) static inline void	_del(
	t_rl_data *const restrict data
)
{
	int				len;
	unsigned char	c;
	int				i;
	int				j;

	if (data->cursor_pos >= data->line_length)
		return ;
	len = 1;
	c = (unsigned char)data->result[data->cursor_pos];
	len = 1 + (c >= 0xC0) + (c >= 0xE0) + (c >= 0xF0);
	if (data->cursor_pos + len > data->line_length)
		len = data->line_length - data->cursor_pos;
	i = data->cursor_pos;
	j = data->cursor_pos + len;
	while (j <= data->line_length)
		data->result[i++] = data->result[j++];
	data->line_length -= len;
	refresh_line(data);
}

/** */
__attribute__((always_inline, used)) static inline int	_history_entry(
	t_rl_data *const restrict data,
	char *line
)
{
	char	*tmp;
	int		len;

	if (line)
	{
		len = ft_strlen(line);
		tmp = mm_realloc(data->result, len + 1);
		if (_UNLIKELY(!tmp))
			return (1);
		data->result = tmp;
		ft_memcpy(data->result, line, len);
		data->result[len] = '\0';
		data->line_length = len;
		data->cursor_pos = len;
		refresh_line(data);
		return (1);
	}
	if (data->result && data->line_length > 0)
		_neutral(data->result, data->line_length);
	data->result[0] = '\0';
	data->line_length = 0;
	data->cursor_pos = 0;
	refresh_line(data);
	return (1);
}

/**
 * @brief	Handle history navigation for the read line.
 * 
 * @param	data The read line data structure containing the result\
 * 				 and prompt.
 * @param	action The action to perform ('A' for previous, 'B' for next).
 * 
 * @return	Return 1
 */
__attribute__((always_inline, used)) static inline int	_history(
	t_rl_data *const restrict data,
	const char action
)
{
	char	*line;

	if (action == 'A')
		line = _history_manager(rl_get_prev, NULL);
	else if (action == 'B')
		line = _history_manager(rl_get_next, NULL);
	else
		line = NULL;
	return (_history_entry(data, line));
}

/**
 * @brief	Handle ANSI escape sequences for cursor movement and
 * 			history navigation.
 * 
 * @param	data	The read line data structure containing the result
 * 						and prompt.
 * @return	Returns 1 if the ANSI sequence was handled successfully, 0 otherwise.
 * @retval		1	ANSI sequence handled successfully.
 * @retval		0	No ANSI sequence or an error occurred.
*/
__attribute__((used)) int	handle_ansi(
	t_rl_data *const restrict data
)
{
	char	ansi[_RL_ANSI_BUFF + 1];
	int		len;

	len = _read_ansi(ansi, sizeof(ansi));
	if (__builtin_expect(!len || len < 0, unexpected))
		return (0);
	if (_move(data, ansi) > 0)
		return (1);
	else if (ft_strncmp(ansi, "\033[A", 3) == 0
		|| ft_strncmp(ansi, "\033[B", 3) == 0)
		_history(data, ansi[2]);
	else if (ft_strncmp(ansi, "\033[3~", 4) == 0)
		_del(data);
	else if (ft_strncmp(ansi, "\033[200~", 6) == 0)
		data->status = past;
	else if (ft_strncmp(ansi, "\033[201~", 6) == 0)
		data->status = normal;
	return (1);
}
