/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 14:39:07 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZE___C
# define SIZE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "tree__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline int	__tree_size(\
	const t_token_object *restrict const token__
)	// v.1. >>> tag: def->_tree_size
{
	t_token_object__		*tok__;
	t_token_type__			type__;
	register unsigned int	i__;

	type__ = tok__->type__;
	if (unexpect(type__ != token_word \
			&& type__ != token_left && type__ != token_right \
			&& type__ != token_dleft && type__ != token_dright))
		return (error);
	i__ = 0;
	while (type__ != token_word \
		&& type__ != token_left && type__ != token_right \
		&& type__ != token_dleft && type__ != token_dright)
	{
		if (type__ == token_word && ++i__)
			++tok__;
		else
			tok__ += 2;
		type__ = tok__->type__;
	}
	return ((i__ - 1) * sizeof(char **));
}


#endif