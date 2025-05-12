/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:53:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/12 08:58:52 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
#include "exit.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Exit the program with a message and a status code.
 * 
 * @param	status	The exit status code.
 * @param	msg		The message to display before exiting.
 * 
 * @note	Use this function to exit the program with a message.
 * @note	/!\ This fonction Should be the only way to exit the program. /!\
 */
__attribute__((noreturn, unused, cold)) void	exit_program(
	const int status,
	const char *restrict msg
)
{
	reset_cmd();
	if (msg)
		printf("%s\n", msg);
	mm_destroy();
	exit(status);
}

#pragma endregion Fonctions