/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _open.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/22 13:23:46 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _OPEN_C
# define _OPEN_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_reader.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char	_open(\
	const char *restrict const path,
	unsigned int *restrict fd
)	// v.1. >>> tag: def->open
{
	*fd = open(path, O_CREAT | O_RDWR | O_APPEND);
	if (unexpect(*fd < 0))
		return (failed_to_open);
	return (no_error);
}

#endif