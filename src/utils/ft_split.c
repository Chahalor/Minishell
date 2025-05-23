/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:51:43 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/23 15:44:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "utils.h"

/* -----| Modules   |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((always_inline, used)) static inline char	**_allocing(
	const char *const restrict s,
	const char c
)
{
	register int	words;
	register int	i;
	register int	j;
	char			**result;

	words = 0;
	i = -1;
	while (s[++i])
		if (s[i] == c)
			++words;
	result = mm_alloc(sizeof(char *) * (words + 2));
	if (__builtin_expect(!result, unexpected))
		return (NULL);
	j = -1;
	while (j <= words)
		result[++j] = NULL;
	return (result);
}

int	_split(
	char **result,
	const char *const restrict s,
	const char c
)
{
	register int	i;
	register int	j;
	register int	k;

	i = -1;
	
}

/** */
char **ft_split(
	const char *const restrict s,
	const char c
)
{
	char		**result;

	if (__builtin_expect(!s, unexpected))
		return (NULL);
	result = (char **)_allocing(s, c);
	if (__builtin_expect(!result, unexpected))
		return (NULL);
	_split(s, c, result);
	return (result);
}

#pragma endregion Fonctions