/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:10:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/12 12:36:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "_env.h"

char	env_export(
	const char *key,
	const char *value
)
{
	return (env_manager(e_env_export, (void *[2]){(char *)key,
			(char *)value}) != NULL);
}

char	env_register(
	const char **envp
)
{
	return (env_manager(e_env_register, (void *)envp) != NULL);
}

char	env_unset(
	const char *key
)
{
	return (env_manager(e_env_unset, (void *)key) != NULL);
}

char	env_destroy(void)
{
	return (env_manager(e_env_destroy, NULL) != NULL);
}

__attribute__((unused, cold))
int	env_init(
	const char	**envp
)
{
	char	*shlvl_str;
	char	*history_path;

	env_register(envp);
	shlvl_str = ft_itoa(ft_atoi(env_find("SHLVL")) + 1);
	env_export("SHLVL", shlvl_str);
	env_export("PS1", PS1);
	env_export("PS2", PS2);
	history_path = env_expand(DEFAULT_HISTORY_FILE);
	env_export("HISTORY_PATH", history_path);
	mm_free(shlvl_str);
	mm_free(history_path);
	return (0);
}
