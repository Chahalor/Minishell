/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/07/28 10:35:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES__H
# define TYPES__H

# undef TYPES__H
# pragma once

/* -------- modules --------- */
	// ---- private ---- //
# include "memory_.h"

/* --------- enums ---------- */
	// ---- memory ----- //
# ifndef E_MEM_
#  define E_MEM_

// all private memory types.
enum e_mem_types_	// v.1. >>> tag: exp->e_mem_types_
{
	mem_buffer_						= mem_buffer__,
	mem_string_						= mem_string__,
	mem_table_						= mem_table__,
};

// all private memory modes for module methods.
enum e_mem_modes_	// v.1. >>> .
{
	mem_base_						= mem_base__,
	mem_collide_					= mem_collide__,
	mem_correspond_					= mem_correspond__,
	mem_add_						= mem_add__,
	mem_keep_						= mem_keep__,
	mem_drop_						= mem_drop__,
	mem_new_						= mem_new__,
	mem_re_							= mem_re__,
	mem_buffer_						= mem_buffer__,
	mem_ptr_						= mem_ptr__,
	mem_all_						= mem_all__,
	mem_len_						= mem_len__,
	mem_word_						= mem_word__,
	mem_test_						= mem_test__,
	mem_real_						= mem_real__,
	mem_link_						= mem_link__,
	mem_file_						= mem_file__,
	mem_raw_						= mem_raw__,
	mem_duplicate_					= mem_duplicate__,
	mem_replace_					= mem_replace__,
	mem_val_						= mem_val__,
	mem_left_						= mem_left__,
	mem_right_						= mem_right__,
	mem_spec_						= mem_spec__,
	mem_empty_						= mem_empty__,
	mem_blank_						= mem_blank__,
	mem_plain_						= mem_plain__,
	mem_group_						= mem_group__,
	mem_end_						= mem_end__,
	mem_rewind_						= mem_rewind__,
	mem_data_						= mem_data__,
	mem_free_						= mem_free__,
};

// all private memory module error codes.
enum e_mem_errors_	// v.1. >>> tag: exp->e_mem_errors_
{
	mem_allocation_failure_			= mem_allocation_failure__,
	mem_reallocation_failure_		= mem_reallocation_failure__,
	mem_frontier_smashing_			= mem_frontier_smashing__,
	mem_rebasing_failure_			= mem_rebasing_failure__,
	mem_untracked_data_expired_		= mem_untracked_data_expired__,
	mem_rewinding_failure_			= mem_rewinding_failure__,
	mem_copy_failure_				= mem_copy_failure__,
	mem_reading_failure_			= mem_reading_failure__,
	mem_writing_failure_			= mem_writing_failure__,
};

# endif

/* --------- types ---------- */
	// ---- memory ----- //
# ifndef T_MEM_
#  define T_MEM_

// v.1. >>> tag: exp->t_mem_alloc_
typedef t_mem_alloc__	t_mem_alloc_;
typedef struct s_mem_	t_mem_;								// v.1. >>> .
typedef unsigned int	(*t_mem_format_func_)(\
							const t_mem__ * restrict const, \
							void *, \
							const unsigned int);			// v.1. >>> .
typedef char			(*t_mem_alloc_func_)(\
							void **, \
							const unsigned int, \
							const unsigned char);			// v.1. >>> .
typedef char			(*t_mem_clean_func_)(\
							const char, \
							void *, \
							const unsigned int);			// v.1. >>> .
typedef unsigned int	(*t_mem_size_func)(\
							void *, \
							const char);					// v.1. >>> .
typedef char			(*t_mem_write_func_)(\
							const unsigned char, \
							void *, \
							void *, \
							const unsigned int);			// v.1. >>> .
typedef char			(*t_mem_read_func_)(\
							const unsigned char, \
							void *, \
							void *, \
							const unsigned int);			// v.1. >>> .
typedef char			(*t_mem_copy_func_)(\
							void *, \
							void *, \
							const unsigned int);			// v.1. >>> .
typedef unsigned int	(*t_mem_shift_func_)(\
							const unsigned char *restrict const, \
							void *restrict const, \
							char *restrict const);			// v.1. >>> .
typedef int				(*t_mem_search_func_)(\
							const unsigned char, \
							const void *restrict const, \
							const void *restrict const);	// v.1. >>> .

# endif

/* -------- structs --------- */
	// ---- memory ----- //
# ifndef S_MEM_
#  define S_MEM_

// private memory module access struct.
struct s_mem_	// v.1. >>> .
{
	// data :
	char			_internal_[sizeof(t_mem__)];
	t_reader		reader_;
	t_writer		writer_;
	// >>>
	// access :
	char			(*alloc_)(\
							const unsigned char *restrict const, \
							void **, \
							const unsigned int, \
							const unsigned char);
	char			(*clean_)(\
							const unsigned char *restrict const, \
							const char, \
							void *, \
							const unsigned int);
	unsigned int	(*size_)(\
							const unsigned char *restrict const, \
							void *, \
							const char);
	void			*(*section_)(\
							void **, \
							const unsigned int);
	char			(*write_)(\
							const unsigned char *restrict const, \
							void *, \
							void *, \
							const unsigned int);
	char			(*read_)(\
							const unsigned char *restrict const, \
							void *, \
							void *, \
							const unsigned int);
	char			(*copy_)(\
							const unsigned char *restrict const, \
							void *, \
							void *, \
							const unsigned int);
	unsigned int	(*shift_)(\
							const unsigned char *restrict const, \
							void *restrict const, \
							const unsigned int);
	char			(*compare_)(\
							const char *const, \
							const char *const, \
							unsigned int *);
	int				(*search_)(\
							const unsigned char *restrict const, \
							const void *restrict const, \
							const void *restrict const);
};

# endif

#endif