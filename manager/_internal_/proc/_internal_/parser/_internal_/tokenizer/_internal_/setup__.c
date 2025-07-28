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
 const char *restrict const cmd__,
	unsigned int *qty__
)	// v.2. >>> .
{
	unsigned int	size__;
	const char		opt__[2] = {mem_spec, mem_group};
	const char		*ptr__ = cmd__;
	unsigned int	len__;

	size__ = token_size_;
	while (*ptr__)
	{
		ptr__ += mem__->shift(opt__, ptr__, (char [2]){' ', '\t'});
		if ((*ptr__ == token_pipe_ || *ptr__ == token_left_ \
			|| *ptr__ == token_right_) && ++(*qty__))
		{
			len__ = ((*ptr__ == token_left_  && ptr__[1] == token_left_) \
					|| (*ptr__ == token_right_ && ptr__[1] == token_right_))
			ptr__ += 1 + len__;
			size__ += 1 + len__;
			continue ;
		}
		len__ = mem__->shift(opt__, ptr__, (char [5]){' ', '\t', token_pipe_, \
													token_left_, token_right_});
		ptr__ += len__;
		if (len__ && ++(*qty__))
            size__ += len__;
	}
	return (size__ + (++(*qty__) * token_object_size_));
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__token_setup(\
	t_token__ **token__,
	const t_mem *restrict const mem__,
	const char *restrict const cmd__
)	// v.2. >>> tag: def->_token_setup
{
	void 			*base__;
	unsigned int	size__;
	unsigned int	qty__;

	size__ = __token_size(mem__, cmd__, &qty__);
	if (unexpect(\
				mem__->alloc((unsigned char[1]){mem_new}, (void **)token__, \
							size__, mem_buffer) \
				!= no_error))
		return (error);
	base__ = (void *)((char *)*token__ + token_size_);
	(*token__)->_internal_ = (t_token__){ \
		.size__ = qty__, \
		.content__ = (t_token_object__ *)base__ \
	};
	return (no_error);
}

#endif