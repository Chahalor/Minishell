/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sub_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:38:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/16 20:11:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region HEADERS

#include "_parser.h"
#include "parser.h"
#include "env.h"

#pragma endregion HEADERS
#pragma region    FUNCTIONS

extern inline void	__words(
	const char *line,
	size_t *const i,
	size_t len,
	t_token *tok
)
{
	char	*chr_tmp;
	char	*expanded;
	int		size;

	(void)len;
	size = *i;
	while (*i && line[*i] && !_is_space(line[*i])
		&& !_is_redirections(line[*i]) && !_is_quote(line[*i]))
		++(*i);
	size = *i - size;
	chr_tmp = mm_alloc(size + 1);
	if (_UNLIKELY(!chr_tmp))
		return ;
	ft_memcpy(chr_tmp, line + *i - size, size);
	chr_tmp[size] = '\0';
	expanded = env_expand(chr_tmp);
	mm_free(chr_tmp);
	chr_tmp = expanded;
	chr_tmp = ft_strcat(tok->value, chr_tmp);
	mm_free(tok->value);
	tok->value = chr_tmp;
}

#pragma endregion FUNCTIONS