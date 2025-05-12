/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/12 12:19:49 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline void _insert(
	const char c
)
{
	write(STDOUT_FILENO, "\033[4h", 4);	// entrer en mode insertion
	write(STDOUT_FILENO, &c, 1);		// écrire ton caractère
	write(STDOUT_FILENO, "\033[4l", 4);	// quitter le mode insertion
}
 
/** */
__attribute__((always_inline, used)) static inline int	_handle_ansi(
	char *buffer,
	int *length,
	int *pos
)
{
	char	tmp[4];

	(void)buffer;
	(void)length;
	if (read(STDIN_FILENO, &tmp, 2) == -1)
		return (-1);
	// printf("tmp: <%s> (%c)\n", tmp, tmp[1]);	//rm
	if (tmp[0] == '[')
	{
		if (tmp[1] == 'C')
		{
			write(STDOUT_FILENO, "\033[1C", 5);
			*pos -= 1;
		}
		else if (tmp[1] == 'D')
		{
			*pos += 1;
			write(STDOUT_FILENO, "\033[1D", 5);
		}
		else
			write(STDOUT_FILENO, "\033[1~", 5);
			
	}
	return (0);
}

/** */
__attribute__((always_inline, used)) static inline int	_add_to_result(
	char *result,
	int *length,
	int *pos,
	const char c
)
{
	register int	i;

	if (*length >= RL_MAX_BUFFER)
	{
		result = mm_realloc(result, *length, *length + RL_MAX_BUFFER);
		if (__builtin_expect(!result, unexpected))
			return (-1);
	}
	else if (*length == *pos)
		result[(*pos)++] = c;
	else
	{
		i = *pos;
		while (i < *length)
		{
			result[i] = result[i - 1];
			++i;
		}
		result[*pos] = c;
	}
	(*length)++;
	(*pos)++;
	return (0);
}

/** */
__attribute__((hot)) int	_read(
	char *restrict result
)
{
	int		pos;
	int		length;
	char	c;

	pos = 0;
	length = -1;
	while (1)
	{
		if (read(STDIN_FILENO, &c, 1) == -1)
			return (-1);
		if (c == '\n' || c == '\r')
		{
			result[++length] = '\0';
			_insert(c);
			break ;
		}
		else if (c == '\033')
			_handle_ansi(result, &length, &pos);
		else if (c == 127)
		{
			if (length > 0)
			{
				write(STDOUT_FILENO, "\033[1D", 5);
				write(STDOUT_FILENO, "\033[1P", 5);
				--length;
				--pos;
			}
		}
		else
		{
			_add_to_result(result, &length, &pos, c);
			_insert(c);
		}
	}
	return (length);
}

#pragma endregion Fonctions