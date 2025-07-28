/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/24 10:02:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "../_internal_/builtin__.h"

/* -----| Modules   |----- */
#include "exec.h"	// for the t_exec_dat struct

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Get the builtin command link based on the command name.
 * 
 * @param	args The command name to search for.
 * 
 * @return	A pointer to the builtin
 *  @retval		NULL if no matching builtin is found.
 *  @retval		A pointer to the t_blt_link structure containing the
 * 				builtin command name and function pointer.
 */
t_blt_link	*get_builtins(
	const char *const restrict args
)
{
	return (get_builtins__(args));
}

char	exec_builtin_fork(
	t_exec_data *args,
	char *const envp[],
	const int fd_in,
	const int fd_out
)
{
	return (exec_builtin_fork__(args, envp, fd_in, fd_out));
}

/**
 * @brief Execute the builtin command
 * 
 * @param args The command to execute
 * 
 * @return The exit code of the command
 * @retval 	-1 if the command is not a builtin
 * 
 * @version 1.0
*/
char	exec_builtin(
	t_exec_data *args,
	char *const envp[],
	const int fd_in,
	const int fd_out
)
{
	return (exec_builtin__(args, envp, fd_in, fd_out));
}

#pragma endregion Fonctions