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

#ifndef TYPES___H
# define TYPES___H

# undef TYPES___H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../standards/standards.h"

/* --------- enums ---------- */
	// ---- manager ---- //
# ifndef E_MANAGER__
#  define E_MANAGER__

// ...

// all internal manager module error codes.
enum e_manager_errors__	// v.1. >>> tag: set->e_manager_errors_
{
	// ...
};

# endif

/* --------- types ---------- */
	// ---- manager ---- //
# ifndef T_MANAGER__
#  define T_MANAGER__

typedef struct s_manager__		t_manager__;	// v.1. >>> tag: def->t_manager

# endif

/* -------- structs --------- */
	// ---- manager ---- //
# ifndef S_MANAGER__
#  define S_MANAGER__

// manager storage access struct.
struct s_manager__	// v.1. >>> tag: def->s_manager
{
	t_mem					mem;
	t_env					env;
	t_proc					proc;
	t_interface				interface;
};

# endif

/* ---------- size ---------- */
	// ---- manager ---- //
# ifndef SZ_MANAGER__
#  define SZ_MANAGER__

// all internal sizes used in manager module.
enum e_manager_sizes__	// v.1. >>> tag: set->e_manager_sizes_
{
	// offsets :
	manager_mem_offset__		= (0),
	manager_env_offset__		= (\
									manager_mem_offset__ \
									+ sizeof(t_mem)),
	manager_proc_offset__		= (\
									manager_env_offset__ \
									+ sizeof(t_env)),
	manager_interface_offset__	= (\
									manager_proc_offset__ \
									+ sizeof(t_proc)),
};

# endif

#endif