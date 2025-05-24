/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:05:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/24 15:22:26 by nduvoid          ###   ########.fr       */
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

#pragma endregion Header
#pragma region Fonctions

__attribute__((always_inline, used)) static inline void	show_help(void)
{
	ft_printf(
		UNDERLINE BLUE "Usage:" RESET "./Minishell [options]\n"
		UNDERLINE YELLOW "Options:\n" RESET
		"  -h, --help       Show this help message\n"
		UNDERLINE BLUE "Author:\n" RESET
		"  nduvoid <" UNDERLINE "nduvoid@student.42mulhouse.fr" RESET ">\n"
		"  rcreuzea <" UNDERLINE "rcreuzea@student.42mulhouse.fr" RESET ">\n"
	);
	exit(0);
}

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

/** */
__attribute__((cold, unused)) t_args	args_parser(
	const int argc,
	const char **argv
)
{
	t_args			args;
	register int	i;

	i = 1;
	while (i < argc && !args.error && !args.help)
	{
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