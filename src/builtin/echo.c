/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/16 09:53:12 by nduvoid          ###   ########.fr       */
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
	ft_fprintf(STDERR_FILENO,
		BLUE "Usage:" RESET " echo [options] [string ...]\n"
		YELLOW "Options:\n" RESET
		"  -n, \t\tDo not output the trailing newline\n"
		"  -h, --help\t\tDisplay this help and exit\n"
		);
	return (EXIT_FAILURE);
}

/** */
__attribute__((always_inline, used)) static inline int	_is_no_nl(
	const char *const restrict arg
)
{
	register int	i;

	if (_UNLIKELY(!arg || !*arg))
		return (0);
	i = 0;
	while (ft_is_space(*arg))
		i++;
	if (!(arg[i] == '-'))
		return (0);
	while (arg[++i] && !ft_is_space(arg[i]))
	{
		if (arg[i] != 'n')
			return (0);
	}
	if (i != (int)ft_strlen(arg))
		return (0);
	return (1);
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

	result = (struct s_args_echo){.start = 0, .nl = 1, .help = 0};
	if (_UNLIKELY(!args || !*args))
		return (result);
	i = 0;
	if (args[1] && (ft_strncmp(args[1], "--help", 6) == 0
			|| ft_strncmp(args[1], "-h", 2) == 0))
		result.help = 1;
	while (args[++i] && _is_no_nl(args[i]))
	{
		result.nl = 0;
		++result.start;
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
__attribute__((used))
char	builtin_echo(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const struct s_args_echo	parsed = _parse(args);
	register int				i;

	(void)fd_in;
	if (_UNLIKELY(parsed.help))
		return (_help());
	i = parsed.start;
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