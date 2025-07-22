/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:06:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/22 15:22:32 by nduvoid          ###   ########.fr       */
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
		.prompt_length = ft_strlen(prompt),
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

/**
 * @brief	Adds a line to the history.
 * 
 *  @param	line The line to add to the history.
 * 
 *  @return	Returns the line that was added to the history.
 *  @retval		NULL if an error occurs or if the line is empty.
 *  @retval		Otherwise, the line that was added to the history.
 * 
 *  @version 1.0
*/
__attribute__((used)) char	*rl_add_history(
	const char *const restrict line
)
{
	return (_history_manager(rl_add, line));
}

/**
 *  @brief	Frees the history.
 * 
 * @param	void
 * 
 *  @return	Returns nothing.
 * 
 * @version 1.0
*/
__attribute__((used, cold)) void	rl_clear_history(void)
{
	_history_manager(rl_clear, NULL);
	return ;
}

/**
 * @brief	Loads the history from a file.
 * 
 * @param	filename The name of the file to load the history from.
 * 
 * @return	The success status of the operation.
 * @retval		0 if the history is loaded successfully.
 * @retval		1 if the history somehow failed to load.
 * 
 * @version 1.0
*/
__attribute__((used, cold)) int	rl_load_history(
	const char *const restrict filename
)
{
	return (_history_manager(rl_load, filename) == NULL);
}

__attribute__((used, cold)) t_history	*rl_get_history(void)
{
	return ((t_history *)_history_manager(rl_get_all, NULL));
}

/** */
__attribute__((used, cold)) void	rl_reset_cmd(void)
{
	struct termios	t;

	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &t);
	_set_default(&t);
	return ;
}

#pragma endregion Fonctions