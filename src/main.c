/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:44:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/29 13:55:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Systems   |----- */
#include <stdio.h>
#include <signal.h>

/* -----| Internals |----- */
	//...

/* -----| Modules   |----- */
#include "args.h"
#include "signals.h"
#include "mmanager.h"
#include "read_line.h"
#include "lexer.h"
#include "exec.h"
#include "builtin.h"
#include "utils.h"

volatile sig_atomic_t	g_last_signal = 0; // Global signal variable

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((cold, unused)) int	init_all(
	int argc,
	const char **argv
)
{
	args_parser(argc, argv);
	return (
		init_signal() \
		|| rl_load_history(DEFAULT_HISTORY_FILE)
	);
}

#pragma endregion Fonctions
#pragma region Main

/**
 *
 */
int	main(int argc, const char **argv, char **envp)
{
	char			*line;
	t_exec_data		*data;

	if (!init_all(argc, argv))
		return (EXIT_FAILURE);
	while (1)
	{
		line = read_line(DEFAULT_PROMPT);
		if (__builtin_expect(!line, unexpected))
			continue ;
		else
		{
			data = lexer(line);
			if (data)
			{
				rl_add_history(line);
				full_exec(data, envp);
			}
			else
				perror("command not found");
		}
		mm_free(line);
	}
	exit_program(0, "main(): Exiting program");
	return (0);
}

#pragma endregion Main