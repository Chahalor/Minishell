/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _lexer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:19:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/04 16:12:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_lexer.h"

/* -----| Modules   |----- */
#include "lexer.h"

#pragma endregion Header
#pragma region Fonctions

/*

static inline int	_is_space(
	const char c
)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

static inline int is_operator(
	const char c
)
{
	return (c == '<' || c == '>' || c == '|');
}

static t_token	*new_token(
	t_token_type type,
	const char *const restrict start,
	size_t len
)
{
	t_token	*token;
	
	token = malloc(sizeof(t_token));
	if (_UNLIKELY(!token))
		return (NULL);
	else
	{
		*token = (t_token) {
			.type = type,
			.value = memdup(start, len),
			.next = NULL
		};
	}
	return (token);
}

static void	add_token(
	t_token **head,
	t_token *new
)
{
	t_token	*tmp;
	
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_token	*lex(
	const char *const restrict input
)
{
	t_token			*tokens;
	register int	i;
	register int	start;

	tokens = NULL;
	i = 0;
	while (input[i])
	{
		if (_is_space(input[i]))
		{
			++i;
			continue;
		}
		if (input[i] == '|')
			add_token(&tokens, new_token(TOKEN_PIPE, input + i++, 1));
		else if (input[i] == '<')
		{
			if (input[i + 1] == '<')
			{
				add_token(&tokens , new_token(TOKEN_REDIR_HEREDOC,
					input + i, 2));
				i += 2;
			}
			else
				add_token(&tokens, new_token(TOKEN_REDIR_IN, input + i++, 1));
		}
		else if (input[i] == '>')
		{
			if (input[i + 1] == '>')
			{
				add_token(&tokens, new_token(TOKEN_REDIR_APPEND, input + i, 2));
				i += 2;
			}
			else
				add_token(&tokens, new_token(TOKEN_REDIR_OUT, input + i++, 1));
		}
		else
		{
			start = i;
			while (input[i] && !_is_space(input[i]) && !is_operator(input[i]))
				++i;
			add_token(&tokens, new_token(TOKEN_WORD, input + start, i - start));
		}
	}
	return tokens;
}

void	print_tokens(
	t_token *tok
)
{
	while (tok)
	{
		ft_printf("TOKEN_%d: \"%s\"\n", tok->type, tok->value);
		tok = tok->next;
	}
}
	
*/

#pragma endregion Fonctions