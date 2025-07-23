/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:06:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/23 18:03:30 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
#include "interraction__.h"

/* -----| Modules  |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

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
__attribute__((used, always_inline))
inline char	*_rl_read_line__(
	const char *const restrict prompt
)
{
	t_rl_data	rl_data;

	rl_data = (t_rl_data){
		.result = mm_alloc(_RL_ALLOC_SIZE + 1),
		.line_length = 0,
		.cursor_pos = 0,
		.prompt = (char *)prompt,
		.prompt_length = ft_strlen(prompt),
		.status = normal,
	};
	if (_UNLIKELY(!rl_data.result))
		return (NULL);
	_init_cmd(&rl_data);
	rl_data.line_length = _rl_read__(&rl_data);
	_rl_set_default__(&rl_data.terms.resore);
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
__attribute__((used, always_inline))
inline void	_rl_reset_cmd__(void)
{
	struct termios	t;

	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &t);
	_rl_set_default__(&t);
	return ;
}

/** */
__attribute__((always_inline, used))
inline void	_init_cmd(
	t_rl_data *const restrict data
)
{
	tcgetattr(STDIN_FILENO, &data->terms.oldt);
	data->terms.raw = data->terms.oldt;
	data->terms.resore = data->terms.oldt;
	_rl_set_raw__(&data->terms.raw);
	write(STDOUT_FILENO, "\033[?2004h", 8);
	write(STDOUT_FILENO, data->prompt, data->prompt_length);
}

#pragma endregion Fonctions