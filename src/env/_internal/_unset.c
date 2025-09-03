/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _unset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:11:21 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/03 10:08:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "_env.h"

static inline int	__cmp(
	const char *const restrict s1,
	const char *const restrict s2
)
{
	register int	__i;

	if (_UNLIKELY(!s1 || !s2))
		return (0);
	__i = 0;
	while (s1[__i] && s2[__i] && s1[__i] == s2[__i])
		++__i;
	return (s1[__i] - s2[__i]);
}

extern inline void	*_env_unset(
	t_env *env,
	void *data
)
{
	const char	*_data = (const char *)data;
	t_env_node	*_current;
	t_env_node	*_prev;

	_current = env->nodes;
	_prev = NULL;
	while (_current)
	{
		if (__cmp(_current->key, _data) == 0)
		{
			if (_prev)
				_prev->next = _current->next;
			else
				env->nodes = _current->next;
			mm_free(_current);
			--env->nb_node;
			return (_prev);
		}
		_prev = _current;
		_current = _current->next;
	}
	return (NULL);
}
