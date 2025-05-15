/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:44:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/15 09:39:12 by nduvoid          ###   ########.fr       */
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
#include "utils.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((cold, unused)) int	init_all(void)
{
	return (
		init_signal() ||
		rl_load_history(NULL)
	);
}

#pragma endregion Fonctions
#pragma region Main

volatile sig_atomic_t	g_last_signal = 0; // Global signal variable

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *line;

	if (__builtin_expect(init_all(), unexpected))
	{
		perror("Error: init_all() failed\n");
		exit_program(1, "main(): init_all() failed");
	}
	line = read_line(DEFAULT_PROMPT);
	while (ft_strncmp("exit", line, 4) != 0 && g_last_signal != SIGINT)
	{
		if (!line)
		{
			perror("Error: read_line failed\n");
			exit_program(1, "main(): read_line() failed");
		}
		else
		{
			write(STDOUT_FILENO, "You entered: <", 14);
			write(STDOUT_FILENO, line, ft_strlen(line));
			write(STDOUT_FILENO, ">\n", 2);
			rl_add_history(line);
			mm_free(line);
		}
		line = read_line(DEFAULT_PROMPT);
	}
	exit_program(0, "main(): Exiting program");
	return (0);
}

#pragma endregion Main