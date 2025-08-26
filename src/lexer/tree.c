/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:40:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/26 16:49:52 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region HEADERS

#include "_lexer.h"
#include "lexer.h"
#include "env.h"

#pragma endregion HEADERS
#pragma region FUNCTIONS

#pragma region TOKEN


/* Create a new token */
static inline t_token	*token_new(
	const char *str,
	const int type,
	const int size
)
{
	t_token	*tok;

	tok = mm_alloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->value = strndup(str, size);
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
	ft_fprintf(2, "%s called\n", __func__);
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
	ft_fprintf(2, "%s called\n", __func__);
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
	size_t *const	idx = transfer[1];
	const size_t	start = *i;
	t_token			*tok;

	ft_fprintf(2, "%s called\n", __func__);
	while (*i < len && !isspace(line[*i]) &&
		line[*i] != '|' && line[*i] != '<' && line[*i] != '>')
		++(*i);
	if (!(*idx))
		tok = token_new(line + start, TOKEN_CMD, *i - start);
	else if (*idx && tokens[*idx - 1] && (tokens[*idx - 1]->type == TOKEN_PIPE))
		tok = token_new(line + start, TOKEN_CMD, *i - start);
	else
		tok = token_new(line + start, TOKEN_WORD, *i - start);
	ft_fprintf(2, "end of word_andling idx=%d\n", *idx);
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
		ft_fprintf(2, "line[%d]=<%c>, idx=%d\n", i, line[i], idx);
		if (isspace(line[i]))
			++i;
		else if (line[i] == '|')
		{
			ft_fprintf(2, "token pipe created\n");
			tokens[idx++] = token_new("|", TOKEN_PIPE, 1 + 0 * ++i);
		}
		else if (line[i] == '\'' || line[i] == '"')
			tokens[idx++] = _quote_handling(line, &i, len, &idx);
		else if (line[i] == '>' || line[i] == '<')
			tokens[idx++] = _redirect_handling(line, &i, &idx);
		else
			tokens[idx++] = _word_handling(line, (size_t *[2]){&i, &idx}, (const t_token **)tokens, len);
		ft_fprintf(2, "idx=%d tokens[%d]=%p\n", idx, idx, tokens[idx]);
		if (!(idx % PARSER_ALLOC_SIZE))
			tokens = mm_realloc(tokens, (idx + PARSER_ALLOC_SIZE) * sizeof(t_token*));
	}
	*count = idx;
	return (tokens);
}

const char *show_type(
	const int type
)
{
	static const char	*messages[14] = {
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
		[PARSER_ERR_INVALID_REDIRECTION] = RED "INVALID REDIRECTION" RESET,
		[PARSER_ERR_MEMORY_ALLOCATION] = RED "MEMORY ALLOCATION" RESET
	};

	return (messages[type % (PARSER_ERR_MEMORY_ALLOCATION + 1)]);
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
		token == TOKEN_DGREATER || token == TOKEN_DLESS);
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
	return (j - start);
}

t_exec_data	*token_to_exec(
	t_token **tokens,
	const int count
)
{
	t_exec_data		*data;
	t_exec_data		*current;
	register int	nb_args;
	register int	i;
	register int	j;

	(void)count;
	data = new_exec();
	if (!data)
		return (NULL);
	current = data;
	i = -1;
	while (tokens[++i])
	{
		nb_args = 0;
		current->cmd = _get_bin(tokens[i]->value);
		if (!current->cmd)
			return (mm_free(current), NULL); // shale also free data
		while (tokens[++i] && is_word(tokens[i]->type))
			++nb_args;
		current->args = mm_alloc((nb_args + 2) * sizeof(char *));
		if (_UNLIKELY(!current->args))
			return (mm_free(current->cmd), NULL); // shale also free data
		j = -1;
		while (++j < nb_args + 1)
		{
			if (tokens[i - nb_args - 1 + j]->type == TOKEN_DQUOTE ||
				tokens[i - nb_args - 1 + j]->type == TOKEN_WORD)
				current->args[j] = env_expand(tokens[i - nb_args - 1 + j]->value);
			else
				current->args[j] = tokens[i - nb_args - 1 + j]->value;
		}
		current->args[j] = NULL;
		if (!tokens[i])
			break ;
		else if (tokens[i]->type == TOKEN_PIPE)
		{
			current->pipe = new_exec();
			if (!current->pipe)
				return (mm_free(current->cmd), free_tab(current->args), NULL); // shale also free data
			current = current->pipe;
			++i;
		}
		else if (is_redirect(tokens[i]->type))
			i += apply_redirs(current, tokens, i);
		else
			break ;
	}
	return (data);
}

#pragma endregion "TO EXEC"

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
		printf("[%s] type=%s (%d) size=%d\n", tokens[i]->value,
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
		printf("Command: '%s'\n", current->cmd);
		printf("Arguments:\n");
		if (current->args)
		{
			register int	j;

			j = -1;
			while (current->args[++j])
				printf("  arg[%d]: '%s'\n", j, current->args[j]);
		}
		else
			printf("  No arguments\n");
		printf("Input FD: %d\n", current->fd_in);
		printf("Output FD: %d\n", current->fd_out);
		printf("Status: %d\n", current->status);
		printf("Next command:\n");
		current = current->pipe;
	}
}

#pragma endregion FUNCTIONS