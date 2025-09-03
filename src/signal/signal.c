/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/03 13:08:15 by nduvoid          ###   ########.fr       */
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
 * @brief	Signal handler for SIGINT (Ctrl+C).
 * 
 * @param	signal	The signal number.
 * @param	info	Pointer to a siginfo_t structure containing information
 * 			 about the signal.
 * @param	context	Pointer to a ucontext_t structure containing the context
 * 			 of the signal.
 * 
 * @note	This function is called when the user presses Ctrl+C in the
 * 			 terminal.
 * 
 * @version 1.1
*/
__attribute__((cold, visibility("hidden"))) void	_sigint_handler(
	int signal,
	siginfo_t *info,
	void *context
)
{
	(void)info;
	(void)context;
	g_last_signal = signal;
}

/**
 * @brief	Signal handler for SIGQUIT (Ctrl+\).
 * 
 * @param	signal	The signal number.
 * @param	info	Pointer to a siginfo_t structure containing information
 * 			 about the signal.
 * @param	context	Pointer to a ucontext_t structure containing the context
 * 			 of the signal.
 *
 * @note	This function is called when the user presses Ctrl+\ in the
 * 			 terminal. It resets the command and sends SIGQUIT to the last
 * 			 child process.
 * 
 * @version 1.1
*/
__attribute__((cold, visibility("hidden"))) void	_sigquit_handler(
	int signal,
	siginfo_t *info,
	void *context
)
{
	(void)info;
	(void)context;
	g_last_signal = signal;
}

/**
 * @brief	Signal handler for SIGTSTP (Ctrl+Z).
 * 
 * @param	signal	The signal number.
 * @param	info	Pointer to a siginfo_t structure containing information
 * 			 about the signal.
 * @param	context	Pointer to a ucontext_t structure containing the context
 * 			 of the signal.
 *
 * @note	This function is called when the user presses Ctrl+Z in the
 * 			 terminal. It sets the last signal to SIGTSTP.
 * 
 * @version 1.0
*/
__attribute__((cold, visibility("hidden"))) void	_sigstp_handler(
	int signal,
	siginfo_t *info,
	void *context
)
{
	(void)info;
	(void)context;
	g_last_signal = signal;
}

__attribute__((always_inline, used)) inline int	reset_signal(void)
{
	return (
		signal(SIGINT, SIG_DFL) == SIG_ERR
		|| signal(SIGQUIT, SIG_DFL) == SIG_ERR
		|| signal(SIGTSTP, SIG_DFL) == SIG_ERR
	);
}

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