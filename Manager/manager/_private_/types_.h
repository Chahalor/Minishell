/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/12 12:07:38 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES__H
# define TYPES__H

# undef TYPES__H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "manager_.h"

/* --------- enums ---------- */
	// ---- manager ---- //
# ifndef E_MANAGER_
#  define E_MANAGER_

// ...

// all private manager module error codes.
enum e_manager_errors_	// v.1. >>> tag: exp->e_manager_errors_
{
	// ...
};

# endif

/* --------- types ---------- */
	// ---- manager ---- //
# ifndef T_MANAGER_
#  define T_MANAGER_

typedef t_manager__		t_manager_;	// v.1. >>> tag: exp->t_manager_

# endif

/* ---------- size ---------- */
	// ---- manager ---- //
# ifndef SZ_MANAGER_
#  define SZ_MANAGER_

// all private sizes used in manager module.
enum e_manager_sizes__	// v.1. >>> tag: exp->e_manager_sizes_
{
	// sizes :
	manager_size_				= (\
									sizeof(t_manager_)),
	// offsets :
	manager_mem_offset_			= manager_mem_offset__,
	manager_env_offset_			= manager_env_offset__,
	manager_proc_offset_		= manager_proc_offset__,
	manager_interface_offset_	= manager_interface_offset__,
};

# endif

#endif