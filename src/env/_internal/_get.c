/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _get.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:11:21 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/04 14:08:27 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "_env.h"

extern sig_atomic_t	g_last_signal;	/* Global signal variable */

extern inline void	*_env_find(
	t_env *env,
	char *str,
	const int mode
)
{
	t_env_node	*current;

	if (ft_strncmp("?", str, 1) == 0)
		return (ft_itoa(g_last_signal));
	else if (ft_strncmp("~", str, 1) == 0)
		return (env_find("HOME"));
	current = env->nodes;
	while (current)
	{
		if (ft_strlen(current->key) == ft_strlen(str)
			&& !ft_strncmp(current->key, str, ft_strlen(str)))
		{
			if (mode)
				return (current);
			else
				return (current->value);
		}
		current = current->next;
	}
	return (NULL);
}

static inline void	__cpy(
	char **result,
	t_env_node *_current,
	int _i
)
{
	ft_memcpy(result[_i], _current->key, ft_strlen(_current->key));
	if (_current->value)
		result[_i][ft_strlen(_current->key)] = '=';
	ft_memcpy(&result[_i][ft_strlen(_current->key) + 1],
		_current->value, ft_strlen(_current->value) + 1);
}

extern inline void	*_env_getall(
	t_env *env,
	const int mode
)
{
	char			**result;
	t_env_node		*_current;
	register int	_i;

	result = mm_alloc(sizeof(char *) * (env->nb_node + 1));
	if (_UNLIKELY(!result))
		return (NULL);
	_current = env->nodes;
	_i = -1;
	while (_current)
	{
		if (!_current->value && !mode)
		{
			_current = _current->next;
			continue ;
		}
		result[++_i] = mm_alloc(ft_strlen(_current->key)
				+ ft_strlen(_current->value) + 2);
		if (_UNLIKELY(!result[_i]))
			return (free_tab(result), NULL);
		__cpy(result, _current, _i);
		_current = _current->next;
	}
	return (result);
}
