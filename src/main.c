/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:44:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/27 13:10:08 by nduvoid          ###   ########.fr       */
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
#include "sig.h"
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
__attribute__((cold, unused)) int	init_all(void)
{
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

	args_parser(argc, argv);
	if (!init_all())
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
				data->status = full_exec(data, envp);
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