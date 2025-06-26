/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 11:22:32 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_C
# define OPEN_C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used))
//	(-public-)
extern char	open(\
	const char *restrict const path,
	unsigned int *restrict fd
)	// v.1. >>> tag: exp->open
{
	return (_open(path, fd));
}

#endif