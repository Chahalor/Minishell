/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/07/28 12:15:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPEND___C
# define EXPEND___C

/* -------- modules --------- */
	// ---- access ----- //
# include "env__.h"
# include "standards.h"

/* -------- inlines --------- */

static inline char	*_get_var(
	const char *restrict const str,
)
{
	const t_mem *restrict const	mem = _manager()->mem;
	register int				i;
	char						*var;

	i = -1;
	while (str[++i] && str[i] != ' ')
		;
	mem.alloc((unsigned char [1]{mem_alloc}), (void **)&var, i + 1);
	if (unexpect(!var))
		return (NULL);
	mem.copy((unsigned char [1]{mem_copy}), var, str, i);
	var[i] = '\0';
	return (var);
}

__attribute__((always_inline, used))
// (-internal-)
extern inline t_env_	*__env_expend(\
	t_env_	*restrict const new__,
	const char	*restrict const str
)	// v.1. >>> tag: def->_env_expend
{
	register int	i;
	char			*var;

	if (unexpect(!new__ || !str))
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '$')
		{
			var = _get_var(str + i + 1);
			if (unexpect(!var))
				return (NULL);
			
		}
	}
}

#endif