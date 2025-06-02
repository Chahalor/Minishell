/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:12:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/02 11:57:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_ft_printf.h"

/* -----| Modules   |----- */
#include "ft_printf.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Write The formatted string to the standard output.
 * 
 * @param	format	The format string.
 * @param	...		The values to format.
 * 
 * @return	The number of characters written, or -1 on error.
*/
__attribute__((__format__(__printf__, 1, 2))) int	ft_printf(
	const char *const restrict format,
	...
)
{
	va_list	args;
	t_print	print;
	char	buffer[PRINTF_BUFFER_SIZE];

	if (__builtin_expect(!format || write(1, "", 0) == -1, unexpected))
		return (-1);
	va_start(args, format);
	ft_bzero(buffer, PRINTF_BUFFER_SIZE);
	print = _init_print(buffer, 1, PRINTF_BUFFER_SIZE);
	write_loop(format, args, &print);
	write(print.fd, print.buffer, print.buff_pos);
	va_end(args);
	return (print.nb_char);
}

/**
 * @brief	Write The formatted string to the standard output but for raw mode.
 * 
 * @param	format	The format string.
 * @param	...		The values to format.
 * 
 * @return	The number of characters written, or -1 on error.
 * 
 * @note	This function is used for raw mode
 * 
 * @version 1.0
 */
__attribute__((__format__(__printf__, 1, 2))) int	raw_printf(
	const char *const restrict format,
	...
)
{
	va_list	args;
	t_print	print;
	char	buffer[PRINTF_BUFFER_SIZE];

	if (__builtin_expect(!format || write(1, "", 0) == -1, unexpected))
		return (-1);
	va_start(args, format);
	ft_bzero(buffer, PRINTF_BUFFER_SIZE);
	print = _init_print(buffer, 1, PRINTF_BUFFER_SIZE);
	write_loop(format, args, &print);
	write(print.fd, print.buffer, print.buff_pos);
	va_end(args);
	return (print.nb_char);
}

/**
 * @brief	Write The formatted string to the file descriptor.
 * 
 * @param	fd		The file descriptor to write to.
 * @param	format	The format string.
 * 
 * @param	...		The values to format.
 * 
 * @return	The number of characters written, or -1 on error.
*/
__attribute__((__format__(__printf__, 2, 3))) int	ft_fprintf(
	const int fd,
	const char *const restrict format,
	...
)
{
	va_list	args;
	t_print	print;
	char	buffer[PRINTF_BUFFER_SIZE];

	if (__builtin_expect(!format || fd == -1 || write(fd, "", 0) == -1,
			unexpected))
		return (-1);
	va_start(args, format);
	ft_bzero(buffer, PRINTF_BUFFER_SIZE);
	print = _init_print(buffer, fd, PRINTF_BUFFER_SIZE);
	write_loop(format, args, &print);
	write(print.fd, print.buffer, print.buff_pos);
	va_end(args);
	return (print.nb_char);
}

/**
 * @brief	Write The formatted string to the buffer.
 * 
 * @param	buffer	The buffer to write to.
 * @param	format	The format string.
 * @param	...		The values to format.
 * 
 * @return	The number of characters written, or -1 on error.
*/
__attribute__((__format__(__printf__, 2, 3))) int	ft_sprintf(
	char *const restrict buffer,
	const char *const restrict format,
	...
)
{
	va_list	args;
	t_print	print;

	if (__builtin_expect(!format || write(1, "", 0) == -1, unexpected))
		return (-1);
	va_start(args, format);
	ft_bzero(buffer, PRINTF_BUFFER_SIZE);
	print = _init_print(buffer, 1, PRINTF_BUFFER_SIZE);
	write_loop(format, args, &print);
	write(print.fd, print.buffer, print.buff_pos);
	va_end(args);
	return (print.nb_char);
}

__attribute__((__format__(__printf__, 1, 2))) void	ft_perror(
	const char *const restrict format,
	...
)
{
	va_list	args;
	t_print	print;
	char	buffer[PRINTF_BUFFER_SIZE];

	if (__builtin_expect(!format || write(STDERR_FILENO, "", 0) == -1, unexpected))
		return ;
	va_start(args, format);
	ft_bzero(buffer, PRINTF_BUFFER_SIZE);
	print = _init_print(buffer, STDERR_FILENO, PRINTF_BUFFER_SIZE);
	write_loop(format, args, &print);
	writestr(strerror(errno), &print);
	write(print.fd, print.buffer, print.buff_pos);
	va_end(args);
	return ;
}

#pragma endregion Fonctions