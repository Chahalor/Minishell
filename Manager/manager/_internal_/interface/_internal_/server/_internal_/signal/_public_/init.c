/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/22 14:45:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif /* _GNU_SOURCE */

#pragma region Header
/* -----| Internals |----- */
#include "_signals.h"

/* -----| Modules  |----- */
#include "signals.h"

extern volatile sig_atomic_t	g_last_signal; // Global signal variable

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Initializes the signal handlers for all differents signals.
 * 
 * @param	None
 * 
 * @return	the success status of the signal initialization.
 * @retval		0 if the signal handlers were successfully set.
 * @retval		1 if there was an error setting the signal handlers.
 * 
 * @version 1.2
*/
__attribute__((always_inline, used)) inline int	init_signal(void)
{
	struct sigaction	sigint_action;
	struct sigaction	sigquit_action;
	struct sigaction	sigstp_action;

	sigint_action.sa_sigaction = _sigint_handler;
	sigint_action.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sigint_action.sa_mask);
	sigquit_action.sa_sigaction = _sigquit_handler;
	sigquit_action.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sigquit_action.sa_mask);
	sigstp_action.sa_sigaction = _sigstp_handler;
	sigstp_action.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sigstp_action.sa_mask);
	return (
		sigaction(SIGINT, &sigint_action, NULL) == -1
		|| sigaction(SIGQUIT, &sigquit_action, NULL) == -1
		|| sigaction(SIGTSTP, &sigstp_action, NULL) == -1
	);
}
#pragma endregion Fonctions