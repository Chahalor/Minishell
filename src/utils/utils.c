/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:04:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/19 12:09:02 by nduvoid          ###   ########.fr       */
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
	const char *const restrict s1,
	const char *const restrict s2,
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
	const char *const restrict str
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

__attribute__((always_inline, used))
//	(-hidden-)
extern inline void	_neutral(\
	void *restrict const area,
	const unsigned int size
)	// v.1. >>> tag: def->neutral
{
	volatile unsigned long long		*restrict	area_64b;
	volatile unsigned char	*restrict			area_8b;
	const unsigned int							len_64b = (size >> 3);
	register unsigned int						i;

	area_64b = (volatile unsigned long long *)area;
	i = 0;
	while (i++ != len_64b)
		*(area_64b++) = 0;
	i <<= 3;
	area_8b = (volatile unsigned char *)area + i;
	while (!((size - i++) >> 31))
		*(area_8b++) = 0;
}

/** */
__attribute__((always_inline, used, malloc)) inline void	*memdup(
	const void *const restrict src,
	size_t size
)
{
	void			*dup;
	register size_t	i;

	dup = mm_alloc(size);
	if (__builtin_expect(!dup, unexpected))
		return (NULL);
	i = -1;
	while (++i < size)
		((char *)dup)[i] = ((char *)src)[i];
	return (dup);
}

/** */
__attribute__((always_inline, used)) inline void	ft_memcpy(
	void *const restrict dst,
	const void *restrict src,
	size_t size
)
{
	register size_t	i;

	if (__builtin_expect(!dst || !src, unexpected))
		return ;
	i = -1;
	while (++i < size)
		((char *)dst)[i] = ((char *)src)[i];
	return ;
}

#pragma endregion Fonctions