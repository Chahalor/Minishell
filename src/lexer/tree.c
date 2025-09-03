/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:40:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/03 13:08:57 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region HEADERS

#include "_lexer.h"
#include "lexer.h"
#include "env.h"

#pragma endregion HEADERS
#pragma region FUNCTIONS

static inline t_exec_data	*new_exec(
	const int nb_args
)
{
	t_exec_data	*exec;

	exec = mm_alloc(sizeof(t_exec_data));
	if (_UNLIKELY(!exec))
		return (NULL);
	*exec = (t_exec_data){
		.cmd = NULL,
		.args = mm_alloc(nb_args * sizeof(char *)),
		.pipe = NULL,
		.type = 0,
		.fd_in = -1,
		.fd_out = -1,
		.status = -1,
		.pid = 0,
	};
	return (exec);
}

static inline int	count_args(
	const t_token *const restrict *const restrict tok
)
{
	register int	i;
	register int	count;

	i = -1;
	count = 0;
	while (tok[++i] && !_is_redir(tok[i]->type))
		if (tok[i]->type == TOKEN_CMD || tok[i]->type == TOKEN_WORD)
			++count;
	return (count);
}

static inline int	__redir(
	t_token **tok,
	t_exec_data *exec,
	int *const restrict i
)
{
	const int	flag_truc = O_WRONLY | O_CREAT | O_TRUNC;
	const int	flag_app = O_WRONLY | O_CREAT | O_APPEND;
	int			heredoc_fd;

	if (tok[*i]->type == TOKEN_GREATER)
		exec->fd_out = open(tok[++(*i)]->value, flag_truc, 0644);
	else if (tok[*i]->type == TOKEN_DGREATER)
		exec->fd_out = open(tok[++(*i)]->value, flag_app, 0644);
	else if (tok[*i]->type == TOKEN_LESS)
		exec->fd_in = open(tok[++(*i)]->value, O_RDONLY);
	else if (tok[*i]->type == TOKEN_DLESS)
	{
		heredoc_fd = heredoc_all(tok[++(*i)]->value);
		if (heredoc_fd < 0)
			return (-1);
		exec->fd_in = heredoc_fd;
	}
	return (0);
}

static inline int	__new_cmd(
	t_exec_data *exec,
	t_token **tok,
	int *const restrict j,
	const int i
)
{
	if (!exec->cmd)
		exec->cmd = _get_bin(tok[i]->value);
	if (tok[i]->type != TOKEN_QUOTE)
		exec->args[(*j)++] = env_expand(tok[i]->value);
	else
		exec->args[(*j)++] = tok[i]->value;
	return (-(exec->cmd == NULL));
}

t_exec_data	*token_to_exec(
	t_token **tok
)
{
	t_exec_data	*exec;
	int			i;
	int			j;

	if (_UNLIKELY(!tok || !*tok || check_tokens(tok) != PARSER_ERR_NONE))
		return (NULL);
	exec = new_exec(count_args((void *)tok) + 2);
	if (_UNLIKELY(!exec || !exec->args))
		return (mm_free(exec), NULL);
	i = 0;
	j = 0;
	while (tok[i] && tok[i]->type != TOKEN_PIPE)
	{
		if (_is_word(tok[i]->type))
			__new_cmd(exec, tok, &j, i);
		else if (_is_redir(tok[i]->type))
			if (__redir(tok, exec, &i) < 0)
				return (mm_free(exec->cmd), free_tab(exec->args),
					mm_free(exec), NULL);
		++i;
	}
	exec->args[j] = NULL;
	if (tok[i] && tok[i]->type == TOKEN_PIPE)
		exec->pipe = token_to_exec(&tok[i + 1]);
	return (exec);
}

#pragma endregion FUNCTIONS
