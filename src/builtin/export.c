/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/25 14:20:33 by nduvoid          ###   ########.fr       */
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

static inline int	_is_valid_name(
	const char *restrict const str
)
{
	register int	i;

	if (_UNLIKELY(!str || !*str))
		return (0);
	if (_UNLIKELY(!(
		('a' <= str[0] && str[0] <= 'z')
		|| ('A' <= str[0] && str[0] <= 'Z'))
		|| str[0] == '_'))
		return (0);
	i = 0;
	while (str[++i])
		if (!((str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z') ||
			(str[i] >= '0' && str[i] <= '9') ||
			str[i] == '_'))
			return (0);
	return (1);
}

static inline int	_help()
{
	ft_fprintf(STDERR_FILENO,
		BLUE "Usage:" RESET " export [options] [name=value]\n"
		"Exports the given variables to the environment.\n"
		YELLOW "Options:\n" RESET
		"  -h, --help                display this help and exit\n"
	);
	return (EXIT_FAILURE);
}

static inline struct s_args_export _export_parse(
	const char **args
)
{
	register int	i;
	char			**splited;

	i = 0;
	if (_UNLIKELY(ft_strncmp(args[i], "-h", 2) == 0
		|| ft_strncmp(args[i], "--help", 6) == 0))
		return ((struct s_args_export){.help = 1});
	while (args[++i])
	{
		splited = ft_split((char *)args[i], '=');
		if (_UNLIKELY(!splited))
			return ((struct s_args_export){.error = ENOMEM});
		else if (_LIKELY(_is_valid_name(splited[0]) && splited[1]))
				env_export(splited[0], splited[1]);
		free_tab(splited);
	}
	return ((struct s_args_export){0});
}

/** */
__attribute__((used, visibility("hidden")))
char	builtin_export(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const struct s_args_export	args_env = _export_parse(args);

	(void)fd_in;
	(void)fd_out;
	if (_UNLIKELY(args_env.help))
		return (_help());
	else if (args_env.error)
	{
		ft_fprintf(2, "env: %s\n", strerror(args_env.error));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

#pragma endregion Fonctions