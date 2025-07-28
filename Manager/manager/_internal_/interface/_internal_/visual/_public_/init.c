/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/28 11:36:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif /* _GNU_SOURCE */

#pragma region Header
/* -----| Internals |----- */
#include "../_private_/visual_.h"
#include "./visual.h"
#include "./types.h"

/* -----| Modules  |----- */
	//...

#pragma endregion Header
#pragma region Functions

// doc ...
__attribute__((always_inline, used))
//    (-internal-)
extern inline char	__visual_init(\
	t_visual *restrict const visual__
)	// v.1. >>> tag: def->visual_init
{
	visual__->printf = ft_printf;
	visual__->fprintf = ft_fprintf;
	visual__->sprintf = ft_sprintf;
	visual__->perror = ft_perror;
	return (0);
}

#pragma endregion Functions