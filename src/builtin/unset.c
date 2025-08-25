/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/25 14:24:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_builtin.h"

/* -----| Modules   |----- */
#include "builtin.h"
#include "env.h"

#pragma endregion Header
#pragma region Fonctions


static int	_help(void)
{
	ft_fprintf(2,
		"Usage: unset [options] [VARIABLE]\n"
		"Options:\n"
		"  -h, --help                display this help and exit\n"
	);
	return (EXIT_FAILURE);
}

static inline int _unset_parse(
	const char **args__
)
{
	if (!args__ || !*args__)
		return (0);
	else if (_UNLIKELY(ft_strncmp("--help", args__[0], 6) == 0
			|| ft_strncmp("-h", args__[0], 2) == 0))
		return (1);
	else
		return (0);
}

/**
 * @todo: verify that it work for like `unset "BOB AMOGUS" BANANE`
*/
__attribute__((used))
char	builtin_unset(
	const char **args__,
	const int fd_in__,
	const int fd_out__
)
{
	const int		help = _unset_parse(args__);
	register int	i;

	(void)fd_in__;
	(void)fd_out__;
	if (_UNLIKELY(help))
		return (_help());
	i = 0;
	while (args__[++i])
	{
		ft_fprintf(2, "unset: '%s'\n", args__[i]);
		env_unset(args__[i]);
	}
	
	return (EXIT_SUCCESS);
}

#pragma endregion Fonctions