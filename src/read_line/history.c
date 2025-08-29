/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:04:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/29 11:04:30 by nduvoid          ###   ########.fr       */
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

#pragma endregion Fonctions