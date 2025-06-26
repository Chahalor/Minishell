/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/29 12:56:00 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_C
# define INIT_C

/* -------- modules --------- */
	// ---- access ----- //
# include "tokenizer.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used))
//	(-public-)
extern char	init_tokenizer(\
	t_tokenizer *restrict tokenizer
)	// v.1. >>> tag: exp->init_tokenizer
{
	return (_init_tokenizer((t_tokenizer_ *restrict)tokenizer));
}

#endif