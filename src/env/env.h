/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:08:32 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/25 09:57:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# pragma once

# include <stdlib.h>

char	env_export(
			const char *key,
			const char *value
			);

char	env_unset(
			const char *key
			);

char	env_register(
			const char **envp
			);

char	env_destroy(void);

char	*env_expand(
			char **str
			);

char	*env_find(
			const char *key
			);

#endif