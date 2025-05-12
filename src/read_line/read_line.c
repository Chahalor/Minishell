/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:06:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/12 15:11:53 by nduvoid          ###   ########.fr       */
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
 * @todo: 	handle the delete key /!\
 * @todo: 	make differnce between ENTER and just a '\n' (maybe read more than 1 char)
 */

/** */
__attribute__((hot, malloc)) char	*read_line(
	const char *restrict prompt
)
{
	struct termios	oldt;
	struct termios	resore;
	struct termios	raw;
	int				line_length;
	char			*result;

	result = mm_alloc(_RL_ALLOC_SIZE + 1);
	if (!result)
		return (NULL);
	write(STDOUT_FILENO, prompt, ft_strlen(prompt));
	tcgetattr(STDIN_FILENO, &oldt);
	raw = oldt;
	resore = oldt;
	_set_raw(&raw);
	line_length = _read(result);
	_set_default(&resore);
	write(STDOUT_FILENO, "\n", 1);
	printf("line_length: %d\n", line_length);	//rm
	return (result);
}


/** */
__attribute__((hot)) void	reset_cmd(void)
{

	struct termios	oldt;
	struct termios	resore;

	tcgetattr(STDIN_FILENO, &oldt);
	resore = oldt;
	_set_default(&resore);
}


#pragma endregion Fonctions