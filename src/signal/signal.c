/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/12 08:59:34 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
#include "sig.h"

extern volatile sig_atomic_t g_last_signal; // Global signal variable

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((hot)) void	_sigint_handler(
	int signal,
	siginfo_t *info,
	void *context
)
{
	(void)info;
	(void)context;
	g_last_signal = signal;
	reset_cmd();
	printf("\nSIGINT received\n");
	exit_program(signal, "SIGINT received");	// should be change
}

/** */
__attribute__((hot)) void	_sigquit_handler(
	int signal,
	siginfo_t *info,
	void *context
)
{
	(void)info;
	(void)context;
	g_last_signal = signal;
	reset_cmd();
	printf("\nSIGQUIT received\n");
	exit_program(signal, "SIGQUIT received");	// should be change
}

/** */
__attribute__((always_inline, used)) inline int	init_signal(void)
{
	struct sigaction	sigint_action;
	struct sigaction	sigquit_action;

	sigint_action.sa_sigaction = _sigint_handler;
	sigint_action.sa_flags = SA_SIGINFO;
	sigemptyset(&sigint_action.sa_mask);
	sigquit_action.sa_sigaction = _sigquit_handler;
	sigquit_action.sa_flags = SA_SIGINFO;
	sigemptyset(&sigquit_action.sa_mask);
	return (
		sigaction(SIGINT, &sigint_action, NULL) == -1
		|| sigaction(SIGQUIT, &sigquit_action, NULL) == -1
	);
}

#pragma endregion Fonctions