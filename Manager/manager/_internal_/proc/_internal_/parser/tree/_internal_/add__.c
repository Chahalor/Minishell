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

#ifndef ADD___C
# define ADD___C

/* -------- modules --------- */
	// ---- access ----- //
# include "tree__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline t_tree	*__tree_cmd(\
	t_mem *restrict const mem__,
	const char *restrict const target__,
	const char *restrict *restrict const args__
)	// v.1. >>> tag: def->tree_cmd
{
	t_tree_	*cmd__;

	if (unexpect(\
			mem__->alloc((unsigned char [1]){mem_new}, (void **)&cmd__, \
						tree_size_, mem_buffer) \
			!= no_error))
		return (error);
	*cmd__ = (t_tree_){
		.type__ = tree_cmd_, \
		.content__ = (t_tree_cmd_){\
			.builtin__ = TRUE, \ // placeholder as we'll need a function to determine that.
			.target__ = target__, \
			.args__ = args__, \
			.redir__ = NULL \
		} \
	}
	return (cmd__);
}


#endif