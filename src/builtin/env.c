/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/25 13:48:00 by nduvoid          ###   ########.fr       */
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


static int	__help(void)
{
	ft_fprintf(STDERR_FILENO,
		BLUE "Usage:" RESET " env [options]\n"
		"Shows the current environment variables.\n"
		YELLOW "Options:\n" RESET
		"  -h, --help                display this help and exit\n"
	);
	return (EXIT_FAILURE);
}

static inline int	__env_parse(
	const char **args__
)
{
	if (!args__ || !args__[0] || !args__[1])
		return (0);
	else if (_UNLIKELY(ft_strncmp("--help", args__[0], 6)
			|| ft_strncmp("-h", args__[0], 2)))
		return (1);
	else
		return (0);
}

/** */
__attribute__((used, visibility("hidden")))
char	builtin_env(
	const char **args__,
	const int fd_in__,
	const int fd_out__
)
{
	const int		help_ = __env_parse(args__);
	char			**_env;
	register int	_i;

	(void)fd_in__;
	if (_UNLIKELY(help_))
		return (__help());
	_env = env_getall();
	if (_UNLIKELY(!_env))
	{
		perror("env");
		return (EXIT_FAILURE);
	}
	_i = -1;
	while (_env[++_i])
		ft_fprintf(fd_out__, " [%d] %s\n", _i, _env[_i]);
	free_tab(_env);
	return (EXIT_SUCCESS);
}

#pragma endregion Fonctions