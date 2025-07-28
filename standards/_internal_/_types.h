/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/24 15:56:30 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TYPES_H
# define _TYPES_H

# undef _TYPES_H
# pragma once

/* -------- modules --------- */
	// ----- config ----- //
# include "../../config/_public_/config.h"

	// ----- locals ----- //
# include "./_dependencies.h"

/* --------- enums ---------- */
	// ---- common ----- //
# ifndef E_ERRORS
#  define E_ERRORS

// TODO: re-order errors codes.

// common error codes.
enum e_errors
{
	successfully_failed	= -17,
	// ...
	failed_to_print,
	failed_to_setup,
	// ...
	operation_failure,
	operation_unauthorized,
	invalid_input_error,
	invalid_input_type_error,
	invalid_input_syntax_error,
	invalid_value_error,
	// ...
	error				= -1,
	no_error			= +0,
	none				= +0,
};

# endif

/* --------- types ---------- */
	// ---- common ----- //
# ifndef T_COMMON__
#  define T_COMMON__

typedef unsigned char	t_uchar__;	// v.1. >>> tag: def->t_uchar

# endif

/* -------- structs --------- */
// ...

#endif