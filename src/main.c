/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:44:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/04 14:01:35 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Systems   |----- */
#include "allowed.h"

/* -----| Internals |----- */
	//...

/* -----| Modules   |----- */
#include "args.h"
#include "signals.h"
#include "mmanager.h"
#include "read_line.h"
#include "parser.h"
#include "exec.h"
#include "builtin.h"
#include "env.h"
#include "utils.h"

volatile sig_atomic_t	g_last_signal = 0;	/* Global signal variable */

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((cold, unused))
int	init_all(
	int argc,
	const char **argv,
	const char **envp
)
{
	args_parser(argc, argv);
	init_signal();
	env_init(envp);
	rl_load_history(env_find("HISTORY_PATH"));
	return (1);
}

__attribute__((always_inline, used))
static inline int	_prompt(
	char *prompt
)
{
	const char	*_prompt = env_expand(prompt);
	char		*line;
	t_exec_data	*data;

	line = read_line(_prompt);
	mm_free((void *)_prompt);
	if (__builtin_expect(!line, unexpected))
		return (1);
	else if (line[0] == '\04')
		return (mm_free(line), 0);
	else if (_LIKELY(line != NULL))
	{
		data = parser(line);
		rl_add_history(line);
		if (_LIKELY(data != NULL))
			full_exec(data, env_getall(1));
	}
	return (mm_free(line), 1);
}

#pragma endregion Fonctions
#pragma region Main

/**
 *
 */
int	main(int argc, const char **argv, const char **envp)
{
	int	running;

	if (_UNLIKELY(!init_all(argc, argv, envp)))
		return (exit_program(1, "main(): Failed to initialize"), EXIT_FAILURE);
	running = 1;
	while (running)
	{
		running = _prompt(env_find("PS1"));
	}
	exit_program(0, DEFAULT_EXIT_MESSAGE);
	return (0);
}

#pragma endregion Main