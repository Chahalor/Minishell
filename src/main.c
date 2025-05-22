/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:44:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/22 09:41:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Systems   |----- */
#include <stdio.h>
#include <signal.h>

/* -----| Internals |----- */
	//...

/* -----| Modules   |----- */
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

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argc;
	(void)argv;
	init_all();
	line = NULL;
	ft_printf("Welcome to the shell!\n");
	while (1)
	{
		line = read_line(DEFAULT_PROMPT);
		ft_printf("You entered: <%s>\n", line);
		if (__builtin_expect(!line, unexpected))
			continue ;
		else if (is_builtin(line))
			exec_builtin(line);
		else
			exec_cmd(built_exec_data(line), envp);
		rl_add_history(line);
		mm_free(line);
	}
	exit_program(0, "main(): Exiting program");
	return (0);
}

#pragma endregion Main