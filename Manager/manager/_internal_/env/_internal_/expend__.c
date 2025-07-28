/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/07/28 15:43:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPEND___C
# define EXPEND___C

/* -------- modules --------- */
	// ---- access ----- //
# include "env__.h"
# include "standards.h"

/* -------- inlines --------- */

static inline void	*_expand(
	const int i,
	const t_mem *restrict const _mem,
	void **_result,
)
{
	char	*var;
	char	*expanded;

	var = _get_var(str + i);
	if (unexpect(!var))
		return (NULL);
	expanded = env__->find_(var);
	_mem.write((unsigned char [1]{mem_write}), result, expanded,
				_mem.size((unsigned char [1]{mem_size}), expanded,
				mem_string_));
	_mem.clean((unsigned char [1]{mem_free}), none, var, 0);
}

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
extern inline t_env_	*__env_expend(
	t_env_	*restrict const env__,
	const char	*restrict const str
)	// v.1. >>> tag: def->_env_expend
{
	const t_mem *restrict const	_mem = _manager()->mem;
	register int				i;
	char						*result;

	if (unexpect(!new__ || !str))
		return (NULL);
	result = _mem.alloc((unsigned char [1]{mem_alloc}),(void **)&result, 64,
						mem_string_);
	if (unexpect(!result))
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '$')
		{
			if (unexpect(!_expand(++i, _mem, &result)))
				return (_mem.clean((unsigned char [1]{mem_free}),
						none, result, 0), NULL);
		}
		else
			_mem.write((unsigned char [1]{mem_write}), result, str + i, 1);
	}
	return (result);
}

#endif