/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:49:54 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_C
# define SETUP_C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-public-)
extern inline char	reader_setup(\
	t_reader **reader,
	const t_mem *restrict const mem
)	// v.1. >>> tag: exp->reader_setup
{
	return (__reader_setup(reader, mem));
}

#endif