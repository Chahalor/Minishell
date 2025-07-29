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

#ifndef CD___C
# define CD___C

/* -------- modules --------- */
	// ---- access ----- //
# include "builtin__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_builtin_cd_	__builtin_cd_parser(\
	t_mem *restrict const mem__,
	const char **args__
)	// v.1. >>> tag: def->_builtin_cd
{
	t_builtin_cd_	options__;

	options__ = (t_builtin_cd_){0};
	if (unexpect(!args__ || !*args__))
		return (options__);
	else if (unexpect(args__[1]))
		options__.error__ = builtin_too_many_args_;
	else if (!*args__)
		options__.home__ = TRUE;
	else if (*args__[0] = '-' && !*args__[1])
		options__.pwd__ = TRUE;
	else if (mem__->compare(args__[0], "--help", 7)
			|| mem__->compare(args__[0], "-h", 3))
		options__.help__ = TRUE;
	return (options__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	*__builtin_cd(\
	t_visual *restrict const visual__,
	const char **args__
)	// v.1. >>> tag: def->_builtin_cd
{
	t_builtin_cd_	options__;
	char			*dest__;
	char			error__;

	options__ = _builtin_cd_parser(args__);
	if (unexpect(options__.help__))
		return (visual__->printf(\
					BLUE "Usage:" RESET " cd [options] [dir]\n"
					YELLOW "Options:\n" RESET
					"  -, \t\tChange to the last directory\n"
					"  -h, --help\t\tDisplay this help and exit\n"));
	else if (unexpect(opts.error))
		return (_error(opts.error, NULL));
	// ...
}

#endif