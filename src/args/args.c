/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:05:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/13 12:01:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
// #include "_args.h"

/* -----| Modules   |----- */
#include "args.h"
#include "utils.h"
#include "ft_printf.h"
#include "formating.h"
#include "exit.h"

#pragma endregion Header
#pragma region Fonctions

/**
 *  @brief	Displays the help message for the program.
 * 
 * This function prints the usage and options of the program to the standard output
 * and then exits the program with a success status.
 */
__attribute__((always_inline, used)) static inline void	show_help(void)
{
	ft_printf(
		UNDERLINE BLUE "Usage:" RESET "./Minishell [options]\n"
		UNDERLINE YELLOW "Options:\n" RESET
		"  -h, --help       Show this help message\n"
		UNDERLINE BLUE "Author:\n" RESET
		"  nduvoid  <" BLUE UNDERLINE "nduvoid@student.42mulhouse.fr" RESET ">\n"
		"  rcreuzea <" BLUE UNDERLINE "rcreuzea@student.42mulhouse.fr" RESET ">\n"
		);
	exit_program(0);
}

/**
 *  @brief	Parses a long option passed to the program at startup.
 * 
 * @param	option The option string to parse.
 * @param	args The struct to store parsed arguments.
 * 
 * @return	the number of arguments parsed (1 for long options).
 */
__attribute__((always_inline, used)) static inline int	parse_long_option(
	const char *const restrict option,
	t_args *const restrict args
)
{
	if (ft_strncmp(option, "--help", 6) == 0)
	{
		args->help = 1;
		show_help();
		return (1);
	}
	else
	{
		ft_fprintf(2, "Unknown option: %s\n", option);
		args->error = 1;
		return (1);
	}
}

/**
 * @brief	Parses a short option passed to the program at startup.
 * 
 * @param	option The option string to parse.
 * @param	args The struct to store parsed arguments.
 * 
 * @return	the number of arguments parsed (1 for short options).
 */
__attribute__((always_inline, used)) static inline int	parse_short_option(
	const char *const restrict option,
	t_args *const restrict args
)
{
	if (ft_strncmp(option, "-h", 2) == 0)
	{
		args->help = 1;
		show_help();
		return (1);
	}
	else
	{
		ft_fprintf(2, "Unknown option: %s\n", option);
		args->error = 1;
		return (1);
	}
}

/**
 * @brief	Parsed agrument passed to the program at startup.
 * 
 * @param	argc The number of arguments.
 * @param	argv The array of argument strings.
 * 
 * @return	The struct containing the parsed arguments.
 *  @retval	.	.argc The number of arguments.
 *  @retval		.argv The array of argument strings.
 *  @retval		.error The error flag, set to 1 if an error occurred.
 *  @retval		.help The help flag, set to 1 if help was requested.
*/
__attribute__((cold, unused)) t_args	args_parser(
	const int argc,
	const char **argv
)
{
	t_args			args;
	register int	i;

	args = (t_args){0};
	i = 0;
	while (i < argc && !args.error && !args.help)
	{
		ft_fprintf(2, "Parsing argument: <%s>\n", argv[i]);
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-')
				i += parse_long_option(argv[i], &args);
			else
				i += parse_short_option(argv[i], &args);
		}
		else
			++i;
	}
	return (args);
}

#pragma endregion Fonctions