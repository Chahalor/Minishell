/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 10:32:40 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPERS_H
# define WRAPPERS_H

# pragma once

/* -------- modules --------- */
	// --- internals --- //
# include "_internal_/_wrappers.h"

/* ------- prototypes ------- */
	// ---- exposed ---- //
// expect :
extern unsigned char	unexpect(\
							const unsigned char cond
							)
						__attribute__((always_inline, used, visibility("default")));
extern unsigned char	expect(\
							const unsigned char cond
							)
						__attribute__((always_inline, used, visibility("default")));

#endif