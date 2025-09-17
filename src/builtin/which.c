/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 10:46:28 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Internals |----- */
#include "_builtin.h"
#include "read_line.h"

/* -----| Modules   |----- */
#include "builtin.h"

char			*_get_bin(
					char *name
					);

static inline char	__help(void)
{
	ft_fprintf(
		STDERR_FILENO,
		BLUE "Usage:" RESET " which COMMAND...\n"
		"Locate a command.\n"
		"\n"
		YELLOW "Options:\n" RESET
		"  -h, --help\tDisplay this help message and exit.\n"
		);
	return (EXIT_SUCCESS);
}

static inline int	__parse(
	const char **args
)
{
	if (_UNLIKELY(!args || !args[1]))
		return (builtin_help);
	else if (ft_strncmp(args[1], "-h", 2) == 0
		|| ft_strncmp(args[1], "--help", 7) == 0)
		return (builtin_help);
	return (builtin_no_error);
}

char	builtin_which(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const int		__target = __parse(args);
	register int	__i;
	char			*__path;
	char			_ret;

	(void)fd_in;
	if (__target == builtin_help)
		return (__help());
	_ret = EXIT_SUCCESS;
	__i = 0;
	while (args[++__i])
	{
		if (get_builtins(args[__i]))
		{
			ft_fprintf(fd_out, "%s: shell builtin command.\n", args[__i]);
			continue ;
		}
		__path = _get_bin((char *)args[__i]);
		if (__path)
			ft_fprintf(fd_out, "%s\n", __path);
		else
			_ret = EXIT_FAILURE;
		mm_free(__path);
	}
	return (_ret);
}
