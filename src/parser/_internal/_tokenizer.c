/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tokenizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:41:27 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 13:04:51 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parser.h"
#include "parser.h"
#include "env.h"

extern int	_token_handler(
				t_token **tokens,
				const char *const restrict line,
				size_t *const transfer[2],
				const int len
				);

static int	tokenize_alloc(
	t_token ***tokens,
	const size_t idx
)
{
	t_token			**tmp;
	register size_t	i;

	if (!(idx % PARSER_ALLOC_SIZE))
	{
		tmp = mm_alloc((idx + PARSER_ALLOC_SIZE) * sizeof(t_token *));
		if (_UNLIKELY(!tmp))
			return (-1);
		i = 0;
		while (i != idx)
		{
			tmp[i] = (*tokens)[i];
			++i;
		}
		mm_free(*tokens);
		*tokens = tmp;
	}
	return (0);
}

static int	tokenize_line_logic(
	const char *const restrict line,
	t_token ***tokens,
	size_t *transfer[2],
	const size_t len
)
{
	size_t	*idx;
	size_t	*i;

	i = transfer[0];
	idx = transfer[1];
	if (_UNLIKELY(\
			_token_handler((*tokens), line, (size_t *[2]){i, idx}, len) \
			|| (!(*tokens)[*idx - 1] \
				|| (*tokens)[*idx - 1]->type > PARSER_ERR_NONE)))
		return (+1);
	else if (tokenize_alloc(tokens, *idx) != 0)
		return (-1);
	else
		return (+0);
}

t_token	**tokenize_line(
	const char *const restrict line,
	int *const restrict count
)
{
	const size_t	len = ft_strlen(line);
	t_token			**tokens;
	size_t			idx;
	size_t			i;
	char			code;

	tokens = mm_alloc(PARSER_ALLOC_SIZE * sizeof(t_token *));
	if (_UNLIKELY(!tokens))
		return (*count = 0, NULL);
	code = 0;
	idx = 0;
	i = 0;
	while (i < len && !code)
	{
		if (_is_space(line[i]))
			++i;
		else
			code = tokenize_line_logic(line, &tokens, \
										(size_t *[2]){&i, &idx}, len);
		if (code == -1)
			return (*count = 0, NULL);
	}
	tokens[idx] = NULL;
	return (*count = idx, tokens);
}
