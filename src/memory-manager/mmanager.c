/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmanager.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:11:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/11 15:28:31 by nduvoid          ###   ########.fr       */
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
__attribute__((malloc)) void	*mm_alloc(
	const size_t size
)
{
	t_mm_node	*node;

	if (size < 1)
		return (NULL);
	node = (t_mm_node *)malloc(sizeof(t_mm_node) + size);
	if (node == NULL)
		return (NULL);
	node->ptr = (void *)(node + 1);
	node->next = NULL;
	_mm_store(node, mm_add);
	return (node->ptr);
}

/** */
__attribute__(()) void	mm_free(
	void *restrict ptr
)
{
	if (ptr == NULL)
		return ;
	_mm_store(ptr, mm_freeing);
}

/** */
__attribute__(()) void	mm_destroy(void)
{
	_mm_store(NULL, mm_free_all);
}

#pragma endregion Functions