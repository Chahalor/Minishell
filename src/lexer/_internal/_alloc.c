/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _alloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:28:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/29 11:51:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region HEADERS

#include "_lexer.h"
#include "lexer.h"

#pragma endregion HEADERS
#pragma region FUNCTIONS

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
	if (_UNLIKELY(!tok))
		return (NULL);
	tok->value = mm_alloc(size + 1);
	if (_UNLIKELY(!tok->value))
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
	size_t len
)
{
	register size_t	start;
	t_token			*tok;
	char			delim;

	delim = line[*i];
	start = ++(*i);
	while (*i < len && line[*i] != delim)
		++(*i);
	if (delim == '\'')
		tok = token_new(line + start, TOKEN_QUOTE, (*i)++ - start);
	else
		tok = token_new(line + start, TOKEN_DQUOTE, (*i)++ - start);
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

	while (*i < len && !_is_space(line[*i])
		&& line[*i] != '|' && line[*i] != '<' && line[*i] != '>')
		++(*i);
	if (!idx)
		tok = token_new(line + start, TOKEN_CMD, *i - start);
	else if (idx && tokens[idx - 1] && (tokens[idx - 1]->type == TOKEN_PIPE))
		tok = token_new(line + start, TOKEN_CMD, *i - start);
	else
		tok = token_new(line + start, TOKEN_WORD, *i - start);
	return (tok);
}

extern inline int	_token_handler(
	t_token **tokens,
	const char *const restrict line,
	size_t *const transfer[2],
	const int len
)
{
	size_t *const	i = (size_t * const)transfer[0];
	size_t *const	idx = (size_t * const)transfer[1];

	if (line[*i] == '|')
		tokens[(*idx)++] = token_new("|", TOKEN_PIPE, 1 + 0 * ++(*i));
	else if (line[*i] == '\'' || line[*i] == '"')
		tokens[(*idx)++] = _quote_handling(line, i, len);
	else if (line[*i] == '>' || line[*i] == '<')
		tokens[(*idx)++] = _redirect_handling(line, i, idx);
	else
		tokens[(*idx)++] = _word_handling(line, transfer,
				(const t_token **)tokens, len);
	return (0);
}

#pragma endregion FUNCTIONS