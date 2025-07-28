/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 15:06:11 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL__C
# define VISUAL__C

/* -------- modules --------- */
	// ---- access ----- //
# include "visual_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern int	_visual_printf(\
	const char *const restrict format_,
	...
)	// v.1. >>> tag: exp->_visual_printf
{
	va_list	args_;

	va_start(args_, format_);
	return (__visual_printf((t_visual__ *)&_visual_self()->_internal_, \
							format_, args_));
}

// doc ...
__attribute__((hot, used))
// (-private-)
extern int	_visual_rprintf(\
	const char *const restrict format_,
	...
)	// v.1. >>> tag: exp->_visual_rprintf
{
	va_list	args_;

	va_start(args_, format_);
	return (__visual_rprintf((t_visual__ *)&_visual_self()->_internal_, \
							format_, args_));
}

// doc ...
__attribute__((hot, used))
// (-private-)
extern int	_visual_fprintf(\
	const int fd_,
	const char *const restrict format_,
	...
)	// v.1. >>> tag: exp->_visual_fprintf
{
	va_list	args_;

	va_start(args_, format_);
	return (__visual_fprintf((t_visual__ *)&_visual_self()->_internal_, \
							fd_, format_, args_));
}

// doc ...
__attribute__((hot, used))
// (-private-)
extern int	_visual_sprintf(\
	char *const restrict buffer_,
	const char *const restrict format_,
	...
)	// v.1. >>> tag: exp->_visual_sprintf
{
	va_list	args_;

	va_start(args_, format_);
	return (__visual_sprintf((t_visual__ *)&_visual_self()->_internal_, \
							buffer_, format_, args_));
}

// doc ...
__attribute__((hot, used))
// (-private-)
extern char	_visual_perror(\
	const char *const restrict format_,
	...
)	// v.1. >>> tag: exp->_visual_perror
{
	va_list	args_;

	va_start(args_, format_);
	return (__visual_perror((t_visual__ *)&_visual_self()->_internal_, \
							format_, args_));
}

#endif