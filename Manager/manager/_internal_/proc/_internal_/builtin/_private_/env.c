/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/30 10:51:33 by nduvoid          ###   ########.fr       */
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

static int	_help(void)
{
	_manager()->interface.printf(
		"Usage: env [options]\n"
		"Options:\n"
		"  -h, --help                display this help and exit\n"
	);
	return (EXIT_FAILURE);
}

static inline struct int _parse(
	const char **args
)
{
	if (!args || !*args)
		return (0);
	else if (unexpect(_manager()->mem.compare("--help", args[i],
			(unsigned int [1]){7}) || _manager()->mem.compare("-h", args[i],
			(unsigned int [1]){3})))
		return (1);
	else
		return (0);
}

/** */
__attribute__((used)) char	bltin_env(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const int									help = _parse(args);
	const char *restrict const *restrict const	env = _manager()->env.vars();
	register int								i;

	if (unexpect(help))
		return (_help());
	else if (unexpect(!env))
	{
		_manager()->interface.perror("env: failed to retrieve environment");
		return (EXIT_FAILURE);
	}
	i = -1;
	while (env[++i])
		_manager()->interface.printf("%s\n", env[i]);
	return (EXIT_SUCCESS);
}

#pragma endregion Fonctions