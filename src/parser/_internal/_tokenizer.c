/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tokenizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Delta_0ne <romain.creuzeau.pro@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:41:27 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/16 18:47:11 by Delta_0ne        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region HEADERS

#include "_parser.h"
#include "parser.h"
#include "env.h"

#pragma endregion HEADERS
#pragma region    Prototypes

extern int	_token_handler(
				t_token **tokens,
				const char *const restrict line,
				size_t *const transfer[2],
				const int len
				);

#pragma endregion Prototypes
#pragma region    FUNCTIONS

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
		return (1);
	else if (!((*idx - 1) % PARSER_ALLOC_SIZE))
	{
		(*tokens) = mm_realloc((*tokens), (*idx + PARSER_ALLOC_SIZE)
				* sizeof(t_token *));
		if (_UNLIKELY(!(*tokens)))
			return (-1);
	}
	return (0);
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

#pragma endregion FUNCTIONS