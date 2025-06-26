/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 13:01:17 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE___C
# define WRITE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_write_buffer(\
	const unsigned char spec__,
	void *dest__,
	void *data__,
	const unsigned int len__
)	// v.1. >>> tag: def->mem_write_buffer
{
	t_mem_alloc_	*restrict	alloc__;
	void						*lwall__;
	void						*rwall__;
	unsigned int				backoff__;

	alloc__ = _mem_to_alloc(dest__);
	if (unexpect(!alloc__))
		return (mem_rewinding_failure_);
	lwall__ = &alloc__->lborder__[3];
	if (unexpect(dest__ <= lwall__))
		dest__ = alloc__->buffer__;
	rwall__ = &alloc__->rborder__[0];
	if (unexpect((void *)((char *)dest__ + len__) >= rwall__))
	{
		if (spec__ == mem_test_)
			return (mem_frontier_smashing_);
		backoff__ = (_mem_shift((unsigned char [1]){mem_rewind_}, dest__, 0) \
					- mem_alloc_offset__);
		_mem_alloc((unsigned char [1]){mem_re_}, dest__, len__, mem_string_);
		dest__ += backoff__;
	}
	if (spec__ != mem_test_)
		return (_mem_copy((unsigned char [1]){mem_raw_}, data__, \
							dest__, len__));
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_link(\
	void *dest__,
	void *data__,
	const unsigned int len__
)	// v.1. >>> tag: def->mem_link
{
	t_mem_alloc_	*restrict	base__;
	t_mem_alloc_	*restrict	node__;
	void						*temp__;
	char						code__;

	base__ = _mem_to_alloc(dest__);
	if (unexpect(!base__))
		return (mem_rewinding_failure_);
	code__ = no_error;
	node__ = _mem_to_alloc(dest__);
	if (!node__)
	{
		if (unexpect(\
				_mem_alloc((unsigned char [1]){mem_new_}, (void **)&temp__, \
							len__, mem_string_) \
					!= no_error))
			return (mem_rebasing_failure_);
		_mem_copy((unsigned char [1]){mem_raw_}, data__, temp__, len__);
		code__ = mem_untracked_data_expired_;
		node__ = _mem_to_alloc(temp__);
	}
	base__->link__ = node__;
	return (code__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_write_file(\
	void *dest__,
	void *data__,
	const unsigned int len__
)	// v.1. >>> tag: def->mem_write_file
{
	(void)dest__;
	(void)data__;
	(void)len__;
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_write(\
	const unsigned char *restrict const mode__,
	void *dest__,
	void *data__,
	const unsigned int len__
)	// v.1. >>> tag: def->mem_write
{
	return ((t_mem_write_func_ [3]){\
				_mem_write_buffer, _mem_link, _mem_write_file}[\
					mode__[0]](mode__[1], dest__, data__, len__));
}

#endif