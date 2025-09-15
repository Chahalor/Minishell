/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:41:27 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/15 14:25:26 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region HEADERS

#include "_parser.h"
#include "parser.h"
#include "env.h"

#pragma endregion HEADERS
#pragma region FUNCTIONS

extern volatile sig_atomic_t	g_last_signal;

static inline const char	*show_type(
	const int type
)
{
	static const char	*messages[15] = {\
		[TOKEN_CMD] = BLUE "CMD" RESET, \
		[TOKEN_PIPE] = CYAN "PIPE" RESET, \
		[TOKEN_QUOTE] = YELLOW "QUOTE" RESET, \
		[TOKEN_DQUOTE] = GREEN "DQUOTE" RESET, \
		[TOKEN_GREATER] = RED "GREATER" RESET, \
		[TOKEN_LESS] = MAGENTA "LESS" RESET, \
		[TOKEN_DGREATER] = BLUE "DGREATER" RESET, \
		[TOKEN_DLESS] = BLUE "DLESS" RESET, \
		[TOKEN_WORD] = WHITE "WORD" RESET, \
		[PARSER_ERR_NONE] = GREEN "NO ERROR" RESET, \
		[PARSER_ERR_MISSING_QUOTE] = RED "MISSING QUOTE" RESET, \
		[PARSER_ERR_UNEXPECTED_TOKEN] = RED "UNEXPECTED TOKEN" RESET, \
		[PARSER_ERR_BROKEN_PIPE] = RED "BROKEN PIPE" RESET, \
		[PARSER_ERR_INVALID_REDIRECTION] = RED "INVALID REDIRECTION" RESET, \
		[PARSER_ERR_MEMORY_ALLOCATION] = RED "MEMORY ALLOCATION" RESET \
	};

	return (messages[type % (PARSER_ERR_MEMORY_ALLOCATION + 1)]);
}

__attribute_maybe_unused__
static inline void	__show_error(
	const t_token **tok,
	int index,
	int error
)
{
	const int	_start = index;

	ft_fprintf(2, "Syntax error near unexpected token: %s\n\t\t",
		show_type(error));
	index = (index - 5) * (index > 5);
	while (index < _start)
		ft_fprintf(2, "%s ", tok[index++]->value);
	ft_fprintf(2, RED " '%s'" RESET, tok[_start]->value);
	while (tok[++index] && index < _start + 5)
		ft_fprintf(2, " %s", tok[index]->value);
	ft_fprintf(2, "\n");
	g_last_signal = 2;
}

static inline int	__first_check(
	t_token **tok,
	t_tok_error *err
)
{
	if (tok[0] && tok[0]->type == TOKEN_PIPE)
		*err = (t_tok_error){.error = PARSER_ERR_BROKEN_PIPE, .token = tok[0]};
	return (err->error);
}

static inline int	__check_redir(
	t_token **tok,
	t_tok_error *err,
	int *const restrict last_token,
	const int i
)
{
	if (tok[i] && _is_redir(tok[i]->type) && !tok[i + 1])
		err->error = PARSER_ERR_UNEXPECTED_TOKEN;
	else if (i && _is_redir(tok[i]->type) && tok[i]->type != TOKEN_DLESS && !_is_word(tok[i - 1]->type))
		err->error = PARSER_ERR_UNEXPECTED_TOKEN;
	else if (_is_redir(tok[i]->type) && tok[i]->type != TOKEN_DLESS && !i)
		err->error = PARSER_ERR_UNEXPECTED_TOKEN;
	else if (i && tok[i]->type == TOKEN_PIPE && *last_token == TOKEN_PIPE)
		*err = (t_tok_error){.error = PARSER_ERR_BROKEN_PIPE, .token = tok[i]};
	else if (i && (((_is_redir(tok[i]->type) && _is_redir(*last_token)) \
			|| (_is_redir(tok[i]->type) && (tok[i + 1]
						&& _is_word(tok[i + 1]->type) != 1)))))
		err->error = PARSER_ERR_UNEXPECTED_TOKEN;
	else if (tok[i]->type == TOKEN_DLESS && !tok[i + 1])
		err->error = PARSER_ERR_UNEXPECTED_TOKEN;
	if (err->error != PARSER_ERR_NONE)
		err->token = tok[i];
	return (err->error != PARSER_ERR_NONE);
}

inline int	check_tokens(
	t_token **tok
)
{
	register int	i;
	t_tok_error		err;
	int				last_token;

	err.error = PARSER_ERR_NONE;
	__first_check(tok, &err);
	i = -1;
	while (tok[++i] && err.error == PARSER_ERR_NONE)
	{
		if (tok[i]->type >= PARSER_ERR_NONE)
		{
			err.error = (tok[i]->type);
			err.token = tok[i];
			break ;
		}
		else if (__check_redir(tok, &err, &last_token, i))
			break ;
		last_token = tok[i]->type;
	}
	if (i && err.error == PARSER_ERR_NONE && tok[i - 1]->type == TOKEN_PIPE)
		err = (t_tok_error){.error = PARSER_ERR_BROKEN_PIPE, .token = tok[--i]};
	if (err.error != PARSER_ERR_NONE)
		__show_error((const t_token **)tok, i, err.error);
	return (err.error);
}

#pragma endregion FUNCTIONS