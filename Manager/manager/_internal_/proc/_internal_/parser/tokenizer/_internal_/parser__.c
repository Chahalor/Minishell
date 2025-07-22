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
	if (*word__ == token_left_ || *word__ == token_right_ \
		|| *word__ == token_pipe_)
	{
		token__->content__[index__].type__ = *word__;
		token__->content__[index__].content__[0] = *word__;
		++word__;
		if (*word__ == token_left_ || *word__ == token_right_)
		{
			token__->content__[index__].type__ += *word__;
			token__->content__[index__].content__[1] = *word__;
		}
		return (TRUE);
	}
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline void	__token_parse(\
	t_token_ *restrict const token__,
	const t_mem *restrict const mem__,
	const char **argv__,
	const unsigned int argc__
)	// v.1. >>> tag: def->_token_parse
{
	register char			*word__;
	unsigned int			len__;
	register unsigned int	i__;
	register unsigned int	j__;

	i__ = 0;
	j__ = 0;
	while (i__ != argc__)
	{
		word__ = argv__[i__++];
		if (__token_parse_separator(token__, word__, j__))
			++j__;
		else
		{
			len__ = mem__->size((unsigned char [2]){mem_word}, word__, \
						(char [3]){token_left_, token_right_, token_pipe_});
			mem__->copy((unsigned char [1]){mem_raw}, word__, \
						token__->content__[j__].content__, len__);
			token__->content__[j__++].type__ = token_word_;
		}
	}
	token__->content__[j__].type__ = token_eof_;
}

#endif