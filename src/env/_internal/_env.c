/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:11:21 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/25 14:37:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "_env.h"
# include "ft_printf.h"

extern sig_atomic_t	g_last_signal;	/* Global signal variable */

static inline void *_env_unset(
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
		ft_fprintf(2, "compare '%s' and '%s'\n", _current->key, _data); //--- rm ---
		if (ft_strncmp(_current->key, _data, ft_strlen(_data)) == 0)
		{
			if (_prev)
				_prev->next = _current->next;
			else
				env->nodes = _current->next;
			ft_fprintf(2, "current={%s=%s}\n", _current->key, _current->value); //--- rm ---
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
	char			**split;

	split = ft_split(_envp[0], '=');
	_env_export(env, split, 1);
	free_tab(split);
	env->nodes = env->last;
	i = 0;
	while (_envp[++i])
	{
		split = ft_split(_envp[i], '=');
		_env_export(env, split, 1);
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
	char *str,
	const int mode
)
{
	t_env_node	*current;

	if (ft_strncmp("?", str, 1) == 0)
		return (ft_itoa(g_last_signal));
	else if (ft_strncmp("~", str, 2) == 0)
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

static inline void	*_env_getall(
	t_env *env
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
		result[++_i] = mm_alloc(ft_strlen(_current->key)
			+ ft_strlen(_current->value) + 2);
		if (_UNLIKELY(!result[_i]))
			return (free_tab(result), NULL);
		ft_memcpy(result[_i], _current->key, ft_strlen(_current->key));
		result[_i][ft_strlen(_current->key)] = '=';
		ft_memcpy(&result[_i][ft_strlen(_current->key) + 1],
			_current->value, ft_strlen(_current->value) + 1);
		_current = _current->next;
	}
	return (result);
}

void	*env_manager(
	const int access,
	void *data
)
{
	static t_env	env = {NULL, NULL, 0, 0};
	t_find_access	*__find;

	if (_LIKELY(access == e_env_expand))
		return (_env_expand(&env, data));
	else if (access == e_env_find)
	{
		__find = (t_find_access *)data;
		return (_env_find(&env,
			(void *)__find->key,
			__find->mode));
	}
	else if (access == e_env_export)
		return (_env_export(&env, data, 0));
	else if (access == e_env_unset)
		return (_env_unset(&env, data));
	else if (access == e_env_getall)
		return (_env_getall(&env));
	else if (access == e_env_register)
		return (_env_register(&env, data));
	else if (access == e_env_destroy)
		return (_env_destroy(&env, data));
	else
		return (NULL);
}
