/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ansi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:19:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 10:42:29 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Internals |----- */
#include "_read_line.h"

/* -----| Modules   |----- */
#include "read_line.h"

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
	int				len;
	char			c;
	register int	i;

	if (!buffer || buffer_size < 2)
		return (-1);
	buffer[0] = '\033';
	len = read(STDIN_FILENO, &c, 1);
	if (__builtin_expect(len <= 0 || c != '[', unexpected))
		return (-1);
	buffer[1] = c;
	i = 2;
	while (i < buffer_size - 1)
	{
		len = read(STDIN_FILENO, &c, 1);
		if (__builtin_expect(len <= 0, unexpected))
			return (-1);
		buffer[i++] = c;
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '~')
			break ;
	}
	buffer[i++] = '\0';
	return (i);
}

/** */
__attribute__((always_inline, used)) static inline int	_history_entry(
	t_rl_data *const restrict data,
	char *line
)
{
	char	*tmp;
	int		full_len;
	int		len;

	if (line)
	{
		len = ft_strlen(line);
		full_len = _RL_ALLOC_SIZE + (len * (len > _RL_ALLOC_SIZE));
		tmp = mm_alloc(full_len);
		if (_UNLIKELY(!tmp))
			return (refresh_line(data));
		data->result = tmp;
		ft_memcpy(data->result, line, len);
		data->result[len] = '\0';
		data->line_length = len;
		data->cursor_pos = len;
		return (refresh_line(data));
	}
	if (data->result && data->line_length > 0)
		_neutral(data->result, data->line_length);
	data->result[0] = '\0';
	data->line_length = 0;
	data->cursor_pos = 0;
	return (refresh_line(data));
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
		back_move(data);
	else if (ft_strncmp(ansi, "\033[200~", 6) == 0)
		data->status = past;
	else if (ft_strncmp(ansi, "\033[201~", 6) == 0)
		data->status = normal;
	return (1);
}
