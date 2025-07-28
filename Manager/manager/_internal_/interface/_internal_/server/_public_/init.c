/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/28 11:27:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif /* _GNU_SOURCE */

#pragma region Header
/* -----| Internals |----- */
#include "./server.h"
#include "./types.h"

/* -----| Modules  |----- */
	//...

#pragma endregion Header
#pragma region Functions

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
__attribute__((visibility("hidden"), used))
int	init_signal(void)
{
	return (init_signal__());
}

__attribute__((visibility("hidden"), used))
int	_reset_signal(void)
{
	return (_reset_signal__());
}

// doc ...
__attribute__((always_inline, used))
//    (-internal-)
extern inline char	__server_init(\
	t_server *restrict const server__
)	// v.1. >>> tag: def->env_init
{
	server__->init = &init_signal;
	server__->reset = &_reset_signal;
	return (0);
}

#pragma endregion Functions