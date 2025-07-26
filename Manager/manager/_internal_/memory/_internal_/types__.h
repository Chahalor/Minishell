/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 14:36:33 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES___H
# define TYPES___H

# undef TYPES___H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../standards/_public_/standards.h"

/* --------- enums ---------- */
	// ---- memory ----- //
# ifndef E_MEM__
#  define E_MEM__

// all internal memory types.
enum e_mem_types__	// v.1. >>> tag: set->e_mem_types_
{
	mem_self__							= +0,
	mem_buffer__						= +1,
	mem_string__						= +2,
	mem_table__							= +3,
};

// all internal memory modes for module methods.
enum e_mem_modes__	// v.1. >>> tag: set->e_mem_types
{
	mem_base__							= +0,
	// sig :
	mem_collide__						= +0,
	mem_correspond__					= +1,
	// access :
	// ...
	// manage :
	mem_add__							= +0,
	mem_keep__							= +1,
	mem_drop__							= +2,
	// alloc :
	mem_new__							= +0,
	mem_re__							= +1,
	// clean :
	mem_buffer__						= +0,
	mem_ptr__							= +1,
	mem_all__							= +2,
	// size :
	mem_len__							= +0,
	mem_word__							= +1,
	// write :
	// mem_buffer__						= +0,
	mem_test__							= +0,
	mem_real__							= +1,
	mem_link__							= +2,
	mem_file__							= +3,
	// read :
	// mem_buffer__						= +0,
	// mem_test__						= +0,
	// mem_real__						= +1,
	// mem_file__						= +2,
	// copy :
	mem_raw__							= +0,
	mem_duplicate__						= +1,
	mem_replace__						= +2,
	// shift :
	mem_val__							= +0,
	mem_left__							= +0,
	mem_right__							= +1,
	mem_spec__							= +1,
	mem_empty__							= +0,
	mem_blank__							= +1,
	mem_plain__							= +2,
	mem_group__							= +3,
	mem_end__							= +4,
	mem_rewind__						= +2,
	// search :
	mem_data__							= +0,
	// mem_keep__						= +1,
	// mem_empty__						= +0,
	mem_free__							= +1,
	// mem_file__						= +2,
};

// all internal memory module error codes.
enum e_mem_errors__	// v.1. >>> tag: set->e_mem_errors_
{
	mem_allocation_failure__			= -9,
	mem_reallocation_failure__			= -8,
	mem_frontier_smashing__				= -7,
	mem_rebasing_failure__				= -6,
	mem_untracked_data_expired__		= -5,
	mem_rewinding_failure__				= -4,
	mem_copy_failure__					= -3,
	mem_reading_failure__				= -2,
	mem_writing_failure__				= -1,
};

# endif

/* --------- types ---------- */
	// ---- memory ----- //
# ifndef T_MEM__
#  define T_MEM__

// v.1. >>> tag: def->t_mem_alloc_
typedef struct s_mem_alloc__	t_mem_alloc__;
typedef struct s_mem__			t_mem__;		// v.1. >>> tag: def->t_mem

# endif

/* -------- structs --------- */
	// ---- memory ----- //
# ifndef S_MEM__
#  define S_MEM__

// allocation meta data.
struct s_mem_alloc__	// v.1. >>> .
{
	unsigned int	size__;			// allocated size for this buffer.
	unsigned char	type__;			// copy type of this buffer.
	unsigned char	lborder__[4];	// left border security padding.
	void			*buffer__;		// buffer pointer.
	unsigned char	rborder__[4];	// right border security padding.
	t_mem_alloc__	*link__;		// link to another area for some operations.
	/*
	 * Here you shall note have more than one link (for optimisation purposes)
	 * Also because a chained list isn't the purpose of this.
	*/
	unsigned int	id__;			// allocation id.
};
// memory management access struct.
struct s_mem__			// v.1. >>> def: def->s_mem
{
	unsigned int	total__;		// total memory actually allocated.
	unsigned int	size__;			// size of the access list (in ptr).
	unsigned int	index__;		// current index to assign.
	unsigned int	*free__;		// pool free space size.
	void			**pool__;		// free space pool.
	void			**access__;		// all allocated pointers.
};

# endif

/* ---------- size ---------- */
	// ---- memory ----- //
# ifndef SZ_MEM__
#  define SZ_MEM__

// all internal sizes used in memory module.
enum e_mem_sizes__	// v.1. >>> tag: set->e_mem_sizes
{
	// sizes :
	mem_alloc_size__	= (\
							sizeof(t_mem_alloc__)),
	// offsets :
	/*
	 * offsets in both way either start from buffer or just after a wall
	 * (security border).
	*/
	// back :
	mem_size_offset__	= (\
							(1 * sizeof(unsigned char)) \
							+ sizeof(unsigned int)),
	mem_alloc_offset__	= (\
							mem_size_offset__ \
							+ (4 * sizeof(unsigned char))),
	// to :
	mem_buffer_offset__	= (0),
	mem_id_offset__		= (\
							sizeof(void *)),
	mem_free_offset__	= (0),
	mem_pool_offset__	= (\
							mem_free_offset__ \
							+ (2 * sizeof(unsigned int))),
};

# endif

#endif