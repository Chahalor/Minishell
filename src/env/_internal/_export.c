/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _export.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:44:41 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/25 14:31:50 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_env.h"
# include "ft_printf.h"

static inline void	*__env_new_export(
	t_env *const restrict env,
	char **_data
)
{
	const int	_key_len = ft_strlen(_data[0]);
	const int	_val_len = ft_strlen(_data[1]);
	const int	_alloc_size = sizeof(t_env_node) + _key_len + _val_len + 2;
	t_env_node	*current;

	if (_UNLIKELY(!_data || !_data[0] || !_data[1]))
		return (NULL);
	current = mm_alloc(_alloc_size);
	if (_UNLIKELY(!current))
		return (NULL);
	current->key = (char *)(current + 1);
	ft_memcpy(current->key, _data[0], _key_len + 1);
	current->value = current->key + _key_len + 1;
	ft_memcpy(current->value, _data[1], _val_len + 1);
	current->next = NULL;
	if (env->last)
		env->last->next = current;
	env->last = current;
	++env->nb_node;
	env->size += _alloc_size;
	return (current);
}

static inline void	*__env_old_export(
	t_env *const restrict env,
	char **_data
)
{
	const t_find_access				find = {_data[0], 1};
	t_env_node *const	restrict	current = env_manager(e_env_find, (void *)&find);

	(void)env;
	mm_free(current->value);
	current->value = memdup(_data[1], ft_strlen(_data[1]) + 1);
	if (_UNLIKELY(!current->value))
		return (NULL);
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

	if (_UNLIKELY(!_data || !_data[0] || !_data[1]))
		return (NULL);
	else if (mode || env_manager(e_env_find, (void *)&find) == NULL)
		return (__env_new_export(env, data));
	else
		return (__env_old_export(env, data));
}
