/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:12:56 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/28 11:17:34 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./type.h"
#include "./interraction.h"

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__interactions_setup(\
	t_interactions *restrict const interactions__
)	// v.1. >>> tag: def->env_init
{
	interactions__->read_line = read_line;
}