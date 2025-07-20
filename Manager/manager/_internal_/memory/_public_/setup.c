/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 15:06:11 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_C
# define SETUP_C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-public-)
extern inline char	mem_setup(\
	void **mem
)	// v.1. >>> tag: exp->mem_setup
{
	return (__mem_setup((t_mem **)mem));
}

#endif