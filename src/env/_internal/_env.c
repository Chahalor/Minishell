/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:11:21 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/01 13:21:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "_env.h"

extern sig_atomic_t	g_last_signal;	/* Global signal variable */

extern void	*_env_find(
				t_env *env,
				char *str,
				const int mode
				);

extern void	*_env_getall(
				t_env *env,
				const int mode
				);

static inline void	*_env_unset(
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
		if (ft_strncmp(_current->key, _data, ft_strlen(_data)) == 0)
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

__attribute__((unused))
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
	return (env);
}

static inline void	*_env_register(
	t_env *env,
	void *data
)
{
	const char		**_envp = (const char **)data;
	register int	i;
	register int	j;
	char			*split[3];

	split[2] = NULL;
	_neutral(split, sizeof(split));
	i = -1;
	while (_envp[++i])
	{
		j = -1;
		while (_envp[i][++j] && _envp[i][j] != '=')
			;
		split[0] = mm_alloc(j + 1);
		split[1] = mm_alloc(ft_strlen(_envp[i] + j + 1) + 1);
		if (_UNLIKELY(!split[0] || !split[1]))
			continue ;
		ft_memcpy(split[0], _envp[i], j);
		ft_memcpy(split[1], _envp[i] + j + 1, ft_strlen(_envp[i] + j + 1) + 1);
		_env_export(env, (void *)split, 1);
		free_tab(split);
	}
	return (NULL);
}

static inline void	*_env_destroy(
	t_env *env
)
{
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

void	*env_manager(
	const int access,
	void *data
)
{
	static t_env	env = {NULL, NULL, 0, 0};
	t_find_access	*__find;

	if (_LIKELY(access == e_env_expand))
		return (_env_expand(data));
	else if (access == e_env_find)
	{
		__find = (t_find_access *)data;
		return (_env_find(&env, \
			(void *)__find->key, \
			__find->mode));
	}
	else if (access == e_env_export)
		return (_env_export(&env, data, 0));
	else if (access == e_env_unset)
		return (_env_unset(&env, data));
	else if (access == e_env_getall)
		return (_env_getall(&env, *(int *)data));
	else if (access == e_env_register)
		return (_env_register(&env, data));
	else if (access == e_env_destroy)
		return (_env_destroy(&env));
	else
		return (NULL);
}
