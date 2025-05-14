/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:12:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/14 10:50:09 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @file ft_printf.c
 * @dir ft_printf
 * @brief ft_printf is a function that will print a formatted string
 * to the standard output (aka printf of wish)
 * @author nduvoid
 * 
 * @param s the string to print
 * @param ... the arguments to print
 * @return int the number of characters printed
 */
__attribute__((__format__(__printf__, 1, 2)))
int	ft_printf(const char *s, ...)
{
	va_list		args;
	__uint32_t	strlen;
	int			nb_char;

	if (write(1, "", 0) == -1)
		return (-1);
	else if (!s)
		return (-1);
	va_start(args, s);
	nb_char = 0;
	strlen = ft_strlen(s);
	nb_char = write_loop(s, args, strlen, &nb_char);
	va_end(args);
	return (nb_char);
}

#if defined(DEBUG) && DEBUG == 1

/** */
__attribute__((__format__(__printf__, 1, 2)))
int	debug_printf(const char *s, ...)
{
	va_list		args;
	__uint32_t	strlen;
	int			nb_char;

	if (write(1, "", 0) == -1)
		return (-1);
	else if (!s)
		return (-1);
	va_start(args, s);
	nb_char = 0;
	strlen = ft_strlen(s);
	nb_char = write_loop(s, args, strlen, &nb_char);
	va_end(args);
	return (nb_char);
}

#else

/** */
__attribute__((__format__(__printf__, 1, 2)))
int	debug_printf(const char *s, ...)
{
	(void)s;
	return (0);
}

#endif

/** */
__attribute__((deprecated))
int	ft_fprintf(int fd, const char *s, ...)
{
	// va_list		args;
	// __uint32_t	strlen;
	// int			nb_char;

	// if (write(fd, "", 0) == -1)
	// 	return (-1);
	// else if (!s)
	// 	return (-1);
	// va_start(args, s);
	// nb_char = 0;
	// strlen = ft_strlen(s);
	// nb_char = write_loop(s, args, strlen, &nb_char);
	// va_end(args);
	(void)s;
	(void)fd;
	write(1, "ft_fprintf is not implemented yet\n", 34);
	return (-1);
}