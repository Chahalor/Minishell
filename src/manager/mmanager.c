/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmanager.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:11:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/26 16:21:10 by nduvoid          ###   ########.fr       */
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
	register size_t	i;

	if (size < 1)
		return (NULL);
	node = (t_mm_node *)malloc(sizeof(t_mm_node) + size);
	if (__glibc_unlikely(!node))
		return (NULL);
	i = -1;
	while (++i < size)
		((char *)(node + 1))[i] = 0;
	node->ptr = (void *)(node + 1);
	node->alloced = size;
	node->next = NULL;
	_mm_store(node, mm_add);
	return (node->ptr);
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
	register size_t	i;

	if (ptr == NULL)
		return (mm_alloc(nsize));
	if (nsize < 1)
		return (mm_free(ptr), NULL);
	node = (t_mm_node *)ptr - 1;
	new_ptr = mm_alloc(nsize);
	if (new_ptr == NULL)
		return (NULL);
	cpsize = _mm_max(node->alloced, nsize);
	mm_memcpy(new_ptr, ptr, cpsize);
	i = cpsize - 1;
	while (++i < nsize)
		((char *)new_ptr)[i] = 0;
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