/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:19:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/15 15:42:43 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MM_H
# define _MM_H

# pragma once

/* ************************************************************************** */
/*                                  Headers                                   */
/* ************************************************************************** */

/* -----| Systemes |----- */
# include "allowed.h"

/* -----| Globals  |----- */
//...

/* -----| Modules  |----- */
//...

/* ************************************************************************** */
/*                                  Defines                                   */
/* ************************************************************************** */

# define MM_BUCKET_SIZE		1021	/* a prim number for hashing */

/* ************************************************************************** */
/*                                  Typedefs                                  */
/* ************************************************************************** */

typedef struct s_mm_node	t_mm_node;	/* */

/* ************************************************************************** */
/*                                  Enums                                     */
/* ************************************************************************** */

enum e_mm_access
{
	mm_add,			/* request to add a pointer to the manager    */
	mm_find,		/* request to find a pointer in da bucket */
	mm_freeing,		/* request to free a pointer from the amanger */
	mm_free_all,	/* request to free the full manager         */
};

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

struct s_mm_node
{
	size_t		allocated;/* size of the allocated block  */
	void		*ptr;	/* pointer to the memory block */
	t_mm_node	*next;	/* pointer to the next node   */
};

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

// _mm.c

void		*_mm_store(
				void *restrict ptr,
				const int access
				);

// _utils.c

int			_hash(
				const void *restrict ptr
				);

extern void	*mm_memcpy(
				void *restrict dst,
				const void *restrict src,
				register const size_t n
				);

extern int	_mm_min(
				const size_t a,
				const size_t b
				);

#endif /* _MM_H */