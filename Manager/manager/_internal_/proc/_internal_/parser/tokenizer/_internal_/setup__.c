/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 15:42:05 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP___C
# define SETUP___C

/* -------- modules --------- */
	// ---- access ----- //
# include "tokenizer__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-) x (-local-)
static inline unsigned int	__token_size(\
	const t_mem *restrict const mem__,
	const char **argv__,
	const unsigned int argc__,
	unsigned int *qty__
)	// v.1. >>> tag: def->_token_size
{
	register char			*word__;
	unsigned int			size__;
	unsigned int			len__;
	register unsigned int	i__;
	register unsigned int	j__;

	size__ = token_size_;
	i__ = 0;
	j__ = 0;
	while (i__ != argc__)
	{
		len__ = mem__->size((unsigned char [1]){mem_len}, \
							argv__[i__], (unsigned char [1]){'\0'});
		size__ += len__;
		while (len__ > 0 && ++j__)
			len__ -= mem__->size((unsigned char [2]){mem_word}, argv__[i__], \
							(char [3]){token_left_, token_right_, token_pipe_});
		++i__;
	}
	return (size__ + (j__ * token_object_size_));
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__token_setup(\
	t_token__ **token__,
	const t_mem *restrict const mem__,
	const char **argv__,
	const unsigned int argc__
)	// v.1. >>> tag: def->_token_setup
{
	void					*base__;
	unsigned int			size__;
	unsigned int			qty__;

	size__ = __token_size(mem__, argv__, argc__, &qty__);
	if (unexpect(\
			mem__->alloc((unsigned char [1]){mem_new}, (void **)token__, \
						size__, mem_buffer)
			!= no_error))
		return (error);
	base__ = (void *)((char *)token__ + token_size_);
	*token__->_internal_ = (t_token__){\
		.size__ = qty__, \
		.content__ = (t_token_object__ *)base__ \
	};
	return (no_error);
}

#endif