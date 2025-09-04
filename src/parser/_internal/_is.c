/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _is.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:41:27 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/04 13:19:09 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region HEADERS

#include "_parser.h"
#include "parser.h"
#include "env.h"

#pragma endregion HEADERS
#pragma region FUNCTIONS

inline int	_is_word(
	const int token
)
{
	return (token == TOKEN_WORD || token == TOKEN_CMD
		|| token == TOKEN_QUOTE || token == TOKEN_DQUOTE);
}

inline int	_is_redir(
	const int token
)
{
	return (token == TOKEN_GREATER || token == TOKEN_LESS
		|| token == TOKEN_DGREATER || token == TOKEN_DLESS);
}

inline int	_is_space(
	const char c
)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

inline int	_is_redirections(
	const char c
)
{
	return (c == '>' || c == '<' || c == '|');
}

inline int	_is_quote(
	const char c
)
{
	return (c == '\'' || c == '"');
}

#pragma endregion FUNCTIONS