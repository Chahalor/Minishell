/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:20:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/17 15:21:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Interface |----- */
#include "mmanager.h"

/* -----| Internal  |----- */
#include "_mm.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline, used)) static inline void	_add_to_bucket(
	t_mm_node *restrict bucket,
	void *restrict ptr
)
{
	const t_mm_node	*restrict	node = (t_mm_node *)ptr;
	const int					index = _hash(node->ptr);
	t_mm_node		*restrict	current;

	current = &bucket[index];
	while (current && current->next)
		current = current->next;
	current->next = (t_mm_node *)node;
}

/** */
__attribute__((always_inline, used)) static inline void	_free_one(
	t_mm_node *restrict bucket,
	void *restrict ptr
)
{
	const int				index = _hash(ptr);
	t_mm_node	*restrict	current;
	t_mm_node	*restrict	last;

	current = &bucket[index];
	while (current->next && current->ptr != ptr)
	{
		last = current;
		current = current->next;
	}
	if (current->ptr == ptr)
	{
		if (last)
			last->next = current->next;
		free(current);
		current = NULL;
	}
}

/** */
__attribute__((always_inline, used)) static inline void	_free_all_bucket(
	t_mm_node *restrict bucket
)
{
	int						i;
	t_mm_node	*restrict	current;
	t_mm_node	*restrict	next;

	i = -1;
	while (++i < MM_BUCKET_SIZE)
	{
		current = bucket[i].next;
		next = NULL;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		bucket[i].next = NULL;
		bucket[i].ptr = NULL;
	}
}

/** */
__attribute__((visibility("hidden"))) void	*_mm_store(
	void *restrict ptr,
	const int access
)
{
	static t_mm_node	bucket[MM_BUCKET_SIZE] = {0};

	if (access == mm_add)
		_add_to_bucket(bucket, ptr);
	else if (access == mm_freeing)
		_free_one(bucket, ptr);
	else if (access == mm_free_all)
		_free_all_bucket(bucket);
	return (ptr);
}

#pragma endregion Functions