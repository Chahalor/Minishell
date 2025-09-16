/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tokenizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:41:27 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/16 10:39:47 by nduvoid          ###   ########.fr       */
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

static inline int	_logic(
	t_token **tokens,
	const char *const restrict line,
	size_t *const transfer[2],
	const int len
)
{
	size_t	idx;

	idx = *transfer[1];
	_token_handler(tokens, line, transfer, len);
	if (!tokens[idx - 1] || tokens[idx - 1]->type > PARSER_ERR_NONE)
		return (1);
	else if (!((idx) % PARSER_ALLOC_SIZE))
		tokens = mm_realloc(tokens, (idx + PARSER_ALLOC_SIZE)
				* sizeof(t_token *));
	return (0);
}

t_token	**tokenize_line(
	const char *const restrict line,
	int *const restrict count
)
{
	register const size_t	len = ft_strlen(line);
	t_token					**tokens;
	size_t					idx;
	size_t					i;

	idx = 0;
	tokens = mm_alloc(PARSER_ALLOC_SIZE * sizeof(t_token *));
	i = 0;
	while (i < len)
	{
		if (_is_space(line[i]))
			++i;
		else
		{
			_token_handler(tokens, line, (size_t *[2]){&i, &idx}, len);
			if (!tokens[idx - 1] || tokens[idx - 1]->type > PARSER_ERR_NONE)
				break ;
			else if (!((idx) % PARSER_ALLOC_SIZE))
				tokens = mm_realloc(tokens, (idx + PARSER_ALLOC_SIZE)
						* sizeof(t_token *));
		}
	}
	*count = idx;
	return (tokens);
}

#pragma endregion FUNCTIONS