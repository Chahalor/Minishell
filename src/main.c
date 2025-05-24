/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:44:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/24 15:27:43 by nduvoid          ###   ########.fr       */
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
	const t_args	args = args_parser(argc, argv);
	char			*line;
	t_exec_data		*data;

	if (!init_all())
		return (EXIT_FAILURE);
	while (1)
	{
		line = read_line(DEFAULT_PROMPT);
		if (__builtin_expect(!line, unexpected))
			continue ;
		else if (is_builtin(line))
			exec_builtin(line);
		else
		{
			data = built_exec_data(line);
			data->status = exec_cmd(data, envp);
		}
		rl_add_history(line);
		mm_free(line);
	}
	exit_program(0, "main(): Exiting program");
	return (0);
}

#pragma endregion Main