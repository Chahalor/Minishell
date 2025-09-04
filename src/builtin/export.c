/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/04 14:37:16 by nduvoid          ###   ########.fr       */
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
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9')
				|| str[i] == '_'))
			return (0);
	return (1);
}

static inline int	_help(void)
{
	ft_fprintf(STDERR_FILENO,
		BLUE "Usage:" RESET " export [options] [name=value]\n"
		"Exports the given variables to the environment.\n"
		YELLOW "Options:\n" RESET
		"  -h, --help                display this help and exit\n"
		);
	return (EXIT_FAILURE);
}

static inline int	_export_split(
	const char *const restrict str,
	char *splited[3]
)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '=')
		;
	(splited)[0] = mm_alloc(i + 1);
	if (!str[i])
		(splited)[1] = NULL;
	else
		(splited)[1] = mm_alloc(ft_strlen(str + i + 1) + 1);
	if (_UNLIKELY(!splited[0]))
		return (free_tab(splited), 1);
	ft_memcpy((splited)[0], str, i);
	if (splited[1])
		ft_memcpy((splited)[1], str + i + 1, ft_strlen(str + i + 1) + 1);
	(splited)[2] = NULL;
	if (!splited[0] || (!_is_valid_name((splited)[0])))
		return (1);
	else
		return (0);
}

static inline struct s_args_export	_export_parse(
	const char **args,
	const int fd_out
)
{
	register int	i;
	char			*splited[3];

	i = 0;
	if (_UNLIKELY(ft_strncmp(args[1], "-h", 2) == 0
			|| ft_strncmp(args[1], "--help", 6) == 0))
		return ((struct s_args_export){.help = 1});
	_neutral(splited, sizeof(splited));
	while (args[++i])
	{
		if (_export_split(args[i], splited))
			ft_fprintf(fd_out, "export: `%s': not a valid identifier\n", \
				splited[0]);
		else
			env_export(splited[0], splited[1]);
		free_tab(splited);
	}
	if (i == 1)
		return ((struct s_args_export){.printf_all = 1});
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
	const struct s_args_export	args_env = _export_parse(args, fd_out);
	const char					**env = (const char **)env_getall(1);
	register int				i;
	int							exit_status;

	(void)fd_in;
	exit_status = EXIT_SUCCESS;
	if (_UNLIKELY(args_env.help))
		return (free_tab((char **)env), _help());
	else if (args_env.printf_all)
	{
		i = -1;
		while (env && env[++i])
			ft_fprintf(fd_out, "%s\n", env[i]);
	}
	else if (args_env.error)
	{
		ft_fprintf(2, "env: %s\n", strerror(args_env.error));
		exit_status = EXIT_FAILURE;
	}
	free_tab((char **)env);
	return (exit_status);
}

#pragma endregion Fonctions