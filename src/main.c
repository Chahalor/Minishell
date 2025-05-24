/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:44:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/24 13:48:32 by nduvoid          ###   ########.fr       */
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
	char		*line;
	t_exec_data	*data;

	(void)argc;
	(void)argv;
	init_all();
	line = NULL;
	ft_printf("Welcome to the shell!\n");
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
			if (_UNLIKELY(!data))
				perror("main(): built_exec_data() failed");
			else if (data->pipe)
				piping(data, envp);
			else
				data->status = exec_cmd(data, envp);
		}
		rl_add_history(line);
		mm_free(line);
	}
	exit_program(0, "main(): Exiting program");
	return (0);
}

#pragma endregion Main