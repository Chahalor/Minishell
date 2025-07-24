/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/24 10:17:25 by nduvoid          ###   ########.fr       */
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
static inline int	_parse(
	const char **args
)
{
	int	i;

	if (unexpect(!args || !args[1]))
		return (0);
	i = 1;
	if (ft_strncmp(args[i], "-h", 2) == 0
		|| ft_strncmp(args[i], "--help", 7) == 0)
		return (1);
	else
		return (0);
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

/** */
__attribute__((visibility("hidden"), used))
char	bltin_history(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const t_history	*rl = rl_get_history();
	const int		help = _parse(args);
	register int	i;

	(void)fd_in;
	if (unexpect(!rl))
		return (EXIT_FAILURE);
	else if (help)
		return (_help());
	i = rl->pos + 1;
	while (i != rl->pos)
	{
		if (expect(rl->storage[i] != NULL))
			ft_fprintf(fd_out, "%s\n", rl->storage[i]);
		i = (i + 1) % _RL_HIST_SIZE;
	}
	return (EXIT_SUCCESS);
}

#pragma endregion Fonctions