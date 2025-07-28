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

#ifndef PARSE___C
# define PARSE___C

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
	const t_token *restrict const token__
)	// v.1. >>> tag: def->_tree_parse_redir
{
	char					*target__;
	t_token_object			*tok__;
	t_token_type			tok_type__;
	t_tree_redir_type_		redir_type__;

	tok__ = token__->fetch(token_actual);
	tok_type__ = tok__->type__;
	while (tok_type__ != token_left && tok_type__ != token_right \
		&& tok_type__ != token_dleft && tok_type__ != token_dright)
	{
		tok_type__ = tok__->type__;
		redir_type__ = (tree_in_ * (tok_type__ == token_left) \
						+ tree_out_ * (tok_type__ == token_right) \
						+ tree_air_ * (tok_type__ == token_dleft) \
						+ tree_add_ * (tok_type__ == token_dright));
		if (unexpect(tok_type__ != token_word \
				|| (_tree_redir(cmd__, redir_type__, tok__->content__) \
				!= no_error)))
			return (error);
		tok__ = token__->fetch(token_next);
	}
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline t_tree_	*__tree_parse_cmd(\
	t_mem *restrict const mem__,
	const t_token *restrict const token__
)	// v.1. >>> tag: def->_tree_parse_cmd
{
	t_tree_			*cmd__;
	t_token_object	*tok__;
	register int	size__;

	size__ = _tree_size(token__);
	if (unexpect(size < 0 \
			|| (_tree_cmd(&cmd__, size__) != no_error)
			|| (_tree_parse_redir(cmd__, token__) != no_error)))
		return (NULL);
	size__ = 0;
	tok__ = token__->fetch(token_actual);
	while (tok__->type__ == token_word)
	{
		if (unexpect(!size__ && ++size__))
			*cmd__->content__.cmd__ = (t_tree_cmd_){\
				_tree_builtin(tok__->content__), tok__->content__, \
				tok__->args__, tok__->redir__};
		else
		{
			cmd__->content__.cmd__.args__[size__++ - 1] = tok__->content__;
			if (unexpect(_tree_parse_redir(cmd__, token__) != no_error))
				return (NULL);
		}
		tok__ = token__->fetch(token_next);
	}
	return (cmd__);
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline t_tree_	*__tree_parse(\
	const t_token *restrict const token__
)	// v.1. >>> tag: def->_tree_parse
{
	t_tree_		*left__;
	t_tree_		*right__;

	left__ = _tree_parse_cmd(token__);
	if (unexpect(!left__))
		return (NULL);
	else if (token__->fetch(token_actual)->type__ == token_pipe)
	{
		right__ = _tree_parse(token__);
		if (unexpect(!right__))
			return (NULL);
		return (_tree_pipe(left__, right__));
	}
	return (left__);
}

#endif