/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:06:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/13 17:55:31 by nduvoid          ###   ########.fr       */
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
 * @todo:	X update correcty the buffer when using the arrow keys
 * @todo:	X handle the backspace key
 * @todo: 	X handle the delete key /!\
 * @todo: 	make differnce between ENTER and just a '\n' (maybe read more than 1 char)
 */

 /** */
 __attribute__((always_inline, used)) static inline void	_init_cmd(
	t_rl_data *const restrict data
 )
 {
	tcgetattr(STDIN_FILENO, &data->terms.oldt);
	data->terms.raw = data->terms.oldt;
	data->terms.resore = data->terms.oldt;
	_set_raw(&data->terms.raw);
	write(STDOUT_FILENO, data->prompt, data->prompt_length);
}

/** */
__attribute__((hot, malloc)) char	*read_line(
	const char *const restrict prompt
)
{
	t_rl_data	rl_data;

	rl_data = (t_rl_data){
		.result = mm_alloc(_RL_ALLOC_SIZE + 1),
		.print = mm_alloc(_RL_ALLOC_SIZE + 1),
		.print_length = 0,
		.line_length = 0,
		.cursor_pos = 0,
		.prompt = (char *)prompt,
		.prompt_length = ft_strlen(prompt),
		.status = normal,
	};
	if (__builtin_expect(!rl_data.result || !rl_data.print, unexpected))
		return (NULL);
	_init_cmd(&rl_data);
	rl_data.line_length = _read(&rl_data);
	_set_default(&rl_data.terms.resore);
	if (rl_data.status == eof || rl_data.status == interr)
		return (mm_free(rl_data.result), mm_free(rl_data.print), NULL);
	write(STDOUT_FILENO, "\033[?2004l\n", 10);
	printf("line_length: %d\n", rl_data.line_length);	//rm
	return (mm_free(rl_data.print), rl_data.result);	// maybe strupdup it to have the shortest string possible
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