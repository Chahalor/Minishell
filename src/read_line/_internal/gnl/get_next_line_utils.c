/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:35:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/01 14:36:44 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "get_next_line.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Reallocate the line buffer to a new size. If the line buffer is
 * 			NULL, it will be allocated with the new size. If the new size
 * 			is 0, the line buffer will be mm_freed and NULL will be returned.
 * 
 * @param line		The line buffer to reallocate.
 * @param old_size	The old size of the line buffer.
 * @param new_size	The new size of the line buffer.
 * 
 * @return	char* The reallocated line buffer.
 * @retval		NULL Error occurred.
 * @retval		the reallocated line buffer.
 * 
 * @version	1.0
 */
__attribute__((visibility("hidden"), cold)) char	*_gnl_realloc(
	char *const line,
	const size_t old_size,
	const size_t new_size
)
{
	char			*new_line;
	register size_t	i;

	if (!line)
		return (mm_alloc(new_size));
	else if (!new_size)
		return (mm_free(line), NULL);
	else
	{
		new_line = mm_alloc(new_size);
		if (!new_line)
			return (mm_free(line), NULL);
		i = 0;
		while (i < old_size && i < new_size)
		{
			new_line[i] = line[i];
			++i;
		}
		mm_free(line);
		while (i < new_size)
			new_line[i++] = '\0';
	}
	return (new_line);
}

/**
 * @brief		Set the memory area to zero. This function is used to clear the
 * 				memory area before using it.
 * 
 * @param area	The memory area to set to zero.
 * @param size	The size of the memory area.
 * 
 * @return	void
 * 
 * @version	1.0
 */
__attribute__((visibility("hidden"), cold)) void	_gnl_bzero(
	void *const restrict area,
	const size_t size
)
{
	register size_t	i;

	i = -1;
	while (++i < size)
		((unsigned char *)area)[i] = 0;
}

/**
 * @brief	Copy the memory area from src to dst. This function is used to
 * 			copy the memory area from one location to another.
 * 
 * @param dst	The destination memory area.
 * @param src	The source memory area.
 * @param size	The size of the memory area.
 * 
 * @return	void* The destination memory area.
 * @retval		NULL Error occurred.
 * @retval		the destination memory area.
 * 
 * @version	1.0
*/
__attribute__((visibility("hidden"), cold)) void	*_gnl_memmove(
	void *const restrict dst,
	const void *const restrict src,
	size_t size
)
{
	register int	i;

	if (dst == src || size == 0)
		return (dst);
	if (dst < src)
	{
		i = -1;
		while (++i < (int)size)
			((char *)dst)[i] = ((char *)src)[i];
	}
	else
	{
		i = size;
		while (--i >= 0)
			((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}

/**
 * @brief	Reset the storage structure to its initial state. This function is
 * 			used to clear the storage structure before using it.
 * 
 * @param storage The storage structure to reset.
 * 
 * @return	void
 * 
 * @version	1.0
 */
void	_reset(
	t_storage *const storage
)
{
	if (!storage->storage_len)
		_gnl_bzero(storage->storage, BUFFER_SIZE);
	storage->byte_read = 0;
	storage->line_len = 0;
	storage->status = 0;
	storage->line = NULL;
}

#pragma endregion Fonctions