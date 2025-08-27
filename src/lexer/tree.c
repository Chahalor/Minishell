/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:40:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/27 18:07:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region HEADERS

#include "_lexer.h"
#include "lexer.h"
#include "env.h"

#pragma endregion HEADERS
#pragma region FUNCTIONS

#pragma region TOKEN

const char *show_type(
	const int type
)
{
	static const char	*messages[15] = {
		[TOKEN_CMD] = BLUE "CMD" RESET,
		[TOKEN_PIPE] = CYAN "PIPE" RESET,
		[TOKEN_QUOTE] = YELLOW "QUOTE" RESET,
		[TOKEN_DQUOTE] = GREEN "DQUOTE" RESET,
		[TOKEN_GREATER] = RED "GREATER" RESET,
		[TOKEN_LESS] = MAGENTA "LESS" RESET,
		[TOKEN_DGREATER] = BLUE "DGREATER" RESET,
		[TOKEN_DLESS] = BLUE "DLESS" RESET,
		[TOKEN_WORD] = WHITE "WORD" RESET,
		[PARSER_ERR_NONE] = GREEN "NO ERROR" RESET,
		[PARSER_ERR_MISSING_QUOTE] = RED "MISSING QUOTE" RESET,
		[PARSER_ERR_UNEXPECTED_TOKEN] = RED "UNEXPECTED TOKEN" RESET,
		[PARSER_ERR_BROKEN_PIPE] = RED "BROKEN PIPE" RESET,
		[PARSER_ERR_INVALID_REDIRECTION] = RED "INVALID REDIRECTION" RESET,
		[PARSER_ERR_MEMORY_ALLOCATION] = RED "MEMORY ALLOCATION" RESET
	};

	return (messages[type % (PARSER_ERR_MEMORY_ALLOCATION + 1)]);
}

/* Create a new token */
static inline t_token	*token_new(
	const char *str,
	const int type,
	const int size
)
{
	t_token			*tok;
	register int	i;

	tok = mm_alloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->value = mm_alloc(size + 1);
	if (!tok->value)
		return (mm_free(tok), NULL);
	i = -1;
	while (++i < size)
		tok->value[i] = str[i];
	tok->value[i] = '\0';
	tok->type = type;
	tok->size = size;
	return (tok);
}

static inline t_token	*_quote_handling(
	const char *line,
	size_t *i,
	size_t len,
	size_t *idx
)
{
	register size_t	start;
	t_token			*tok;
	char			delim;

	(void)idx;
	// ft_fprintf(2, "%s called\n", __func__);
	if (line[*i] == '\'')
	{
		start = ++(*i);
		while (*i < len && line[*i] != '\'')
			++(*i);
		tok = token_new(line + start, TOKEN_QUOTE, (*i)++ - start);
		delim = '\'';
	}
	else
	{
		start = ++(*i);
		while (*i < len && line[*i] != '"')
			++(*i);
		tok = token_new(line + start, TOKEN_DQUOTE, (*i)++ - start);
		delim = '"';
	}
	if (line[*i - 1] != delim)
		tok->type = PARSER_ERR_MISSING_QUOTE;
	return (tok);
}

static inline t_token	*_redirect_handling(
	const char *line,
	size_t *i,
	size_t *idx
)
{
	t_token	*tok;

	(void)idx;
	if (line[*i] == '>')
	{
		if (line[*i + 1] == '>')
		{
			tok = token_new(">>", TOKEN_DGREATER, 2);
			*i += 2;
		}
		else
			tok = token_new(">", TOKEN_GREATER, 1 + 0 * ++(*i));
	}
	else
	{
		if (line[*i + 1] == '<')
		{
			tok = token_new("<<", TOKEN_DLESS, 2);
			*i += 2;
		}
		else
			tok = token_new("<", TOKEN_LESS, 1 + 0 * ++(*i));
	}
	return (tok);
}

static inline t_token	*_word_handling(
	const char *line,
	size_t *const transfer[2],
	const t_token **tokens,
	size_t len
)
{
	size_t *const	i = transfer[0];
	const size_t	idx = *transfer[1];
	const size_t	start = *i;
	t_token			*tok;

	// ft_fprintf(2, "%s called\n", __func__);
	while (*i < len && !isspace(line[*i]) &&
		line[*i] != '|' && line[*i] != '<' && line[*i] != '>')
		++(*i);
	if (!idx)
		tok = token_new(line + start, TOKEN_CMD, *i - start);
	else if (idx && tokens[idx - 1] && (tokens[idx - 1]->type == TOKEN_PIPE))
		tok = token_new(line + start, TOKEN_CMD, *i - start);
	else
		tok = token_new(line + start, TOKEN_WORD, *i - start);
	// ft_fprintf(2, "end of word_andling idx=%d\n", idx);
	return (tok);
}

/* Simple tokenizer: splits line into tokens */
t_token	**tokenize_line(
	const char *const restrict line,
	int *const restrict count
)
{
	register const size_t	len = ft_strlen(line);
	t_token					**tokens = mm_alloc(PARSER_ALLOC_SIZE * sizeof(t_token*));
	size_t					idx = 0;
	size_t					i;

	tokens[0] = NULL;
	i = 0;
	while (i < len)
	{
		// ft_fprintf(2, "line[%d]=<%c>, idx=%d\n", i, line[i], idx);
		if (isspace(line[i]))
			++i;
		else if (line[i] == '|')
		{
			// ft_fprintf(2, "token pipe created\n");
			tokens[idx++] = token_new("|", TOKEN_PIPE, 1 + 0 * ++i);
		}
		else if (line[i] == '\'' || line[i] == '"')
			tokens[idx++] = _quote_handling(line, &i, len, &idx);
		else if (line[i] == '>' || line[i] == '<')
			tokens[idx++] = _redirect_handling(line, &i, &idx);
		else
			tokens[idx++] = _word_handling(line, (size_t *[2]){&i, &idx}, (const t_token **)tokens, len);
		// ft_fprintf(2, "idx=%d tokens[%d]=%p\n", idx, idx, tokens[idx]);
		if (!(idx % PARSER_ALLOC_SIZE))
			tokens = mm_realloc(tokens, (idx + PARSER_ALLOC_SIZE) * sizeof(t_token*));
	}
	*count = idx;
	return (tokens);
}

#pragma endregion TOKEN
#pragma region TO EXEC

static inline t_exec_data	*new_exec(

)
{
	t_exec_data	*data;

	data = mm_alloc(sizeof(t_exec_data));
	if (!data)
		return (NULL);
	*data = (t_exec_data){
		.cmd = NULL,
		.args = NULL,
		.status = 0,
		.pid = -1,
		.fd_in = -1,
		.fd_out = -1,
		.type = 0,
		.pipe = NULL,
		.next = NULL
	};
	return (data);
}

static inline int	is_word(
	const int token
)
{
	return (token == TOKEN_WORD || token == TOKEN_CMD ||
		token == TOKEN_QUOTE || token == TOKEN_DQUOTE);
}

static inline int	is_redirect(
	const int token
)
{
	return (token == TOKEN_GREATER || token == TOKEN_LESS ||
		token == TOKEN_DGREATER || token == TOKEN_DLESS || token == TOKEN_WORD);
}

static inline int	_heredoc(
	const char *const restrict delimiter
)
{
	return (heredoc_all(delimiter));
}

static inline int	apply_redirs(
	t_exec_data *data,
	t_token **tok,
	const int start
)
{
	register int	j;

	j = start - 1;
	while (tok[++j] && (is_redirect(tok[j]->type) || is_word(tok[j]->type)))
	{
		if (tok[j]->type == TOKEN_GREATER)
			data->fd_out = open(tok[j + 1]->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (tok[j]->type == TOKEN_DGREATER)
			data->fd_out = open(tok[j + 1]->value, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (tok[j]->type == TOKEN_LESS)
			data->fd_in = open(tok[j + 1]->value, O_RDONLY, 0644);
		else if (tok[j]->type == TOKEN_DLESS)
			data->fd_in = heredoc_all(tok[j + 1]->value);
		else
			continue ;
	}
	if (_UNLIKELY(data->fd_in < 0 || data->fd_out < 0))
		return (mm_free(data), -1); // make sure to free all data
	else
		return (j - start);
}

static inline void	_show_error(
	const t_token **tok,
	int index,
	int error
)
{
	const int	_start = index;

	ft_fprintf(2, "Syntax error near unexpected token: %s\n\t\t", show_type(error));
	index = (index - 5) * (index > 5);
	while (index < _start)
		ft_fprintf(2, "%s ", tok[index++]->value);
	ft_fprintf(2, RED " '%s'" RESET, tok[_start]->value);
	while (tok[++index] && index < _start + 5)
		ft_fprintf(2, " %s", tok[index]->value);
	ft_fprintf(2, "\n");
}

static inline int	check_tokens(
	t_token **tok
)
{
	register int	i;
	t_tok_error		err;
	int				last_token;

	err.error = PARSER_ERR_NONE;
	i = -1;
	while (tok[++i])
	{
		if (tok[i]->type >= PARSER_ERR_NONE)
		{
			err.error = (tok[i]->type);
			err.token = tok[i];
			break ;
		}
		else if (i && tok[i]->type == TOKEN_PIPE && last_token == TOKEN_PIPE)
		{
			err.error = (PARSER_ERR_BROKEN_PIPE);
			err.token = tok[i];
			break ;
		}
		else if (i && ((is_redirect(tok[i]->type) && is_redirect(last_token)) || !is_word(tok[i]->type)))
		{
			err.error = (PARSER_ERR_INVALID_REDIRECTION);
			err.token = tok[i];
			break ;
		}
		else if (i && tok[i]->type == TOKEN_DLESS && !tok[i + 1])	// ne marche pas
		{
			err.error = (PARSER_ERR_INVALID_REDIRECTION);
			err.token = tok[i];
			break ;
		}
		last_token = tok[i]->type;
	}
	if (i && err.error == PARSER_ERR_NONE && tok[i - 1]->type == TOKEN_PIPE)
	{
		err.error = (PARSER_ERR_BROKEN_PIPE);
		err.token = tok[i - 1];
		--i;
	}
	if (err.error != PARSER_ERR_NONE)
		_show_error((const t_token **)tok, i, err.error);
	return (err.error);
}

__attribute_maybe_unused__
static int count_args(t_token **tok)
{
	int i = 0;
	int count = 0;

	while (tok[i] && tok[i]->type != TOKEN_PIPE)
	{
		if (tok[i]->type == TOKEN_CMD || tok[i]->type == TOKEN_WORD)
			count++;
		i++;
	}
	return count;
}

static inline char *ft_strdup(const char *s)
{
	size_t len = ft_strlen(s);
	char *dup = mm_alloc(len + 1);
	if (dup)
		ft_memcpy(dup, s, len + 1);
	return dup;
}

t_exec_data	*token_to_exec(
	t_token **tok
)
{
	t_exec_data		*exec;
	register int	i;
	register int	j;

	if (_UNLIKELY(!tok || !*tok))
		return (NULL);
	exec = mm_alloc(sizeof(t_exec_data));
	if (_UNLIKELY(!exec))
		return (NULL);
	exec->fd_in = -1;
	exec->fd_out = -1;
	exec->status = 0;
	exec->pid = -1;
	exec->pipe = NULL;
	exec->args = mm_alloc((count_args(tok) + 2) * sizeof(char *));
	if (_UNLIKELY(!exec->args))
		return (mm_free(exec), NULL);
	i = 0;
	j = 0;
	while (tok[i] && tok[i]->type != TOKEN_PIPE)
	{
		if (tok[i]->type == TOKEN_WORD || tok[i]->type == TOKEN_QUOTE || tok[i]->type == TOKEN_DQUOTE)
		{
			if (!exec->cmd)
				exec->cmd = _get_bin(tok[i]->value);
			if (tok[i]->type != TOKEN_QUOTE)
				exec->args[j++] = env_expand(tok[i]->value);
			else
				exec->args[j++] = tok[i]->value;
		}
		else if (tok[i]->type == TOKEN_GREATER)
			exec->fd_out = open(tok[++i]->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (tok[i]->type == TOKEN_DGREATER)
			exec->fd_out = open(tok[++i]->value, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (tok[i]->type == TOKEN_LESS)
			exec->fd_in = open(tok[++i]->value, O_RDONLY);
		else if (tok[i]->type == TOKEN_DLESS)
		{
			exec->fd_in = _heredoc(tok[i + 1] ? tok[i + 1]->value : NULL);
			++i;
		}
		++i;
	}
	exec->args[j] = NULL;
	if (tok[i] && tok[i]->type == TOKEN_PIPE)
		exec->pipe = token_to_exec(&tok[i + 1]);
	return (exec);
}

/*{
	t_exec_data		*data;
	t_exec_data		*current;
	register int	nb_args;
	register int	i;
	register int	j;
	int				redir_status;

	// if (check_tokens(tok) != PARSER_ERR_NONE)
	// 	return (NULL);
	data = new_exec();
	if (!data)
		return (NULL);
	current = data;
	i = -1;
	while (tok[++i])
	{
		nb_args = 0;
		if (!is_word(tok[i]->type))
		{
			redir_status = apply_redirs(current, tok, i);
			if (redir_status < 0)
				return (NULL); // make sure to free all data
			i += redir_status - 1;
			continue ;
		}
		current->cmd = _get_bin(tok[i]->value);
		if (!current->cmd)
			return (mm_free(current), NULL); // shale also free data
		while (tok[++i] && is_word(tok[i]->type))
			++nb_args;
		current->args = mm_alloc((nb_args + 2) * sizeof(char *));
		if (_UNLIKELY(!current->args))
			return (mm_free(current->cmd), NULL); // shale also free data
		j = -1;
		while (++j < nb_args + 1)
		{
			if (tok[i - nb_args - 1 + j]->type == TOKEN_DQUOTE ||
				tok[i - nb_args - 1 + j]->type == TOKEN_WORD)
				current->args[j] = env_expand(tok[i - nb_args - 1 + j]->value);
			else
				current->args[j] = tok[i - nb_args - 1 + j]->value;
		}
		current->args[j] = NULL;
		if (!tok[i])
			break ;
		else if (tok[i]->type == TOKEN_PIPE)
		{
			current->pipe = new_exec();
			if (!current->pipe)
				return (mm_free(current->cmd), free_tab(current->args), NULL); // shale also free data
			current = current->pipe;
		}
		else if (is_redirect(tok[i]->type))
		{
			redir_status = apply_redirs(current, tok, i);
			if (redir_status < 0)
				return (NULL); // make sure to free all data
			i += redir_status - 1;
		}
		else
			break ;
	}
	return (data);
}*/

#pragma endregion "TO EXEC"
#pragma region DEBUG

/* ===== Debug print ===== */
void	print_tokens(
	const t_token **tokens,
	const int count
)
{
	register int	i;

	if (_UNLIKELY(!tokens || count < 1))
	{
		printf("No tokens to display\n");
		return ;
	}
	i = -1;
	while (++i < count)
		printf("(%d)[%s] type=%s (%d) size=%d\n", i, tokens[i]->value,
			show_type(tokens[i]->type), tokens[i]->type, tokens[i]->size);
}

void	print_exec(
	const t_exec_data *const restrict exec
)
{
	t_exec_data	*current;

	current = (t_exec_data *)exec;
	while (current)
	{
		printf("Command: '%s' (%p)\n", current->cmd, current);
		printf("Arguments:\n");
		if (current->args)
		{
			register int	j;

			j = -1;
			while (current->args[++j])
				printf("  arg[%d]: '%s'\n", j, current->args[j]);
			printf("  arg[%d]: %p\n", j, current->args[j]);
		}
		else
			printf("  No arguments\n");
		printf("Input FD: %d\n", current->fd_in);
		printf("Output FD: %d\n", current->fd_out);
		printf("Status: %d\n", current->status);
		current = current->pipe;
	}
}
#pragma endregion DEBUG
#pragma endregion FUNCTIONS
