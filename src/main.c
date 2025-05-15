/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:44:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/15 16:44:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Systems   |----- */
#include <stdio.h>

/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
#include "sig.h"
#include "mmanager.h"
#include "read_line.h"
#include "exec/exec.h"
#include "utils.h"

volatile sig_atomic_t	g_last_signal = 0; // Global signal variable

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((cold, unused)) int	init_all(void)
{
	return (
		init_signal() ||
		rl_load_history(DEFAULT_HISTORY_FILE)
	);
}

#pragma endregion Fonctions
#pragma region Main

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	char	*line;
	

	if (__builtin_expect(init_all(), unexpected))
	{
		perror("Error: init_all() failed\n");
		exit_program(1, "main(): init_all() failed");
	}
	line = read_line(DEFAULT_PROMPT);
	while (ft_strncmp("exit", line, 4) != 0 && !g_last_signal)
	{
		if (!line)
		{
			perror("Error: read_line failed\n");
			exit_program(1, "main(): read_line() failed");
		}
		else
		{
			ft_printf("You entered: <%s>\n", line);
			rl_add_history(line);
			exec_cmd(built_exec_data(line), envp);
			mm_free(line);
			// exit_program(0, "main(): exec_cmd() exit");
		}
		line = read_line(DEFAULT_PROMPT);
	}
	exit_program(0, "main(): Exiting program");
	return (0);
}

#pragma endregion Main