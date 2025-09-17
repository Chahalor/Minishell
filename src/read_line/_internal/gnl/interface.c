/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:39:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 10:43:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Internals |----- */
#include "get_next_line.h"

/**
 * @brief		Get the next line from the file descriptor.
 * 
 * @param fd	The file descriptor to read from.
 * 
 * @return	char* The line read from the file descriptor.
 * @retval		NULL Error occurred.
 * @retval 		the line read from the file descriptor.
 * 
 * @note This fonction read in evry file descriptor lower than MAX_FD.
 * 
 * @version	2.0
 */
char	*get_next_line(
	const int fd
)
{
	static t_storage	storage[MAX_FD] = {0};
	int					out;
	char				*result;

	if (__builtin_expect(fd < 0 || fd >= MAX_FD, 0))
		return (NULL);
	while (storage[fd].status >= 0 && storage[fd].status != 1)
	{
		out = _loop(&storage[fd], fd);
		if (out < 0)
			return (_reset(&storage[fd]), NULL);
	}
	result = storage[fd].line;
	_reset(&storage[fd]);
	return (result);
}

/**
 * @brief		Get the next line from the file descriptor and remove the
 * 				newline character at the end of the line.
 * 
 * @param		fd The file descriptor to read from.
 * 
 * @return	char* The line read from the file descriptor.
 * @retval		NULL Error occurred.
 * @retval 		the line read from the file descriptor.
 * 
 * @version	1.0
 */
char	*gnl(
	const int fd
)
{
	char			*line;
	register int	len;

	line = get_next_line(fd);
	if (__builtin_expect(!line, 0))
		return (NULL);
	len = -1;
	while (line[++len] != '\n' && line[len] != '\0')
		;
	if (line[len] == '\n')
		line[len] = '\0';
	return (line);
}

/** */
int	count_lines(
	const int fd
)
{
	int				count;
	char			buffer[BUFFER_SIZE + 1];
	ssize_t			bytes_read;
	register int	i;

	if (__builtin_expect(fd < 0 || fd >= MAX_FD, 0))
		return (-1);
	count = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		i = -1;
		while (++i < bytes_read)
			if (__builtin_expect(buffer[i] == '\n', 0))
				++count;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (count);
}
