/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:06:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/03 10:38:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
#include "_read_line.h"
#include "formating.h"

/* -----| Modules  |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region    Prototypes

extern int	_prompt_length(
				const char *const restrict prompt
				);

#pragma endregion Prototypes
#pragma region    Fonctions

/**
 * @brief Reads a line from standard input with a prompt.
 * 
 * @param	prompt The prompt to display before reading the line.
 * 
 * @return	Returns the read line as a dynamically allocated string.
 * @retval		NULL if an error occurs or if the end of file is reached.
 * @retval		"\04" if the end of file is reached (Ctrl+D).
 * @retval		Otherwise, the read line.
 * 
 * @version 2.0
 */
__attribute__((used, hot, malloc)) char	*read_line(
	const char *const restrict prompt
)
{
	t_rl_data	rl_data;

	rl_data = (t_rl_data){
		.result = mm_alloc(_RL_ALLOC_SIZE + 1),
		.line_length = 0,
		.cursor_pos = 0,
		.prompt = (char *)prompt,
		.prompt_length = _prompt_length(prompt),
		.status = normal,
	};
	if (_UNLIKELY(!rl_data.result))
		return (NULL);
	_init_cmd(&rl_data);
	rl_data.line_length = _read(&rl_data);
	_set_default(&rl_data.terms.resore);
	write(STDOUT_FILENO, "\033[?2004l\n", 9);
	_history_manager(rl_reset_pos, NULL);
	if (rl_data.status == eof)
		return (mm_free(rl_data.result), memdup("\04", 1));
	if (rl_data.status < exiting || !rl_data.line_length)
		return (mm_free(rl_data.result), NULL);
	else
		return (rl_data.result);
}

/** */
__attribute__((used, cold)) void	rl_reset_cmd(void)
{
	struct termios	t;

	t = (struct termios){0};
	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &t);
	_set_default(&t);
	return ;
}

#pragma endregion Fonctions