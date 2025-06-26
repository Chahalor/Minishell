/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 11:22:35 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_C
# define READ_C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used))
//	(-public-)
extern char	read(\
	unsigned int *restrict fd,
	char *restrict const buffer
)	// v.1. >>> tag: exp->read
{
	return (_read(fd, buffer));
}

#endif