/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _manager.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/12 15:01:40 by nduvoid          ###   ########.fr       */
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
 * @brief	Add a character to the line at the cursor position.
 * 
 * @param	c The character to add.
 * @param	data The data structure containing the line and cursor position.
 * 
 * @return	1 on success, 0 on failure.
 * 
 * @note	Yes it doesn't increases the line length by 1.
 * @note	YEs it change the cursor position.
 */
__attribute__((used)) static inline int	_rl_add_char(
	const char c,
	t_rl_data *const restrict data
)
{
	register int	i;

	if ((data->line_length + 1) % _RL_ALLOC_SIZE == 0)
	{
		data->result = mm_realloc(data->result,
				data->line_length + _RL_ALLOC_SIZE + 1, data->line_length);
		if (_UNLIKELY(!data->result))
			return (data->status = error, 0);
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
 * @brief	Add a character or a string to the line at the cursor position.
 * 
 * @param	data The data structure containing the line and cursor position.
 * @param	c The character or string to add.
 * @param	mode The mode of addition (rl_chr for character, rl_str for string).
 * 
 * @return	1 on success, 0 on failure.
 * @retval 		1 if the addition was successful.
 * @retval 		0 if the addition failed (e.g., memory allocation error).
*/
__attribute__((used, visibility("hidden")))
int	_rl_add(
	t_rl_data *const restrict data,
	const char *const restrict c,
	int mode
)
{
	register int	i;
	register int	len;
	int				ret;

	if (mode == rl_chr)
	{
		ret = _rl_add_char(*c, data);
		data->line_length += ret;
		return (ret);
	}
	else
	{
		len = ft_strlen(c);
		i = -1;
		ret = 1;
		while (++i < len && ret)
		{
			ret = _rl_add_char(c[i], data);
			data->line_length += ret;
		}
		return (i * ret);
	}
}

#pragma endregion Fonctions