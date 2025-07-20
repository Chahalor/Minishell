/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:49:54 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE__C
# define WRITE__C

/* -------- modules --------- */
	// ---- access ----- //
# include "writer_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_writer_proc(\
	const char *target_,
	const char *buffer_
)	// v.1. >>> tag: exp->_writer_proc
{
	t_mem			*mem_;
	int				fd_;
	unsigned int	size_;

	mem_ = (t_mem *)&manager()->mem;
	if (unexpect(\
			mem_->reader.find((unsigned char [1]){reader_file}, \
							target_, (void **)&fd_) \
			!= no_error))
		return (error);
	size_ = mem_->size((unsigned char [1]){mem_len}, buffer_, 0);
	return (__writer_proc(fd_, buffer_, size_));
}

#endif