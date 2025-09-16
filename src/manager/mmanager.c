/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmanager.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:11:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/16 12:16:05 by rcreuzea         ###   ########.fr       */
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

/** */
__attribute__((malloc, used)) void	*mm_realloc(
	void *restrict ptr,
	const size_t nsize
)
{
	void			*new_ptr;
	register int 	cpsize;

	if (ptr == NULL)
		return (mm_alloc(nsize));
	else if (nsize < 1)
		return (mm_free(ptr), NULL);
	new_ptr = mm_alloc(nsize);
	if (!new_ptr)
		return (NULL);
	cpsize = 0;
	while (((char *)ptr)[cpsize])
		++cpsize;
	mm_memcpy(new_ptr, ptr, cpsize);
	mm_free(ptr);
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