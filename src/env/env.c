/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:10:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/25 14:38:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_env.h"

char	env_export(
	const char *key,
	const char *value
)
{
	return (env_manager(e_env_export, (void *[2]){(char *)key, (char *)value}) != NULL);
}

char	env_unset(
	const char *key
)
{
	return (env_manager(e_env_unset, (void *)key) != NULL);
}

char	env_register(
	const char **envp
)
{
	return (env_manager(e_env_register, (void *)envp) != NULL);
}

char	env_destroy(
	void
)
{
	return (env_manager(e_env_destroy, NULL) != NULL);
}

char	*env_expand(
	char *str
)
{
	return (env_manager(e_env_expand, (void *)str));
}

char	*env_find(
	const char *key
)
{
	const struct s_env_find_access	data = {(char *)key, 0};

	return (env_manager(e_env_find, (void *)&data));
}

char	**env_getall(void)
{
	return (env_manager(e_env_getall, NULL));
}
