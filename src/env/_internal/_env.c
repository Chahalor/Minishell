/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:11:21 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/25 09:54:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "_env.h"
# include "ft_printf.h"

static inline void	*__env_init(
	t_env *env
)
{
	if (env->nodes)
		return (env);
	env->nodes = mm_alloc(sizeof(t_env_node));
	if (_UNLIKELY(!env->nodes))
		return (NULL);
	env->last = env->nodes;
	env->nb_node = 1;
	env->size = 0;
	env_export("PS1", DEFAULT_PROMPT);
	env_export("PWD", getcwd(NULL, 0));
	env_export("OLDPWD", "");
	env_export("SHLVL", "1");
	return (env);
}

static inline void	*_env_export(
	t_env *const restrict env,
	void *data
)
{
	const char	**_data = (const char **)data;
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

	__env_init(env);
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
	char *str
)
{
	t_env_node	*current;

	ft_fprintf(2, "node=%p\n", env->nodes);
	current = env->nodes;
	while (current)
	{
		ft_fprintf(2, "Searching: '%s' <=> '%s'\n", str, current->key);
		if (ft_strlen(current->key) == ft_strlen(str)
			&& !ft_strncmp(current->key, str, ft_strlen(str)))
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
