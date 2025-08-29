/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:10:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/29 11:53:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_env.h"

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
