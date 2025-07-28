/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 15:45:12 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER___C
# define PARSER___C

/* -------- modules --------- */
	// ---- access ----- //
# include "tokenizer__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-) x (-local-)
static inline char	__token_parse_separator(\
	t_token_ *restrict const token__,
	const char *word__,
	const unsigned int index__
)	// v.1. >>> .
{
	t_token_object__	*token__;

	if (*word__ == token_left_ || *word__ == token_right_ \
		|| *word__ == token_pipe_)
	{
		token__ = &token__->content__[index__];
		token__->type__ = *word__;
		token__->content__[0] = *word__;
		token__->content__[1] = '\0';
		if (*word__ == token_pipe_)
			return (1);
		else if (word__[1] == *word__)
		{
			token__->type__ += word__[1];
			token__->content__[1] = word__[1];
			token__->content__[2] = '\0';
			return (2);
		}
		return (1);
	}
	return (0);
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline void	__token_parse(\
	t_token_ *restrict const token__,
	const t_mem *restrict const mem__,
	const char *restrict const cmd__
)	// v.1. >>> tag: def->_token_parse
{
	const char		opt__[2] = {mem_spec, mem_group};
	const char		*ptr__ = cmd__;
	unsigned int	len__;
	unsigned int	i__;

	i__ = 0;
	while (*ptr__)
	{
		ptr__ += mem__->shift(opt__, ptr__, (char [2]){' ', '\t'});
		len__ = __token_parse_separator(token__, ptr__, i__);
		if (len__ && ++i__)
		{
			ptr__ += len__;
			continue ;
		}
		len__ = mem__->shift(opt__, ptr__, (char [5]){' ', '\t', token_pipe_, \
													token_left_, token_right_});
		if (len__)
		{
			mem__->copy((unsigned char[1]){mem_raw}, start, \
						token__->content__[i__].content__, len__);
			token__->content__[i__++].type__ = token_word_;
		}
	}
	token__->content__[i__] = NULL;
}

#endif