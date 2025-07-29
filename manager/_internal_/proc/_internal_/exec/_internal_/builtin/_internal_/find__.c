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

#ifndef FIND___C
# define FIND___C

/* -------- modules --------- */
	// ---- access ----- //
# include "builtin__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_builtin_call_	*__builtin_find(\
	t_mem *restrict const mem__,
	const char *restrict const name__
)	// v.1. >>> tag: def->_builtin_find
{
	static t_builtin_call_	builtin__[9] = {\
											{"cd", _builtin_cd},
											{"exit", _builtin_exit},
											{"env", _builtin_env},
											{"pwd", _builtin_pwd},
											{"echo", _builtin_echo},
											{"export", _builtin_export},
											{"unset", _builtin_unset},
											{"history", _builtin_history},
											{NULL, NULL}};
	char					*cmd__;
	register unsigned int	i__;
	unsigned int			size__;

	cmd__ = builtin__[0].name__;
	i__ = 0;
	while (cmd__)
	{
		size__ = mem__->size((unsigned char [1]){mem_len}, cmd__, 0);
		if (unexpect(mem__->compare(cmd__, name__, &size__)))
			return (&builtin__[i__]);
		cmd__ = builtin__[i__++].name__;
	}
	return (NULL);
}

#endif