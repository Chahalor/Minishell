/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/26 16:06:34 by nduvoid          ###   ########.fr       */
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
	const char **args
)
{
	const int exit_code = ft_atoi(args[1]);

	free_tab((char **)args);
	exit_program(exit_code, "see you soon ^^");
	return (1);
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
	return (
		ft_strncmp(args, "cd", 2) == 0
		|| ft_strncmp(args, "echo", 4) == 0
		|| ft_strncmp(args, "env", 3) == 0
		|| ft_strncmp(args, "exit", 4) == 0
		|| ft_strncmp(args, "export", 6) == 0
		|| ft_strncmp(args, "pwd", 3) == 0
		|| ft_strncmp(args, "unset", 5) == 0
	);
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
	const char *const restrict args
)
{
	static const t_blt_link	builtins[] = {
		{"cd", bltin_cd},
		{"echo", bltin_echo},
		{"env", bltin_env},
		{"exit", bltin_exit},
		{"export", bltin_export},
		{"pwd", bltin_pwd},
		{"unset", bltin_unset},
		{NULL, NULL}};
	register int			i;
	char					**split_args;
	int						output;

	i = 0;
	while (builtins[i].name && ft_strncmp(args,
		builtins[i].name, ft_strlen(builtins[i].name)) != 0)
		++i;
	if (_UNLIKELY(!builtins[i].name))
		return (-1);
	split_args = ft_split(args, ' ');
	output = builtins[i].func((const char **)split_args);
	free_tab(split_args);
	return (output);
}

#pragma endregion Fonctions