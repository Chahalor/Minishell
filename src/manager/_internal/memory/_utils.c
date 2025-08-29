/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:33:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/29 11:51:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Interface |----- */
#include "mmanager.h"

/* -----| Internal  |----- */
#include "_mm.h"

#pragma endregion Headers
#pragma region Functions

/** 
 * @brief	Hash function to get the index of the pointer in the bucket
 * 
 * @param	ptr	Pointer to hash
 * 
 * @return	Hash value
 * 
 * @details	Uses the pointer value to generate a hash value
*/
__attribute__((always_inline, used)) inline int	_hash(
	const void *restrict ptr
)
{
	size_t	x;

	x = (size_t)ptr;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = (x >> 16) ^ x;
	return ((int)(x % MM_BUCKET_SIZE));
}

/**
 * @brief	Copy memory from src to dst
 * 
 * @param	dst	Destination pointer
 * @param	src	Source pointer
 * @param	n	Number of bytes to copy
 * 
 * @return	Destination pointer
*/
__attribute__((always_inline, used)) inline void	*mm_memcpy(
	void *restrict dst,
	const void *restrict src,
	register const size_t n
)
{
	register size_t	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	if (n == 0)
		return (dst);
	i = -1;
	while (++i < n)
		((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}

/** */
__attribute__((always_inline, used)) inline int	_mm_max(
	const size_t a,
	const size_t b
)
{
	return (a * (a >= b) + b * (b > a));
}

__attribute__((always_inline, used)) inline void	_mm_dump(
	t_mm_node *restrict bucket
)
{
	int						i;
	t_mm_node	*restrict	current;

	i = -1;
	while (++i < MM_BUCKET_SIZE)
	{
		current = bucket[i].next;
		if (current)
		{
			printf("Bucket %d:\n", i);
			while (current)
			{
				printf("  - %p (%zu bytes)\n", current->ptr,
					current->alloced);
				current = current->next;
			}
		}
	}
}

#pragma endregion Functions