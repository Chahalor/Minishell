/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:39:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/01 14:37:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "get_next_line.h"
#include "ft_printf.h"

#pragma endregion Header
#pragma region Prototypes

/* -----| Internals |----- */

extern char	*_gnl_realloc(
				char *const line,
				const size_t old_size,
				const size_t new_size
				);

extern void	_gnl_bzero(
				void *const restrict area,
				const size_t size
				);

extern char	*_gnl_memmove(
				void *const restrict dst,
				const void *const restrict src,
				size_t size
				);

#pragma endregion Prototypes
#pragma region Fonctions

/**
 * @brief		Add a character to the line buffer. If the line buffer is full,
 * 				it will be reallocated to accommodate the new character.
 * 
 * @param storage	The storage structure to store the line.
 * @param c		The character to add to the line buffer.
 * 
 * @return	char* The reallocated line buffer.
 * @retval		NULL Error occurred.
 * @retval 		0 Character added successfully.
 * 
 * @version	1.0
*/
__attribute__((always_inline, used)) static inline char	_add(
	t_storage *const storage,
	const char c
)
{
	if (__builtin_expect(!storage->line
			|| !(storage->line_len % GNL_ALLOC_SIZE), 0))
	{
		storage->line = _gnl_realloc(storage->line, storage->line_len,
				storage->line_len + GNL_ALLOC_SIZE);
		if (!storage->line)
			return (-1);
	}
	storage->line[storage->line_len++] = c;
	storage->line[storage->line_len] = '\0';
	return (0);
}

/**
 * @brief		Read BUFFER_SIZE bytes from the file descriptor fd and store
 * 				them in the storage structure. If it needs to be reallocated,
 * 				it will be done.
 * 
 * @param fd		The file descriptor to read from.
 * @param storage	The storage structure to store the read bytes.
 * 
 * @return	nt the line status:
 * @retval		-1 Error occurred.
 * @retval		+0 Partial line read.
 * @retval		+1 '\n' found
 * @retval		+2 End of file reached.
 * 
 * @version	1.0
*/
__attribute__((used)) static inline char	_read(
	const int fd,
	t_storage *const storage
)
{
	storage->byte_read = read(fd, storage->storage, BUFFER_SIZE);
	if (storage->byte_read < 0)
		return (storage->status = -1);
	else if (storage->byte_read == 0)
		return (storage->status = 2);
	else
	{
		storage->storage[storage->byte_read] = '\0';
		storage->storage_len = storage->byte_read;
	}
	return (storage->status = 0);
}

/**
 * @brief		Get the next line from the storage structure. It will read it
 * 				from the storage structure and store it in the line buffer.
 * 
 * @param storage	The storage structure to store the read bytes.
 * 
 * @return	int the line status:
 * @retval -1	Error occurred.
 * @retval +0	Partial line read.
 * @retval +1	'\n' found
 * 
 * @version	1.0
*/
__attribute__((used)) static inline char	_get(
	t_storage *const storage
)
{
	register ssize_t	i;
	char				result;

	i = -1;
	while (++i < storage->storage_len && storage->storage[i] != '\n')
		if (__builtin_expect(_add(storage, storage->storage[i]) < 0, 0))
			return (-1);
	_gnl_memmove(storage->storage, storage->storage + i + 1,
		storage->storage_len - i - 1);
	_gnl_bzero(storage->storage + storage->storage_len - i - 1,
		BUFFER_SIZE - storage->storage_len + i + 1);
	storage->storage_len -= i + 1;
	if (i != storage->storage_len)
	{
		_add(storage, '\n');
		_add(storage, '\0');
		result = 1;
		storage->status = 1;
	}
	else
		result = 0;
	return (result);
}

/**
 * @brief	Main loop of the get_next_line function. It will read from the
 * 			file descriptor and store the bytes in the storage structure.
 * 
 * @param storage	The storage structure to store the read bytes.
 * @param fd		The file descriptor to read from.
 * 
 * @return	int the line status:
 * @retval -1	Error occurred.
 * @retval +0	Partial line read.
 * @retval +1	'\n' found
 * @retval +2	End of file reached.
*/
__attribute__((used)) inline char	_loop(
	t_storage *const storage,
	const int fd
)
{
	if (storage->storage_len <= 0)
	{
		_read(fd, storage);
		if (__builtin_expect(storage->status < 0, 0))
		{
			mm_free(storage->line);
			_gnl_bzero(storage, sizeof(t_storage));
			return (storage->status);
		}
	}
	if (!storage->byte_read && !storage->storage[0])
		return (storage->status = 1);
	_get(storage);
	if (__builtin_expect(storage->status < 0, 0))
	{
		mm_free(storage->line);
		_gnl_bzero(storage, sizeof(t_storage));
		return (storage->status);
	}
	return (storage->status);
}

#pragma endregion Fonctions