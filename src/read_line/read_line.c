/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:06:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 09:30:32 by nduvoid          ###   ########.fr       */
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
__attribute__((visibility("hidden"), used, hot, malloc)) char	*_read_line(
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
__attribute__((visibility("hidden"), used)) char	*_rl_add_history(
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
__attribute__((visibility("hidden"), used, cold)) void	_rl_clear_history(void)
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
__attribute__((visibility("hidden"), used, cold)) int	_rl_load_history(
	const char *const restrict filename
)
{
	return (_history_manager(rl_load, filename) == NULL);
}

__attribute__((cold, unused))	t_read_line	*get_read_lines(void)
{
	static t_read_line	rl = {
		.read_line = _read_line,
		.add_history = _rl_add_history,
		.clear_history = _rl_clear_history,
		.load_history = _rl_load_history,
		.reset_cmd = _rl_reset_cmd,
		.get_all_history = _rl_get_all
	};

	return (&rl);
}

#pragma endregion Fonctions