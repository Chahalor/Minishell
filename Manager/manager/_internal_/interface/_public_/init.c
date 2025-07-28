/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/28 11:45:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
#include "./interface.h"
#include "./types.h"

/* -----| Modules  |----- */
	//...
	
#pragma endregion Header
#pragma region Functions

// doc ...
__attribute__((always_inline, used))
//    (-internal-)
extern inline char	__interface_init(\
	t_interface *restrict const interface__
)	// v.1. >>> tag: def->visual_init
{
	return (__visual_init(&interface__->visual)
		|| __server_init(&interface__->server)
		|| __interraction_init(&interface__->interraction));
}

#pragma endregion Functions