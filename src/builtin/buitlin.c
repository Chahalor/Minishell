/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitlin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/22 13:52:57 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_builtin.h"

/* -----| Modules   |----- */
#include "builtin.h"

#pragma endregion Header
#pragma region Fonctions

void	free_tab(
	char ***tab
)
{
	char	**tmp;

	if (__builtin_expect(!tab || !*tab, unexpected))
		return ;
	tmp = *tab;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(*tab);
	*tab = NULL;
	return ;
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
		|| ft_strncmp(args, "relaunch", 7) == 0
		|| ft_strncmp(args, "history", 7) == 0
	);
}

/**
 * @brief Execute the builtin command
 * 
 * @param args The command to execute
 * 
 * @return 1 if the command is a builtin, -1 otherwise
*/
__attribute__((always_inline, used)) inline char	exec_builtin(
	const char *const restrict args
)
{
	/*__attribute__((cleanup(free_tab)))*/ char	**split;

	split = ft_split(args, ' ');
	if (__builtin_expect(!split, unexpected))
		return (-1);
	else if (ft_strncmp(args, "cd", 2) == 0)
		return (bltin_cd((const char *const *restrict)split));
	else if (ft_strncmp(args, "echo", 4) == 0)
		return (bltin_echo((const char *const *restrict)split));
	else if (ft_strncmp(args, "env", 3) == 0)
		return (bltin_env((const char *const *restrict)split));
	else if (ft_strncmp(args, "exit", 4) == 0)
		return (exit_program(1, NULL), 1);
	else if (ft_strncmp(args, "export", 6) == 0)
		return (bltin_export((const char *const *restrict)split));
	else if (ft_strncmp(args, "pwd", 3) == 0)
		return (bltin_pwd((const char *const *restrict)split));
	else if (ft_strncmp(args, "unset", 5) == 0)
		return (bltin_unset((const char *const *restrict)split));
	else if (ft_strncmp(args, "relaunch", 7) == 0)
		return (execv("./Minishell", (char *const[]){"./Minishell", NULL}), 1);
	else if (ft_strncmp(args, "history", 7) == 0)
		return (bltin_history((const char *const *restrict)split));
	return (-1);
}

#pragma endregion Fonctions