/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:39:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/16 08:29:21 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/** */
__attribute__((always_inline, used)) static inline char	*line_getter(
	const char *const restrict str,
	const int access
)
{
	register int	i;
	char			*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (access && str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/** */
__attribute__((always_inline, used)) static inline char	*update_remainder(
	char *str
)
{
	register int	i;
	register int	j;
	char			*remainder;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
	{
		free(str);
		return (NULL);
	}
	remainder = (char *)malloc(sizeof(char) * (gnl_strlen(str) - i));
	if (!remainder)
		return (NULL);
	i++;
	while (str[i])
		remainder[j++] = str[i++];
	remainder[j] = '\0';
	free(str);
	return (remainder);
}

/** */
__attribute__((always_inline, used)) static inline char	*read_and_store(
	const int fd,
	char *remainder
)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 && remainder)
			return (free(buffer), free(remainder), NULL);
		else if (bytes_read < 0)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		remainder = str_join(remainder, buffer);
		if (!remainder)
			return (free(buffer), free(remainder), NULL);
		if (bytes_read == 0 || (bytes_read > 0 && remainder
				&& (ft_strchr(remainder, '\n'))))
			break ;
	}
	free(buffer);
	return (remainder);
}

/**
 * @file get_next_line.c
 * @brief Read a line from a file descriptor
 * @author nduvoid
 * 
 * @param fd File descriptor
 * @return The line read from the file descriptor, NULL if an error occurs
 * or the end of the file is reached
 */
char	*get_next_line(int fd)
{
	static char	*remainder[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder[fd] = read_and_store(fd, remainder[fd]);
	if (!remainder[fd] || remainder[fd][0] == '\0')
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	line = line_getter(remainder[fd], 1);
	remainder[fd] = update_remainder(remainder[fd]);
	return (line);
}

/** */
__attribute__((used)) char	*gnl(
	const int fd
)
{
	static char	*remainder[MAX_FD];
	char		*line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder[fd] = read_and_store(fd, remainder[fd]);
	if (!remainder[fd] || remainder[fd][0] == '\0')
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	line = line_getter(remainder[fd], 0);
	remainder[fd] = update_remainder(remainder[fd]);
	return (line);
}
