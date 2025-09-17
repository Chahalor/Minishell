/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _free.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:48:27 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 14:54:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parser.h"
#include "parser.h"
#include "env.h"

extern inline void	free_t_exec(
	t_exec_data *const restrict exec
)
{
	mm_free(exec->cmd);
	free_tab(exec->args);
	mm_free(exec);
}

extern inline int	to_pipe(
	t_exec_data *const restrict exec,
	t_token **tok,
	const int i
)
{
	exec->pipe = token_to_exec(&tok[i + 1]);
	if (_UNLIKELY(!exec->pipe))
		return (free_t_exec(exec), 1);
	return (0);
}
