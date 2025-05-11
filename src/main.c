/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:44:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/11 17:05:49 by nduvoid          ###   ########.fr       */
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

#pragma endregion Fonctions
#pragma region Main

volatile sig_atomic_t	g_last_signal = 0; // Global signal variable

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *line;

	init_signal();
	line = read_line("prompt> ");
	if (!line)
	{
		perror("Error: read_line failed\n");
		return (1);
	}
	else
		printf("You entered: <%s>\n", line);
	mm_destroy();
	return (0);
}

#pragma endregion Main