/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmanager.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:11:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/15 15:50:35 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Interface |----- */
#include "mmanager.h"

/* -----| Internal  |----- */
#include "_internal/memory/_mm.h"
#include "ft_printf.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((malloc, used)) void	*mm_alloc(
	const size_t size
)
{
	t_mm_node		*node;
	char			*base;
	register size_t	i;

	if (size < 1)
		return (NULL);
	node = (t_mm_node *)malloc(sizeof(t_mm_node) + size);
	if (__builtin_expect(!node, 0))
		return (NULL);
	base = (char *)((char *)node + sizeof(t_mm_node));
	i = 0;
	while (i < size)
		base[i++] = 0;
	node->ptr = base;
	node->allocated = size;
	node->next = NULL;
	_mm_store(node, mm_add);
	return (node->ptr);
}

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
__attribute__((malloc, used)) void	*mm_realloc(
	void *restrict ptr,
	const size_t nsize
)
{
	size_t			cpsize;
	t_mm_node		*node;
	void			*new_ptr;

	if (ptr == NULL)
		return (mm_alloc(nsize));
	if (nsize < 1)
		return (mm_free(ptr), NULL);
	node = _mm_store(ptr, mm_find);
	if (!node)
		return (mm_alloc(nsize));
	new_ptr = mm_alloc(nsize);
	if (!new_ptr)
		return (NULL);
	cpsize = _mm_min(node->allocated, nsize);
	mm_memcpy(new_ptr, ptr, cpsize);
	mm_free(node->ptr);
	return (new_ptr);
}

/** */
__attribute__((used)) void	mm_free(
	void *restrict ptr
)
{
	if (ptr == NULL)
		return ;
	_mm_store(ptr, mm_freeing);
}

/** */
__attribute__((used)) void	mm_destroy(void)
{
	_mm_store(NULL, mm_free_all);
}

#pragma endregion Functions