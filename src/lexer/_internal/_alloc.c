/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _alloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:28:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/03 11:02:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region HEADERS

#include "_lexer.h"
#include "lexer.h"
#include "env.h"

#pragma endregion HEADERS
#pragma region FUNCTIONS

/* Create a new token */
inline t_token	*token_new(
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

#pragma endregion FUNCTIONS