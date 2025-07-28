/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _wrappers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/15 12:31:29 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WRAPPERS_H
# define _WRAPPERS_H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./_types.h"

/* ------- prototypes ------- */
	// ---- hidden ----- //
// expect :
extern unsigned char	_unexpect(\
							const unsigned char cond
							)
						__attribute__((always_inline, used, visibility("hidden")));
extern unsigned char	_expect(\
							const unsigned char cond
							)
						__attribute__((always_inline, used, visibility("hidden")));

#endif