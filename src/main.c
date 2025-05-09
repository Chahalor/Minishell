/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:44:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/09 22:06:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Systems   |----- */
#include <stdio.h>

/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
#include "sig.h"

#pragma endregion Header
#pragma region Fonctions

#pragma endregion Fonctions
#pragma region Main

volatile sig_atomic_t g_last_signal = 0; // Global signal variable

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	init_signal();
	while (1)
	{
		pause();
		printf("Signal received: %d\n", g_last_signal);
	}
	return (0);
}

#pragma endregion Main