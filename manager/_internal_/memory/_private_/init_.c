/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/19 17:41:49 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT__C
# define INIT__C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory_.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used))
// (-private-)
extern char	_mem_init(\
	void *restrict const mem
)	// v.1. >>> tag: exp->_mem_init
{
	t_reader	*reader;
	t_writer	*writer;
	char		code;

	code = __mem_init((t_mem_ *)(t_mem *)mem);
	if (unexpect(code != no_error))
		return (failed_to_setup);
	reader = &mem->reader;
	writer = &mem->writer;
	return (code | reader_setup(&reader, mem) | writer_setup(&writer, mem));
}

#endif