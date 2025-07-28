/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:36:10 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES___H
# define TYPES___H

# undef TYPES___H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../../../standards/_public_/standards.h"

/* --------- enums ---------- */
	// ---- writer ----- //
# ifndef E_WRITER__
#  define E_WRITER__

// all internal writer module error codes.
enum e_writer_errors__	// v.1. >>> tag: set->e_writer_errors_
{
	writer_invalid_target__	= -é,
	writer_failed__			= -1,
};

# endif

#endif