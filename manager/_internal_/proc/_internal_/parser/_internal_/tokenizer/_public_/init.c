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

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-public-)
extern char	token_init(\
	t_token *restrict const token
)	// v.1. >>> tag: exp->token_init
{
	return (__token_init(token));
}

#endif