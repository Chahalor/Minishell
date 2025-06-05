/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _build.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:02:33 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/05 13:21:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_lexer.h"

/* -----| Modules   |----- */
#include "lexer.h"

#pragma endregion Header
#pragma region Fonctions

/*static inline t_exec_data	*heredoc(
	const t_token *const restrict tokens
)
{
	return (build_heredoc(tokens));
}

static inline t_exec_data	*_redir(
	const t_token *const restrict tokens
)
{
	return (build_infile(tokens));
}

static inline t_exec_data	*_in(
	const t_token *const restrict tokens
)
{
	return (build_infile(tokens));
}

static inline t_exec_data	*_pipe(
	const t_token *const restrict tokens
)
{
	return (build_pipe(tokens));
}

__attribute__((deprecated)) t_exec_data	*build_exec(
	t_token *const restrict tokens
)
{
	t_exec_data	*data;
	t_exec_data	*current;
	t_token		*tmp;

	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == TOKEN_REDIR_HEREDOC)
			current = heredoc(tmp);
		else if (tmp->type == TOKEN_REDIR_IN)
			current = _in(tmp);
		else if (tmp->type == TOKEN_REDIR_OUT
			|| tmp->type == TOKEN_REDIR_APPEND)
			current = _redir(tmp);
		else if (tmp->type == TOKEN_PIPE)
			current = _pipe(tmp);
		else
			current = _cmd(tmp);
		tmp = tmp->next;
	}
	return (data);
}*/

#pragma endregion Fonctions