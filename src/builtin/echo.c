/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/05 12:56:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_builtin.h"
#include "formating.h"

/* -----| Modules   |----- */
#include "builtin.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Displays the help message for the echo command.
 * 
 * @param	None
 * 
 * @return		Returns EXIT_FAILURE to indicate an error.
*/
__attribute__((always_inline, used)) static inline char	_help(void)
{
	ft_fprintf(2,
		BLUE "Usage:" RESET " echo [options] [string ...]\n"
		YELLOW "Options:\n" RESET
		"  -n, \t\tDo not output the trailing newline\n"
		"  -h, --help\t\tDisplay this help and exit\n"
		);
	return (EXIT_FAILURE);
}

/**
 * @brief	Parses the arguments for the echo command.
 * 
 * @param	args	Arguments to parse.
 * 
 * @return		Returns a struct containing the parsed arguments.
*/
__attribute__((always_inline, used)) static inline struct s_args_echo	_parse(
	const char **args
)
{
	register int		i;
	struct s_args_echo	result;

	result = (struct s_args_echo){.nl = 1, .help = 0};
	if (_UNLIKELY(!args || !*args))
		return (result);
	i = 0;
	while (args[++i])
	{
		if (ft_strncmp(args[i], "-n", 2) == 0)
			result.nl = 0;
		else if (ft_strncmp(args[i], "--help", 6) == 0
			|| ft_strncmp(args[i], "-h", 2) == 0)
			result.help = 1;
		else
			break ;
	}
	return (result);
}

/**
 * @brief	Echoes the given arguments to the standard output.
 * 
 * @param	args	Arguments to echo.
 * @param	fd_in	File descriptor for input (not used).
 * @param	fd_out	File descriptor for output.
 * 
 * @return		Returns the process exit status.
 * * @retval		EXIT_SUCCESS if the command executed successfully.
 * * @retval		EXIT_FAILURE if the command failed or if the help option is
 * * 				used.
 * 
 * @version 2.0
*/
__attribute__((used)) char	bltin_echo(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const struct s_args_echo	parsed = _parse(args);
	register int				i;

	(void)fd_in;
	if (_UNLIKELY(!args || !*args || parsed.help))
		return (_help());
	else if (!parsed.nl)
		i = 1;
	else
		i = 0;
	while (args[++i])
	{
		write(fd_out, args[i], ft_strlen(args[i]));
		if (args[i + 1])
			write(fd_out, " ", 1);
	}
	if (parsed.nl)
		write(fd_out, "\n", 1);
	return (EXIT_SUCCESS);
}

#pragma endregion Fonctions