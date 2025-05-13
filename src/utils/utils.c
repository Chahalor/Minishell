/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:04:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/13 08:20:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
#include "utils.h"

/* -----| Modules  |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((always_inline, used)) inline int	ft_strncmp(
	const char *restrict s1,
	const char *restrict s2,
	size_t n
)
{
	register size_t	i;

	if (__builtin_expect(!s1 || !s2, unexpected))
		return (0);
	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/** */
__attribute__((always_inline, used)) inline int	ft_strlen(
	const char *restrict str
)
{
	register int	i;

	if (__builtin_expect(!str, unexpected))
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

/** */
__attribute__((always_inline, used, malloc)) inline char	*ft_strdup(
	const char *restrict str
)
{
	register int	i;
	char			*dup;

	i = -1;
	dup = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	while (str[++i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

/** */
__attribute__((always_inline, used, malloc)) inline void	*memdup(
	const void *restrict src,
	size_t size
)
{
	void			*dup;
	register size_t	i;

	dup = mm_alloc(size);
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < size)
		((char *)dup)[i] = ((char *)src)[i];
	return (dup);
}
#pragma endregion Fonctions