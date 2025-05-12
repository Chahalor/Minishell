/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/12 17:19:30 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
#include "_read_line.h"
#include "formating.h"

/* -----| Modules  |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((always_inline, used)) static inline void	_write(
	const char c,
	const int line_length,
	const int cursor_pos
)
{
	if (cursor_pos == line_length)
		write(STDOUT_FILENO, &c, 1);
	else
	{
		write(STDOUT_FILENO, "\033[4h", 5);
		write(STDOUT_FILENO, &c, 1);
		write(STDOUT_FILENO, "\033[4l", 5);
	}
}

/** */
__attribute__((used)) static int	handle_ansi(
	char *restrict result,
	int *cursor_pos,
	const int line_length
)
{
	char	seq[10];

	(void)result;
	if (__builtin_expect(read(STDIN_FILENO, seq, 9) == -1, unexpected))
		return (-1);
	else if (seq[0] == '[')
	{
		if (seq[1] == 'D' && *cursor_pos > 0)
		{
			write(STDOUT_FILENO, CURSOR_LEFT, 4);
			--(*cursor_pos);
		}
		else if (seq[1] == 'C' && *cursor_pos < line_length)
		{
			write(STDOUT_FILENO, CURSOR_RIGHT, 4);
			++(*cursor_pos);
		}
		else	// @todo: handle up/down, should change in the history
			write(STDOUT_FILENO, "\033[1~", 5);
	}
	else	// @todo: handle other sequences, like ctrl+D (EOF)
		write(STDOUT_FILENO, seq, ft_strlen(seq));	// maybe change this to a cha cha sequence
	return (0);
}

/** */
__attribute__((used)) static int	_add(
	const char c,
	char *restrict *restrict result,
	const int line_length,
	register const int cursor_pos
)
{
	register int	i;

	if (line_length == _RL_ALLOC_SIZE)
	{
		*result = mm_realloc(*result,
			line_length, line_length + _RL_ALLOC_SIZE + 1);
		if (!*result)
			return (-1);
	}
	if (cursor_pos == line_length)
		(*result)[line_length] = c;
	else
	{
		i = line_length;
		while (i-- > cursor_pos)
			(*result)[i + 1] = (*result)[i];
		(*result)[cursor_pos] = c;
	}
	(*result)[line_length + 1] = '\0';
	return (1);
}

/** */
__attribute__((used)) static int _remove(
	char *restrict *restrict result,
	const int line_length,
	const int cursor_pos
)
{
	if (line_length == 0)
		return (0);
	else if (cursor_pos == line_length)
	{
		(*result)[line_length - 1] = '\0';
		return (line_length - 1);
	}
	else
	{
		int	i;

		i = cursor_pos;
		while (i < line_length)
			(*result)[i] = (*result)[i + 1];
		(*result)[line_length - 1] = '\0';
		return (line_length - 1);
	}
}

/** */
__attribute__((hot)) int	_read(
	char *restrict result
)
{
	int		line_length;
	int		cursor_pos;
	int		bytes_read;
	char	c;

	line_length = 0;
	cursor_pos = 0;
	while (1)
	{
		bytes_read = read(STDIN_FILENO, &c, 1);
		if (__builtin_expect(bytes_read == -1, unexpected))
			return (-1);
		else if (c == '\033')
			line_length += handle_ansi(result, &cursor_pos, line_length);
		else if (c == '\n' || c == '\r')
		{
			result[line_length] = '\0';
			break ;
		}
		else if (c == 127 || c == 8)
		{
			line_length = _remove(&result, line_length, cursor_pos);
			write(STDOUT_FILENO, "\033[1D\033[K", 7);
		}
		else
		{
			line_length += _add(c, &result, line_length, cursor_pos++);
			_write(c, line_length, cursor_pos);
		}
	}
	return (line_length);
}

#pragma endregion Fonctions