/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/25 12:58:36 by nduvoid          ###   ########.fr       */
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

static inline int	_chr(
	const char *const restrict _target,
	const char c
)
{
	register int	i;

	if (unexpect(!_target || !*(_target)))
		return (0);
	i = -1;
	while (_target[++i])
		if (_target[i] == c)
			return (1);
	return (0);
}

static inline int	_help(void)
{
	ft_fprintf(2,
		BLUE "Usage:" RESET " export [options] [NAME=VARIABLE]\n"
		YELLOW "Options:\n" RESET
		"  -h, --help\t\tDisplay this help and exit\n"
	);
	return (EXIT_FAILURE);
}

static inline struct s_args_export	_parse(
	const char **args
)
{
	const int				argc = arraylen((const void *const *)args);
	struct s_args_export	result;
	register int			i;

	if (unexpect(!args || !*args))
		return ((struct s_args_export){0});
	else if (argc < 2)
		return ((struct s_args_export){0, .error = EINVAL});
	else if (ft_strncmp(args[1], "--help", 7) == 0
		|| ft_strncmp(args[1], "-h", 3) == 0)
		return ((struct s_args_export){0, .help = 1});
	result.index_start = 1;
	i = 0;
	while (++i < argc)
	{
		if (unexpect(!_chr(args[i], '=')))
			return ((struct s_args_export){.index_start = i, .error = EINVAL});
		else
			result.index_end = i;
	}
	return (result);
}

/** */
__attribute__((used)) char	bltin_export(
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
	{
		ft_fprintf(2, "export: invalid argument: %s\n", args[arg.index_start]);
	}
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