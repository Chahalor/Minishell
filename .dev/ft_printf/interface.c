/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:12:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/16 16:10:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_ft_printf.h"

/* -----| Modules   |----- */
#include "ft_printf.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((__format__(__printf__, 1, 2))) int	ft_printf(
	const char *const restrict format,
	...
)
{
	va_list	args;
	t_print	print;

	if (__builtin_expect(!format || write(1, "", 0) == -1, unexpected))
		return (-1);
	va_start(args, format);
	print = (t_print){
		.buffer = {0},
		.buffer_len = 0,
		.nb_char = 0,
		.fd = 1
	};
	write_loop(format, args, &print);
	va_end(args);
	return (print.nb_char);
}

#if defined(DEBUG) && DEBUG == 1

/** */
__attribute__((__format__(__printf__, 1, 2))) int	debug_printf(
	const char *const restrict format,
	...
)
{
	va_list	args;
	t_print	print;

	if (__builtin_expect(!format || write(1, "", 0) == -1, unexpected))
		return (-1);
	va_start(args, format);
	print = (t_print){
		.buffer = {0},
		.buffer_len = 0,
		.nb_char = 0,
		.fd = 1
	};
	write_loop(format, args, &print);
	va_end(args);
	return (print.nb_char);
}

#else

/** */
__attribute__((__format__(__printf__, 1, 2))) int	debug_printf(
	const char *const restrict format,
	...
)
{
	va_list	args;
	t_print	print;

	if (__builtin_expect(!format || write(1, "", 0) == -1, unexpected))
		return (-1);
	va_start(args, format);
	print = (t_print){
		.buffer = {0},
		.buffer_len = 0,
		.nb_char = 0,
		.fd = 1
	};
	write_loop(format, args, &print);
	va_end(args);
	return (print.nb_char);
}

#endif

/** */
__attribute__((__format__(__printf__, 2, 3))) int	ft_fprintf(
	const int fd,
	const char *const restrict format,
	...
)
{
	va_list	args;
	t_print	print;

	if (__builtin_expect(!format || write(fd, "", 0) == -1, unexpected))
		return (-1);
	va_start(args, format);
	print = (t_print){
		.buffer = {0},
		.buffer_len = 0,
		.nb_char = 0,
		.fd = fd
	};
	write_loop(format, args, &print);
	va_end(args);
	return (print.nb_char);
}

/** */
__attribute__((__format__(__printf__, 2, 3))) int	ft_sprintf(
	char *const restrict buffer,
	const char *const restrict format,
	...
)
{
	va_list		args;
	t_sprint	print;

	if (__builtin_expect(!format || !buffer, unexpected))
		return (-1);
	va_start(args, format);
	print = (t_sprint){
		.buffer = buffer,
		.nb_char = 0
	};
	write_loop(format, args, &print);
	va_end(args);
	return (print.nb_char);
}

#pragma endregion Fonctions