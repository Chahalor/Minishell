/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/24 08:47:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "./types.h"
#include "../_internal_/exec__.h"

/* -----| Modules   |----- */
#include "standards.h"

#pragma endregion Header
#pragma region Fonctions

int	heredoc(
	const char *const restrict delimiter
)
{
	if (unexpect(!delimiter))
		return (-1);
	else
		return (_heredoc__(delimiter));
}

/**
 * @brief	Executes all commands in the order of data.
 * 				If a command has a pipe, it will create the pipe and
 * 				redirect the output of the previous command to the input of the
 * 				next command. It will execut all pipe one by one.
 * @param	data	Execution data structure containing the commands and their
 * 				arguments.
 * @param	envp	Environment variables to pass to the commands.
 * 
 * @return	Returns the status of the command execution.
 * @retval		~0 if the command executed successfully.
 * @retval		-1 if the pipe() failed.
 * 
 * @version	1.1
 */
int	full_exec(
	t_exec_data *const restrict data,
	char *const envp[]
)
{
	if (unexpect(!data))
		return (-1);
	else
		return (_full_exec__(data, envp));
}
#pragma endregion Fonctions