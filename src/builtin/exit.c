/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/13 11:49:14 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_builtin.h"
#include "utils.h"

/* -----| Modules   |----- */
#include "builtin.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Parses the arguments for the exit command.
 * 
 * @param	args	The arguments to parse.
 * 
 * @return	A structure containing the parsed arguments.
 *  @retval		.exit_code The exit code to use when exiting.
 *  @retval		.error The error type if any error occurred.
 *  @retval		.help A flag indicating if help was requested.
*/
__attribute__((always_inline, used)) static inline struct s_args_exit	_parse(
	const char **args
)
{
	struct s_args_exit	parsed;
	register int		i;

	parsed = (struct s_args_exit){0};
	i = 1;
	if (ft_strncmp(args[i], "-h", 3) == 0 
		|| ft_strncmp(args[i], "--help", 7) == 0)
		parsed.help = 1;
	else
	{
		if (is_nbr(args[i]))
			parsed.exit_code = (unsigned int)ft_atoi(args[i]);
		else
			parsed.error = builtin_error_not_numeric;
	}
	if (args[i + 1])
		parsed.error =  builtin_error_too_many_args;
	return (parsed);
}

/**
 *  @brief	Displays the help message for the exit command.
 * 
 * @param	void
 * 
 * @return	EXIT_FAILURE
*/
__attribute__((always_inline, used)) static inline char	_help(void)
{
	ft_printf("look what that do:\n");
	exit_program(EXIT_FAILURE, DEFAULT_EXIT_MESSAGE);
	return (EXIT_FAILURE);
}

/**
 * @brief	Displays an error message and exits the program.
 * 
 * @param	error The error type to display.
 * @param	exit_code The exit code to use when exiting.
 * 
 * @return	EXIT_FAILURE
 */
__attribute__((always_inline, used)) static inline char	_error(
	const enum e_builtin_error error,
	const char exit_code
)
{
	const char *msg[5] = {
		[builtin_error_too_many_args] = "exit: too many arguments\n",
		[builtin_error_not_numeric] = "exit: not a numeric argument\n",
	};

	ft_printf("%s", msg[error]);
	exit_program(exit_code, DEFAULT_EXIT_MESSAGE);
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
__attribute__((used)) char	bltin_exit(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const struct s_args_exit	parsed = _parse(args);

	(void)fd_in;
	(void)fd_out;
	if (parsed.help)
		return (_help());
	else if (parsed.error)
		return (_error(parsed.error, parsed.exit_code));
	else
		exit_program(parsed.exit_code, DEFAULT_EXIT_MESSAGE);
	 return (EXIT_SUCCESS);
}

#pragma endregion Fonctions