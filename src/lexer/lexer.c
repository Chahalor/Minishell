/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/16 12:02:39 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_lexer.h"

/* -----| Modules   |----- */
#include "lexer.h"

#pragma endregion Header
#pragma region Fonctions

/** */
static inline int	_heredoc(
	const t_redir *const restrict r,
	t_exec_data *const restrict data
)
{
	data->fd_in = heredoc_all(r->file);
	if (_UNLIKELY(data->fd_in < 0))
		return (mm_free(data->cmd), mm_free(data), -1);
	else
		return (data->fd_in);
}

/** */
static inline t_exec_data	*exec_data_new(
	const t_ast *const n
)
{
	t_exec_data	*result;

	result = mm_alloc(1 * sizeof(t_exec_data));
	if (_UNLIKELY(!result))
		return (NULL);
	*result = (t_exec_data){
		.cmd = _get_bin(n->data.cmd.argv[0]),
		.args = n->data.cmd.argv,
		.pipe = NULL,
		.type = 0,
		.fd_in = -1,
		.fd_out = -1,
		.status = -1,
	};
	return (result);
}

/** */
static inline t_exec_data	*apply_redirs(
	t_exec_data *data,
	t_redir *r
)
{
	while (r)
	{
		if (r->type == REDIR_IN)
		{
			data->fd_in = open(r->file, O_RDONLY, 0644);
			data->type = r->type;
		}
		else if (r->type == REDIR_HEREDOC)
		{
			if (_UNLIKELY(_heredoc(r, data) < 0))
				return (mm_free(data->cmd), mm_free(data), NULL);
		}
		else if (r->type == REDIR_OUT || r->type == REDIR_APPEND)
		{
			if (r->type == REDIR_OUT)
				data->fd_out = open(r->file, O_WRONLY | O_CREAT
						| O_TRUNC, 0644);
			else
				data->fd_out = open(r->file, O_WRONLY | O_CREAT
						| O_APPEND, 0644);
			data->type = r->type;
		}
		r = r->next;
	}
	return (data);
}

/** */
t_exec_data	*ast_to_exec_data(
	t_ast	*n
)
{
	t_exec_data	*data;

	if (_UNLIKELY(!n))
		return (NULL);
	else if (n->type == NODE_PIPE)
	{
		data = ast_to_exec_data(n->data.pipe.lhs);
		if (data)
			data->pipe = ast_to_exec_data(n->data.pipe.rhs);
		return (data);
	}
	else
	{
		data = exec_data_new(n);
		if (_UNLIKELY(!data))
			return (NULL);
		data = apply_redirs(data, n->data.cmd.redirs);
		if (_UNLIKELY(!data->cmd && !isatty(data->fd_out)))
		{
			close(data->fd_out);
			data->fd_out = -1;
		}
		return (data);
	}
}

/**
 * @brief	Lexer function that parses a command line and builds an execution
 * 				data structure from it.
 * 
 * @param	line	The command line to parse.
 * 
 * @return	Returns a pointer to the execution data structure.
 * @retval		NULL if the command line is invalid or if an error occurs.
 * @retval		data if the command line is valid and the execution data
 * 					structure is built successfully.
*/
__attribute__((deprecated)) t_exec_data	*lexer(
	const char *const restrict line
)
{
	t_exec_data		*data;
	t_ast			*ast;

	ast = full_ast((char **)&line);
	if (_UNLIKELY(!ast))
		return (perror("lexer(): full_ast() failed"), NULL);
	else
		data = ast_to_exec_data(ast);
	return (data);
}

#pragma endregion Fonctions
