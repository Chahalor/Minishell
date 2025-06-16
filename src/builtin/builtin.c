/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/16 08:29:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_builtin.h"

/* -----| Modules   |----- */
#include "builtin.h"

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
	static t_blt_link	builtins[] = {
	{"cd", bltin_cd},
	{"exit", bltin_exit},
	{"env", bltin_env},
	{"pwd", bltin_pwd},
	{"echo", bltin_echo},
	{"export", bltin_export},
	{"unset", bltin_unset},
	{NULL, NULL}};
	register int		i;

	i = -1;
	while (builtins[++i].name)
		if (ft_strncmp(builtins[i].name, args, ft_strlen(args)) == 0)
			return (&builtins[i]);
	return (NULL);
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
	const t_blt_link	*builtins = get_builtins(args->args[0]);

	(void)envp;
	if (_UNLIKELY(!args || !args->cmd || !builtins))
		return (-1);
	args->pid = 0;
	return (builtins->func((const char **)args->args, fd_in, fd_out));
}

#pragma endregion Fonctions