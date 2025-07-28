/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:19:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/24 08:33:53 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "../interraction__.h"

/* -----| Modules   |----- */
#include "standards.h"

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
__attribute__((always_inline, used))
static inline int	_read_ansi__(
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
	if (unexpect(bytes_read <= 0))
		return (-1);
	buffer[++i] = ch;
	while (i < buffer_size - 1)
	{
		bytes_read = read(STDIN_FILENO, &ch, 1);
		if (unexpect(bytes_read <= 0))
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
__attribute__((always_inline, used))
static inline void	_ansi_del__(
	t_rl_data *const restrict data
)
{
	if (data->cursor_pos < data->line_length)
	{
		_rl_remove__(data);
		write(STDOUT_FILENO, "\033[P", 3);
	}
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
__attribute__((always_inline, used))
static inline int	_ansi_history__(
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
	if (line)
	{
		data->result = line;
		data->line_length = ft_strlen(line);
		data->cursor_pos = data->line_length;
		ft_printf("\r\033[%dC\033[K%s", data->prompt_length, data->result);
	}
	else
	{
		ft_printf("\r\033[%dC\033[K", data->prompt_length);
		_neutral(data->result, data->line_length);
		data->line_length = 0;
		data->cursor_pos = 0;
	}
	return (1);
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
__attribute__((always_inline, used))
inline int	_rl_handle_ansi__(
	t_rl_data *const restrict data
)
{
	char	ansi[_RL_ANSI_BUFF + 1];
	int		len;

	len = _read_ansi__(ansi, sizeof(ansi));
	if (unexpect(len < 1))
		return (0);
	if (_rl_move__(data, ansi) > 0)
		return (1);
	else if (ft_strncmp(ansi, "\033[A", 3) == 0
		|| ft_strncmp(ansi, "\033[B", 3) == 0)
		_ansi_history__(data, ansi[2]);
	else if (ft_strncmp(ansi, "\033[3~", 4) == 0)
		_ansi_del__(data);
	else if (ft_strncmp(ansi, "\033[200~", 6) == 0)
		data->status = past;
	else if (ft_strncmp(ansi, "\033[201~", 6) == 0)
		data->status = normal;
	return (1);
}
