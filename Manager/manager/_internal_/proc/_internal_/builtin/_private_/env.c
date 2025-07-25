/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/25 12:43:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "builtin_.h"
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

/* -----| Modules   |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

static inline int	_help(void)
{
	ft_fprintf(2,
		BLUE "Usage:" RESET " env [options]\n"
		YELLOW "Options:\n" RESET
		"  -h, --help\t\tDisplay this help and exit\n"
	);
	return (EXIT_FAILURE);
}

static inline int	_parse(
	const char **args
)
{
	const int	argc = arraylen((const void *const *)args);

	if (unexpect(!args || !*args))
		return (builtin_error_none);
	else if (argc < 2)
		return (0);
	else if (ft_strncmp(args[1], "--help", 7) == 0
		|| ft_strncmp(args[1], "-h", 3) == 0)
		return (1);
	else
		return (2);
}

/** */
__attribute__((used)) char	bltin_env(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const char		**env = manager_get_env(); // @todo: replace by a proper call
	const int		help = _parse(args);
	register int	i;

	if (expect(!help))
	{
		i = -1;
		while (env[++i])
			ft_fprintf(fd_out, "%s\n", env[i]);
		return (EXIT_SUCCESS);
	}
	else if (unexpect(help == 1))
		return (_help());
	else
	{
		ft_fprintf(2, RED "env: Unknown option: %s\n" RESET, args[1]);
		return (EXIT_FAILURE);
	}
	return (0);
}

#pragma endregion Fonctions