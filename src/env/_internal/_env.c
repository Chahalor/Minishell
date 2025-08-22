/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:11:21 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/22 16:00:43 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "_env.h"

static inline void	*_env_export(
	t_env *env,
	void *data
)
{
	const char	**_data = (const char **)data;
	t_env_node	*current;
	int			_alloc_size;

	if (_UNLIKELY(!_data || !*_data || !_data[1]))
		return (NULL);
	current = env->last->next;
	_alloc_size = sizeof(t_env_node) + ft_strlen(_data[0])
		+ ft_strlen(_data[1]) + 2;
	current = mm_alloc(_alloc_size);
	if (_UNLIKELY(!current))
		return (NULL);
	current->key = (char *)(current + 1);
	ft_memcpy(current->key, _data[0], ft_strlen(_data[0]) + 1);
	current->value = current->key + ft_strlen(_data[0]) + 1;
	ft_memcpy(current->value, _data[1], ft_strlen(_data[1]) + 1);
	env->last = current;
	++env->nb_node;
	env->size += _alloc_size;
	return (current);
}

static inline void	*_env_unset(
	t_env *env,
	void *data
)
{
	char		*_data = (char *)data;
	t_env_node	*current;
	t_env_node	*previous;

	current = env->nodes;
	previous = NULL;
	while (current)
	{
		if (ft_strlen(current->key) == ft_strlen(_data)
			&& !ft_strncmp(current->key, _data, ft_strlen(_data)))
		{
			if (previous)
				previous->next = current->next;
			else
				env->nodes = current->next;
			if (current == env->last)
				env->last = previous;
			mm_free(current);
			--env->nb_node;
			return (NULL);
		}
		previous = current;
		current = current->next;
	}
	return (NULL);
}

static inline void	*_env_register(
	t_env *env,
	void *data
)
{
	const char		**_envp = (const char **)data;
	register int	i;
	char			**split;

	i = -1;
	while (_envp[++i])
	{
		split = ft_split(_envp[i], '=');
		_env_export(env, split);
		free_tab(split);
	}
	return (NULL);
}

static inline void	*_env_destroy(
	t_env *env,
	void *data
)
{
	(void)data;
	t_env_node	*current;
	t_env_node	*next;

	current = env->nodes;
	while (current)
	{
		next = current->next;
		mm_free(current);
		current = next;
	}
	env->nodes = NULL;
	env->last = NULL;
	env->nb_node = 0;
	env->size = 0;
	return (NULL);
}

static inline void	*_env_find(
	t_env *env,
	char **str
)
{
	t_env_node	*current;

	current = env->nodes;
	while (current)
	{
		if (ft_strlen(current->key) == ft_strlen(*str)
			&& !ft_strncmp(current->key, *str, ft_strlen(*str)))
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

void	*env_manager(
	const int access,
	void *data
)
{
	static t_env	env = {NULL, NULL, 0, 0};

	if (access == e_env_expand)
		return (_env_expand(&env, data));
	else if (access == e_env_find)
		return (_env_find(&env, data));
	else if (access == e_env_export)
		return (_env_export(&env, data));
	else if (access == e_env_unset)
		return (_env_unset(&env, data));
	else if (access == e_env_register)
		return (_env_register(&env, data));
	else if (access == e_env_destroy)
		return (_env_destroy(&env, data));
	else
		return (NULL);
}
