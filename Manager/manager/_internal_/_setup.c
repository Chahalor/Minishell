/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _setup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/22 12:22:45 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SETUP_C
# define _SETUP_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_manager.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-hidden-) x (-local-)
extern inline uintptr_t	_section(\
	uintptr_t *restrict const ptr,
	const unsigned int size
)	// v.1. >>> .
{
	const uintptr_t	addr = *ptr;

	*ptr += size;
	return (addr);
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline t_manager_	*_setup_manager(\
	char *restrict *restrict const env
)	// v.1. >>> tag: def->setup_manager
{
	t_manager_	*restrict	manager;
	// other vars ...

	manager = NULL;
	if (expect(\
		alloc((void **)&manager, \
			// size of the manager to be allocated ...
			) != no_error))
		return (NULL);
	return (
			// init here ...
			manager);
}

#endif