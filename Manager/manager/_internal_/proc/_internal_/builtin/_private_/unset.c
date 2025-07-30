/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/30 10:55:53 by nduvoid          ###   ########.fr       */
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
		"Usage: unset [options] [VARIABLE]\n"
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

/**
 * @todo: verify that it work for like unset "BOB AMOGUS" BANANE
*/
__attribute__((used)) char	bltin_env(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const int		help = _parse(args);
	register int	i;

	if (unexpect(help))
		return (_help());
	i = -1;
	while (args[++i])
		_manager()->env.unset(args[i]);
	return (EXIT_SUCCESS);
}

#pragma endregion Fonctions