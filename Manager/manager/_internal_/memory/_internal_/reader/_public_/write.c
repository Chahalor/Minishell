/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 11:22:39 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_C
# define WRITE_C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-public-)
extern char	write(\
	const unsigned int fd,
	const char *restrict const buffer,
	const unsigned int size
)	// v.1. >>> tag: exp->write
{
	return (_write(fd, buffer, size));
}

#endif