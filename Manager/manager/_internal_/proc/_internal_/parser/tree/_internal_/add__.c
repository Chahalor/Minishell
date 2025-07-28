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
extern inline char	__tree_cmd(\
	t_mem *restrict const mem__,
	t_tree **cmd__,
	const unsigned int size__
)	// v.1. >>> tag: def->_tree_cmd
{
	void	*base__;

	if (unexpect(\
			mem__->alloc((unsigned char [1]){mem_new}, (void **)cmd__, \
						tree_size_ + size__, mem_buffer) \
			!= no_error))
		return (error);
	base__ = (void *)((char *)*cmd__ + tree_cmd_size_);
	**cmd__ = (t_tree_){
		.type__ = tree_cmd_, \
		.content__ = (t_tree_cmd_){\
			.builtin__ = FALSE, \
			.target__ = NULL, \
			.args__ = (char **)base__, \
			.redir__ = NULL \
		} \
	}
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline t_tree_	*__tree_pipe(\
	t_mem *restrict const mem__,
	const t_tree_ *const left__,
	const t_tree_ *const right__
)	// v.1. >>> tag: def->_tree_pipe
{
	t_tree_	*pipe__;

	if (unexpect(\
			mem__->alloc((unsigned char [1]){mem_new}, (void **)&pipe__, \
						tree_size_, mem_buffer) \
			!= no_error))
		return (error);
	*pipe__ = (t_tree_){
		.type__ = tree_pipe__, \
		.content__ = (t_tree_pipe_){\
			.left__ = left__, \
			.right__ = right__ \
		} \
	}
	return (pipe__);
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__tree_redir(\
	t_mem *restrict const mem__,
	t_tree *restrict const cmd__,
	const t_tree_redir_type__ type__,
	const char *restrict const target__

)	// v.1. >>> tag: def->_tree_redir
{
	t_tree__redir_	*redir__;

	if (unexpect(\
			mem__->alloc((unsigned char [1]){mem_new}, (void **)&redir__, \
						tree_redir_size_, mem_buffer) \
			!= no_error))
		return (error);
	*redir__ = (t_tree_redir_){\
		.type__ = type__, \
		.target__ = target__, \
		.next__ = NULL \
	};
	*_find_last_redir(cmd__) = redir__;
	return (no_error);
}

#endif