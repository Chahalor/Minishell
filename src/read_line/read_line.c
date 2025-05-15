/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:06:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/15 17:21:31 by nduvoid          ###   ########.fr       */
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
	write(STDOUT_FILENO, "\033[?2004l\n", 9);
	// printf("line_length: %d\n", rl_data.line_length);	//rm
	if (rl_data.status == eof || rl_data.status == interr)
		return (mm_free(rl_data.result), mm_free(rl_data.print), NULL);
	else
		return (mm_free(rl_data.print), rl_data.result);	// maybe strupdup it to have the shortest string possible
}

/** */
__attribute__((used)) char	*rl_add_history(
	const char *const restrict line
)
{
	return (_history_manager(rl_add, line));
}

/** */
__attribute__((used)) void	rl_clear_history(void)
{
	_history_manager(rl_clear, NULL);
	return ;
}

/** */
__attribute__((cold, unused)) int	rl_load_history(
	const char *const restrict filename
)
{
	return (_history_manager(rl_init, filename) == NULL);
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