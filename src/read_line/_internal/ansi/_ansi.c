/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ansi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:19:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/14 11:08:47 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "../_read_line.h"
#include "formating.h"
#include "ft_printf.h"
#include "exit.h"

/* -----| Modules  |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((always_inline, used)) static inline void	_move(
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
}

/** */
__attribute__((always_inline, used)) static inline void	_del(
	t_rl_data *const restrict data,
	const char action
)
{
	if (action == '3')
	{
		if (data->cursor_pos < data->line_length)
		{
			_remove(data);
			refresh_line(data);
		}
	}
}

/** */
__attribute__((always_inline, used)) static inline int	read_ansi_sequence(
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
			break;
	}
	buffer[++i] = '\0';
	return (i);
}

/** */
__attribute__((used)) int	handle_ansi(
	t_rl_data *const restrict data
)
{
	char	ansi[_RL_ANSI_BUFF + 1];
	int		len;

	len = read_ansi_sequence(ansi, sizeof(ansi));
	if (__builtin_expect(!len || len < 0, unexpected))
		return (0);
	if (ft_strncmp(ansi, "\033[D", 3) == 0 || ft_strncmp(ansi, "\033[C", 3) == 0)
		_move(data, ansi[2]);
	else if (ft_strncmp(ansi, "\033[3~", 4) == 0)
		_del(data, ansi[2]);
	else if (ft_strncmp(ansi, "\033[200~", 6) == 0)
		data->status = past;
	else if (ft_strncmp(ansi, "\033[201~", 6) == 0)
		data->status = normal;
	return (1);
}
