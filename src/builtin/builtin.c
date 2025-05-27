/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/27 13:09:36 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_builtin.h"

/* -----| Modules   |----- */
#include "builtin.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((used)) char	bltin_exit(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const int exit_code = ft_atoi(args[1]);

	(void)fd_in;
	(void)fd_out;
	free_tab((char **)args);
	exit_program(exit_code, "see you soon ^^");
	return (1);
}

static t_blt_link	*get_builtins(void)
{
	static const t_blt_link	builtins[8] = {
		{"cd", bltin_cd},
		{"echo", bltin_echo},
		{"env", bltin_env},
		{"exit", bltin_exit},
		{"export", bltin_export},
		{"pwd", bltin_pwd},
		{"unset", bltin_unset},
		{NULL, NULL}};
	
	return ((t_blt_link *)builtins);
}

/**
 * @brief Check if the command is a builtin
 * 
 * @param args The command to check
 * 
 * @return 1 if the command is a builtin, 0 otherwise
*/
__attribute__((always_inline, used)) inline char	is_builtin(
	const char *const restrict args
)
{
	const t_blt_link	*builtins = get_builtins();
	register int		i;

	i = 0;
	while (builtins[i].name)
		if (ft_strncmp(args, builtins[i].name, ft_strlen(builtins[i].name)) == 0)
			return (i);
	return (8);
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
	const t_exec_data *args,
	char *const envp[],
	const int fd_in,
	const int fd_out
)
{
	const t_blt_link	*builtins = get_builtins();
	const int			cmd_index = is_builtin(args->cmd);

	(void)envp;
	if (_UNLIKELY(!args || !args->cmd || !builtins || cmd_index < 0))
		return (-1);
	return (builtins[cmd_index].func((const char **)args->args, fd_in, fd_out));
}

#pragma endregion Fonctions