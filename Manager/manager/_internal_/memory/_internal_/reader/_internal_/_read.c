/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 10:53:27 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _READ_C
# define _READ_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_reader.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char	_read(\
	unsigned int *restrict fd,
	char *restrict const buffer
)	// v.1. >>> tag: def->read
{
	if (!buffer)
		return (no_error);
	if (unexpect(read(fd, buffer, READ_SIZE) != READ_SIZE))
		return (failed_to_read);
	return (no_error);
}

#endif