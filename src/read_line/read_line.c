/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:06:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/11 20:05:47 by nduvoid          ###   ########.fr       */
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

/**
 * @todo:	handle ctrl+c to exit the read_line and not just the program
 * @todo:	update correcty the buffer when using the arrow keys
 * @todo:	handle the backspace key
 */

static inline void _insert(
	const char c
)
{
	// entrer en mode insertion
	write(STDOUT_FILENO, "\033[4h", 4);
	// écrire ton caractère
	write(STDOUT_FILENO, &c, 1);
	// quitter le mode insertion
	write(STDOUT_FILENO, "\033[4l", 4);
}
 
/** */
__attribute__((always_inline, used)) inline void	_handle_ansi(
	char *buffer,
	int *i
)
{
	char	tmp[4];

	(void)buffer;
	(void)i;
	if (read(STDIN_FILENO, &tmp, 2) == -1)	// should get something like "[1A" or "[1B"
		return ;
	if (tmp[0] == '[')
	{
		if (tmp[1] == 'A')
			write(STDOUT_FILENO, "\033[1A", 5);
		else if (tmp[1] == 'B')
			write(STDOUT_FILENO, "\033[1B", 5);
		else if (tmp[1] == 'C')
			write(STDOUT_FILENO, "\033[1C", 5);
		else if (tmp[1] == 'D')
			write(STDOUT_FILENO, "\033[1D", 5);
		else
			write(STDOUT_FILENO, "\033[1~", 5);
			
	}
}

/** */
__attribute__(()) static int	_reader(
	char *buffer
)
{
	int	i;

	i = -1;
	while (++i < RL_MAX_BUFFER)
	{
		if (read(STDIN_FILENO, &buffer[i], 1) == -1)
			return (-1);
		else if (buffer[i] == '\n' || buffer[i] == '\r')
		{
			buffer[i] = '\0';
			write(STDOUT_FILENO, "\n", 1);
			break ;
		}
		else if (buffer[i] == '\033')
			_handle_ansi(buffer, &i);
		else
			_insert(buffer[i]);
	}
	return (i);
}

/** */
char	*read_line(
	const char *restrict prompt
)
{
	struct termios	oldt;
	struct termios	resore;
	struct termios	raw;
	char			buffer[RL_MAX_BUFFER + 1];
	int				line_length;

	write(STDOUT_FILENO, prompt, 8);
	tcgetattr(STDIN_FILENO, &oldt);
	raw = oldt;
	resore = oldt;
	_set_raw(&raw);
	line_length = _reader(buffer);
	_set_default(&resore);
	return (memdup(buffer, line_length + 1));
}


/** */
void	reset_cmd(void)
{

	struct termios	oldt;
	struct termios	resore;

	tcgetattr(STDIN_FILENO, &oldt);
	resore = oldt;
	_set_default(&resore);
}


#pragma endregion Fonctions