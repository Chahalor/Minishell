/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sub_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:38:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 11:06:27 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region HEADERS

#include "_parser.h"
#include "parser.h"
#include "env.h"

#pragma endregion HEADERS
#pragma region    

extern t_token	*_quote_handling(
					const char *line,
					size_t *i,
					size_t len
					);

#pragma endregion Prototypes

extern inline void	__quotes(
	const char *line,
	size_t *const i,
	size_t len,
	t_token *tok
)
{
	t_token	*tmp;
	char	*chr_tmp;
	char	*join;

	if (_UNLIKELY(!tok))
		return ;
	tmp = _quote_handling(line, i, len);
	if (_UNLIKELY(!tmp))
		return ((void)(tok->type = PARSER_ERR_MEMORY_ALLOCATION));
	if (tmp && tmp->type == TOKEN_DQUOTE)
		chr_tmp = env_expand(tmp->value);
	else if (tmp && tmp->type == TOKEN_QUOTE)
		chr_tmp = tmp->value;
	else
	{
		tok->type = tmp->type;
		return (mm_free(tmp->value), mm_free(tmp));
	}
	join = ft_strcat(tok->value, chr_tmp);
	mm_free(tok->value);
	tok->value = join;
	return (mm_free(tmp->value), mm_free(tmp), mm_free(chr_tmp));
}

extern inline void	__words(
	const char *line,
	size_t *const i,
	size_t len,
	t_token *tok
)
{
	const int	start = *i;
	char		*chr_tmp;
	char		*expanded;
	int			size;

	(void)len;
	while (*i > 0 && line[*i] && !_is_space(line[*i]) \
			&& !_is_redirections(line[*i]) && !_is_quote(line[*i]))
		++(*i);
	size = *i - start;
	chr_tmp = mm_alloc(size + 1);
	if (_UNLIKELY(!chr_tmp))
		return ;
	ft_memcpy(chr_tmp, line + start, size);
	chr_tmp[size] = '\0';
	expanded = env_expand(chr_tmp);
	mm_free(chr_tmp);
	chr_tmp = expanded;
	chr_tmp = ft_strcat(tok->value, chr_tmp);
	mm_free(expanded);
	mm_free(tok->value);
	tok->value = chr_tmp;
}

#pragma endregion FUNCTIONS