/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 14:37:28 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# undef TYPES_H
# pragma once

/* -------- modules --------- */
	// ---- public ----- //
# include "memory.h"

/* --------- enums ---------- */
	// ---- memory ----- //
# ifndef E_MEM
#  define E_MEM

// all public memory types.
enum e_mem_types__	// v.1. >>> tag: exp->e_mem_types
{
	mem_self		= mem_self__,
	mem_buffer		= mem_buffer__,
	mem_string		= mem_string__,
	mem_table		= mem_table__,
};

// all public memory modes for module methods.
enum e_mem_modes	// v.1. >>> tag: exp->e_mem_types
{
	mem_base		= mem_base__,
	mem_new			= mem_new__,
	mem_re			= mem_re__,
	mem_buffer		= mem_buffer__,
	mem_ptr			= mem_ptr__,
	mem_all			= mem_all__,
	mem_len			= mem_len__,
	mem_word		= mem_word__,
	mem_test		= mem_test__,
	mem_real		= mem_real__,
	mem_link		= mem_link__,
	mem_file		= mem_file__,
	mem_raw			= mem_raw__,
	mem_duplicate	= mem_duplicate__,
	mem_replace		= mem_replace__,
	mem_val			= mem_val__,
	mem_left		= mem_left__,
	mem_right		= mem_right__,
	mem_spec		= mem_spec__,
	mem_empty		= mem_empty__,
	mem_blank		= mem_blank__,
	mem_plain		= mem_plain__,
	mem_group		= mem_group__,
	mem_end			= mem_end__,
	mem_data		= mem_data__,
	mem_free		= mem_free__,
};

# endif

/* --------- types ---------- */
	// ---- memory ----- //
# ifndef T_MEM
#  define T_MEM

typedef struct s_mem	t_mem;	// v.1. >>> tag: exp->t_mem

# endif

/* -------- structs --------- */
	// ---- memory ----- //
# ifndef S_MEM
#  define S_MEM

// memory module access struct.
struct s_mem	// v.1. >>> tag: exp->s_mem
{
	// data :
	char			_internal_[sizeof(t_mem__)];
	t_reader		reader;
	t_writer		writer;
	// >>>
	// access :
	char			(*alloc)(\
							const unsigned char *restrict const, \
							void **, \
							const unsigned int, \
							const unsigned char);
	char			(*clean)(\
							const unsigned char *restrict const, \
							const char, \
							void *, \
							const unsigned int);
	unsigned int	(*size)(\
							const unsigned char *restrict const, \
							void *, \
							const char);
	void			*(*section)(\
							void **, \
							const unsigned int);
	char			(*write)(\
							const unsigned char *restrict const, \
							void *, \
							void *, \
							const unsigned int);
	char			(*read)(\
							const unsigned char *restrict const, \
							void *, \
							void *, \
							const unsigned int);
	char			(*copy)(\
							const unsigned char *restrict const, \
							void *, \
							void *, \
							const unsigned int);
	unsigned int	(*shift)(\
							const unsigned char *restrict const, \
							void *restrict const, \
							const unsigned int);
	char			(*compare)(\
							const char *const, \
							const char *const, \
							unsigned int *);
	int				(*search)(\
							const unsigned char *restrict const, \
							const void *restrict const, \
							const void *restrict const);
};

# endif

/* ---------- size ---------- */
	// ---- memory ----- //
# ifndef SZ_MEM
#  define SZ_MEM

// all public sizes used in memory module.
enum e_mem_sizes	// v.1. >>> tag: exp->e_mem_sizes
{
	// sizes :
	mem_size			= (\
							sizeof(t_mem)),
};

# endif

#endif