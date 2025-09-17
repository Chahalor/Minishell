/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _handlers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:57:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 11:05:33 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region HEADERS

#include "_parser.h"
#include "parser.h"
#include "env.h"

#pragma endregion HEADERS
#pragma region    

extern void	__quotes(
				const char *line,
				size_t *const i,
				size_t len,
				t_token *tok
				);

extern void	__words(
				const char *line,
				size_t *const i,
				size_t len,
				t_token *tok
				);

#pragma endregion Prototypes
#pragma region FUNCTIONS

extern t_token	*_quote_handling(
	const char *line,
	size_t *i,
	size_t len
)
{
	register size_t	start;
	t_token			*tok;
	char			delim;
	size_t			end;
	int				closed;

	delim = line[*i];
	start = ++(*i);
	while (*i < len && line[*i] != delim)
		++(*i);
	end = *i;
	closed = (*i < len && line[*i] == delim);
	if (delim == '\'')
		tok = token_new(line + start, TOKEN_QUOTE, end - start);
	else
		tok = token_new(line + start, TOKEN_DQUOTE, end - start);
	if (_LIKELY(closed))
		++(*i);
	else
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

	if (_UNLIKELY(!tokens || !line || !transfer))
		return (NULL);
	while (*i < len && !_is_space(line[*i]) && !_is_redirections(line[*i]) \
			&& !_is_quote(line[*i]))
		++(*i);
	if (!idx)
		tok = token_new(line + start, TOKEN_CMD, *i - start);
	else if (tokens[idx - 1] && (tokens[idx - 1]->type == TOKEN_PIPE))
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

	if (_UNLIKELY(!tokens || !line || !transfer))
		return (-1);
	if (line[*i] == '|')
		tokens[(*idx)++] = token_new("|", TOKEN_PIPE, 1 + 0 * ++(*i));
	else if (line[*i] == '\'' || line[*i] == '"')
		tokens[(*idx)++] = _quote_handling(line, i, len);
	else if (line[*i] == '>' || line[*i] == '<')
		tokens[(*idx)++] = _redirect_handling(line, i, idx);
	else
		tokens[(*idx)++] = _word_handling(line, transfer, \
										(const t_token **)tokens, len);
	if (_UNLIKELY(!tokens[*idx - 1]))
		return (-1);
	while (line[*i] && !_is_space(line[*i]) && !_is_redirections(line[*i]) \
		&& !(tokens[*idx - 1]->type > PARSER_ERR_NONE))
	{
		if (_is_quote(line[*i]))
			__quotes(line, i, len, tokens[*idx - 1]);
		else
			__words(line, i, len, tokens[*idx - 1]);
	}
	return (0);
}
