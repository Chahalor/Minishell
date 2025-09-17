/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:04:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 10:49:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Internals |----- */
#include "utils.h"

/* -----| Modules  |----- */
	//...

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
	register unsigned int	i;

	i = 0;
	while (i < size)
		((char *)area)[i++] = 0;
}

/** */
__attribute__((always_inline, used, malloc))
inline void	*memdup(
	const void *const restrict src,
	size_t size
)
{
	char			*dup;

	if (_UNLIKELY(!src || !size))
		return (NULL);
	dup = (char *)mm_alloc(size);
	if (__builtin_expect(!dup, unexpected))
		return (NULL);
	ft_memcpy(dup, src, size);
	return ((void *)dup);
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
