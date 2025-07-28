/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/24 10:18:09 by nduvoid          ###   ########.fr       */
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
 * @brief	Parses the arguments for the pwd command.
 * 
 * @param	args	The arguments to parse.
 * 
 * @return	1 if help is requested, 0 otherwise.
*/
__attribute__((always_inline, used))
static inline char	_parse(
	const char **args
)
{
	register int	i;

	if (unexpect(!args || !*args))
		return (1);
	i = 0;
	while (args[++i])
	{
		if (ft_strncmp(args[i], "--help", 7) == 0
			|| ft_strncmp(args[i], "-h", 3) == 0)
			return (1);
	}
	return (0);
}

/**
 *  @brief	Displays the help message for the pwd command.
 * 
 * @param	void
 * 
 * @return	EXIT_FAILURE
*/
__attribute__((always_inline, used)
static inline char	_help(void)
{
	ft_fprintf(2,
		BLUE "Usage:" RESET " pwd [options]\n"
		"show the current working directory\n"
		YELLOW "Options:\n" RESET
		"  -h, --help\t\tDisplay this help and exit\n"
		);
	return (EXIT_FAILURE);
}

/**
 * @brief	Displays the current working directory.
 * 
 * @param	args	Arguments to parse.
 * @param	fd_in	Input file descriptor (not used).
 * @param	fd_out	Output file descriptor.
 * 
 * @return	The exit status of the command.
 * @retval		EXIT_SUCCESS on success.
 * @retval		EXIT_FAILURE on error.
 * 
 * @version 1.0
*/
__attribute__((used, visibility("hidden")))
char	bltin_pwd(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const char	help = _parse(args);
	const char	*pwd = getcwd(NULL, 0);	// @todo: replace by manager call

	(void)fd_in;
	if (unexpect(!args || help))
		return (_help());
	else if (unexpect(!pwd))
		return (ft_perror("pwd: getcwd failed"), EXIT_FAILURE);
	else
	{
		ft_fprintf(fd_out, "%s\n", pwd);
		free((void *)pwd);
		return (EXIT_SUCCESS);
	}
}

#pragma endregion Fonctions