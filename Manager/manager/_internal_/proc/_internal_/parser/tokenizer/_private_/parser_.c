/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/29 12:53:06 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_C
# define TOKENIZER_C

/* -------- modules --------- */
	// ---- access ----- //
# include "tokenizer.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-public-)
extern char	tokenize(\
	char *command
)	// v.1. >>> tag: exp->tokenize
{
	t_manager_	*restrict	manager;

	manager = get_manager(NULL);
	return (_tokenize(\
				(t_tokenizer_ *restrict const)&manager->proc._tokenizer, \
				(const t_env *restrict const)&manager->env, \
				command));
}

#endif