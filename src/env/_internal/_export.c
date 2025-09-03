/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _export.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:44:41 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/03 11:22:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_env.h"

static inline void	__free_node(
	t_env_node *const restrict node
)
{
	if (_LIKELY(node != NULL))
	{
		mm_free(node->key);
		mm_free(node->value);
		mm_free(node);
	}
}

static inline void	*__env_new_export(
	t_env *const restrict env,
	char **_data
)
{
	const int	_key_len = ft_strlen(_data[0]);
	const int	_val_len = ft_strlen(_data[1]);
	t_env_node	*current;

	current = mm_alloc(sizeof(t_env_node));
	if (_UNLIKELY(!current))
		return (NULL);
	current->key = mm_alloc(_key_len + 1);
	current->value = mm_alloc(_val_len + 1);
	if (_UNLIKELY(!current->key || !current->value))
		return (__free_node(current), NULL);
	ft_memcpy(current->key, _data[0], _key_len + 1);
	if (!_data[1])
		current->value = NULL;
	else
		ft_memcpy(current->value, _data[1], _val_len + 1);
	current->next = NULL;
	if (_UNLIKELY(!env->nodes))
		env->nodes = current;
	else if (_LIKELY(env->last != NULL))
		env->last->next = current;
	env->last = current;
	++env->nb_node;
	env->size += _key_len + _val_len + 2;
	return (current);
}

static inline void	*__env_old_export(
	t_env *const restrict env,
	char **_data
)
{
	const t_find_access	find = {_data[0], 1};
	t_env_node *const	current = env_manager(e_env_find, (void *)&find);

	(void)env;
	if (current->value && !_data[1])
		return (current);
	mm_free(current->value);
	if (!_data[1])
	{
		current->value = NULL;
		return (current);
	}
	current->value = mm_alloc(ft_strlen(_data[1]) + 1);
	if (_UNLIKELY(!current->value))
		return (NULL);
	ft_memcpy(current->value, _data[1], ft_strlen(_data[1]) + 1);
	return (current);
}

inline void	*_env_export(
	t_env *const restrict env,
	void *data,
	const int mode
)
{
	const char			**_data = (const char **)data;
	const t_find_access	find = {(char *)_data[0], 0};

	if (_UNLIKELY(!_data || !_data[0]))
		return (NULL);
	else if (mode || env_manager(e_env_find, (void *)&find) == NULL)
		return (__env_new_export(env, data));
	else
		return (__env_old_export(env, data));
}
