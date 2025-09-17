/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tokenizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:41:27 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 10:44:04 by nduvoid          ###   ########.fr       */
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

t_token	**tokenize_line(
	const char *const restrict line,
	int *const restrict count
)
{
	register const size_t	len = ft_strlen(line);
	t_token					**tokens;
	size_t					idx;
	size_t					i;

	tokens = mm_alloc(PARSER_ALLOC_SIZE * sizeof(t_token *));
	idx = 0;
	i = 0;
	while (i < len)
	{
		if (_is_space(line[i]))
			++i;
		else
		{
			if (_UNLIKELY(\
					_token_handler(tokens, line, (size_t *[2]){&i, &idx}, len) \
					|| (!tokens[idx - 1] \
						|| tokens[idx - 1]->type > PARSER_ERR_NONE)))
				break ;
			else if (!((idx - 1) % PARSER_ALLOC_SIZE))
				tokens = mm_realloc(tokens, (idx + PARSER_ALLOC_SIZE)
						* sizeof(t_token *));
		}
	}
	return (*count = idx, tokens);
}
