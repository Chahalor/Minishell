/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:41:12 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT__C
# define INIT__C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader_.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-private-)
extern inline char	_reader_init(\
	t_reader_ *restrict const reader_
)	// v.1. >>> tag: exp->_reader_init
{
	return (__reader_init(reader_));
}

#endif