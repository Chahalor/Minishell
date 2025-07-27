/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:48:58 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK__C
# define CHECK__C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern char _reader_check(\
	const char *restrict const path_,
	const int mode_
)	// v.1. >>> tag: exp->_reader_check
{
	return (__reader_check(path_, mode_));
}

#endif