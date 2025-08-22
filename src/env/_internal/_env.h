/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _env.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:25:48 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/22 16:00:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ENV_H
# define _ENV_H

# pragma once

#include "mmanager.h"
#include "utils.h"

# define ENV_ALLOC_SIZE	128

typedef enum e_env_access	t_env_access;

typedef struct s_env		t_env;
typedef struct s_env_node	t_env_node;

enum e_env_access
{
	e_env_expand,
	e_env_register,
	e_env_export,
	e_env_unset,
	e_env_find,
	e_env_destroy
};

struct s_env
{
	t_env_node		*nodes;
	t_env_node		*last;
	int				nb_node;
	unsigned int	size;
};

struct s_env_node
{
	char		*key;
	char		*value;
	t_env_node	*next;
};

void	*_env_expand(
			t_env *env,
			void **data
			);

void	*env_manager(
			const int access,
			void *data
			);

#endif /* !_ENV_H */