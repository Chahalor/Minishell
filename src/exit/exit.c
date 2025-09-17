/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:53:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 10:49:17 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Internals |----- */
	//...

/* -----| Modules   |----- */
#include "exit.h"

/**
 * @brief	Exit the program with a message and a status code.
 * 
 * @param	status	The exit status code.
 * @param	msg		The message to display before exiting.
 * 
 * @note	Use this function to exit the program with a message.
 * @note	/!\ This fonction Should be the only way to exit the program. /!\
 */
__attribute__((noreturn, unused, cold))
void	exit_program(
	const int status,
	const char *restrict msg
)
{
	rl_reset_cmd();
	rl_clear_history();
	mm_destroy();
	fdm_close_all();
	if (msg)
		printf("%s\n", msg);
	exit(status);
}
