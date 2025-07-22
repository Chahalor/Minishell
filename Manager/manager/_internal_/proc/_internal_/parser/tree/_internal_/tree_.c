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

#ifndef TREE___C
# define TREE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "tree__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__tree_parse_redir(\
	t_mem *restrict const mem__,
	t_tree_ *restrict const cmd__,
	const t_token__ *restrict const token__,
	const unsigned int index__
)	// v.1. >>> tag: def->_tree_parse_redir
{
	// ...
}

// TODO: split out this shit :

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline t_tree_	*__tree_parse_cmd(\
	t_mem *restrict const mem__,
	const t_token__ *restrict const token__,
	const unsigned int index__
)	// v.1. >>> tag: def->_tree_parse_cmd
{
	t_tree_					*cmd__;
	t_token_object__		*tok__;
	t_token_type__			type__;
	char					*args__;
	register unsigned int	len__;

	tok__ = &token__->content__[index__];
	type__ = tok__->type__;
	if (unexpect(type__ != token_word \
			&& type__ != token_left && type__ != token_right \
			&& type__ != token_dleft && type__ != token_dright))
		return (NULL);
	while (type__ != token_word \
		&& type__ != token_left && type__ != token_right \
		&& type__ != token_dleft && type__ != token_dright)
	{
		if (type__ == token_word && ++len__)
			++tok__;
		else
			tok__ += 2;
	}
	if (unexpect(\
			mem__->alloc((unsigned char [1]){mem_new}, (void **)&args__, \
						len__ * sizeof(char **), mem_buffer) \
			!= no_error))
		return (error);
	cmd__ = _tree_cmd(NULL, &args);
	if (unexpect(!cmd__))
		return (NULL);
	return (cmd__);
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline t_tree_	*__tree(\
	t_tree_ *restrict const tree__,
	t_mem *restrict const mem__,
	const t_token__ *restrict const token__
)	// v.1. >>> tag: def->tree
{
	t_tree_					*left__;
	t_tree_					*right__;
	register unsigned int	i__;

	t_token_object_			tok__;

	left__ = 
	i__ = 0;
	while (i__ != token__->size__)
	{
		if (token__->content__[i__].type__ == token_word)
			cmd__ = _tree_cmd()
		++i__;
	}
}

#endif