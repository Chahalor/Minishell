/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/04 14:48:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_builtin.h"
#include "read_line.h"

/* -----| Modules   |----- */
#include "builtin.h"

#pragma endregion Header
#pragma region Fonctions

__attribute__((always_inline, used))
static inline t_args_history	_parse(
	const char **args
)
{
	int	i;

	if (_UNLIKELY(!args || !args[1]))
		return ((t_args_history){0});
	i = 1;
	if (ft_strncmp(args[i], "-h", 2) == 0
		|| ft_strncmp(args[i], "--help", 7) == 0)
		return ((t_args_history){.help = 1});
	else
	{
		if (!args[i])
			return ((t_args_history){.target = ""});
		else
			return ((t_args_history){.target = (char *)args[i]});
	}
}

__attribute__((always_inline, used))
static inline int	_help(void)
{
	ft_fprintf(
		STDERR_FILENO,
		BLUE "Usage:" RESET " history\n"
		"Display the command history.\n"
		"\n"
		YELLOW "Options:\n" RESET
		"  -h, --help\tDisplay this help message and exit.\n"
		);
	return (EXIT_SUCCESS);
}

__attribute__((always_inline, used))
static inline int	__search(
	const t_history *const restrict rl,
	const char *const restrict target,
	const int fd_out
)
{
	register int	j;

	j = rl->pos + 1;
	while (j != rl->pos)
	{
		if (_LIKELY(rl->storage[j] != NULL
				&& ft_strchr(rl->storage[j], target) != NULL))
			ft_fprintf(fd_out, "%s\n", rl->storage[j]);
		j = (j + 1) % _RL_HIST_SIZE;
	}
	return (0);
}

/** */
char	builtin_history(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const t_history			*rl = rl_get_history();
	const t_args_history	_args = _parse(args);
	register int	i;

	(void)fd_in;
	if (_UNLIKELY(!rl))
		return (EXIT_FAILURE);
	else if (_args.help)
		return (_help());
	else if (_args.target)
		return (__search(rl, _args.target, fd_out), EXIT_SUCCESS);
	i = rl->pos + 1;
	while (i != rl->pos)
	{
		if (_LIKELY(rl->storage[i] != NULL))
			ft_fprintf(fd_out, "%s\n", rl->storage[i]);
		i = (i + 1) % _RL_HIST_SIZE;
	}
	return (EXIT_SUCCESS);
}

#pragma endregion Fonctions