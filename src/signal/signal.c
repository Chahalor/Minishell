/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/09 16:53:20 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
#include "sig.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((hot)) void	_sigint_handler(int sig, siginfo_t *info, void *context)
{

}

/** */
__attribute__((hot)) void	_sigquit_handler(int sig)
{
	(void)sig;
}

/** */
__attribute__((unused, cold)) inline void	signal_init(void)
{
	sigaction(SIGINT, _sigint_handler, NULL);
	sigaction(SIGQUIT, _sigquit_handler, NULL);
}

#pragma endregion Fonctions