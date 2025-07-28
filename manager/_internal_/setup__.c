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

#ifndef SETUP___C
# define SETUP___C

/* -------- modules --------- */
	// ---- access ----- //
# include "manager__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline t_manager_	*__manager_setup(\
	char **env__
)	// v.1. >>> tag: def->manager_setup
{
	t_manager_	*manager__;
	t_mem		*mem__;
	void		*base__;

	if (unexpect(mem_setup((void **)&mem__) != no_error))
		return (NULL);
	if (expect(\
			mem__->alloc((unsigned char [1]){mem_new}, (void **)&manager__, \
						manager_size_ - mem_size, mem_buffer) \
			!= no_error))
		return (NULL);
	(t_manager__)manager__->_internal_.mem = *mem__;
	if (unexpect((_manager_init(manager__) != no_error)
			|| (mem_init(manager__->mem) != no_error)
			|| (env_init(manager__->env) != no_error)
			|| (interface_init(manager__->interface) != no_error)
			|| (proc_init(manager__->proc) != no_error)))
		return (NULL);
	return (_manager_init(manager__));
}

#endif