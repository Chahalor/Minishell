/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/25 15:58:33 by nduvoid          ###   ########.fr       */
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
		BLUE "Usage:" RESET " unset [options] [NAME]\n"
		YELLOW "Options:\n" RESET
		"  -h, --help\t\tDisplay this help and exit\n"
	);
	return (EXIT_FAILURE);
}

static inline int	_parse(
	const char **args
)
{
	const int		argc = arraylen((const void *const *)args);
	register int	i;

	if (unexpect(!args || !*args || argc < 2))
		return (-1);
	i = -1;
	while (++i < argc)
		if (ft_strncmp(args[i], "-h", 3) == 0
			|| ft_strcmp(args[i], "--help", 7) == 0)
			return (1);
	return (0);
}

/** */
__attribute__((used)) char	bltin_unset(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const struct s_args_export	arg = _parse(args);
	register int				i;

	if (unexpect(arg.help))
		return (_help());
	else if (unexpect(arg.error))
		ft_fprintf(2, "export: invalid argument: %s\n", args[arg.index_start]);
	i = arg.index_start;
	while (i < arg.index_end)
	{
		if (manager_export(args[i]) != 0)
		{
			ft_fprintf(2, "export: failed to export: %s\n", args[i]);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

#pragma endregion Fonctions