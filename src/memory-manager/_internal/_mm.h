/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:19:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/12 12:21:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MM_H
# define _MM_H

# pragma once

/* ************************************************************************** */
/*                                  Headers                                   */
/* ************************************************************************** */

/* -----| Systemes |----- */
# include <stdlib.h>
# include <stdio.h>

/* -----| Globals  |----- */
//...

/* -----| Modules  |----- */
//...

/* ************************************************************************** */
/*                                  Defines                                   */
/* ************************************************************************** */

# define MM_BUCKET_SIZE		1024	/**/

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
	mm_freeing,		/* reuest to free a pointer from the amanger */
	mm_free_all,	/* request to free the full manager         */
	mm_reallocing,	/* request to realloc a pointer (not implemented) */
};

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

struct s_mm_node
{
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
				const register size_t n
				);

#endif /* _MM_H */