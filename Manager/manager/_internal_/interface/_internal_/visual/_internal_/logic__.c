/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:36:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/22 10:23:34 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "standards.h"
#include "visual__.h"

/* -----| Modules   |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	add a char to the buffer. If the buffer is full, write it to the fd.
 * 
 * @param	print	The print structure.
 * @param	c		The char to add.
 * 
 * @return	0 if the buffer is full, 1 if the char is added.
 * 
 * @note	write nothing if the fd is -1.
*/
__attribute__((visibility("hidden"), used))
int	_add(
	t_print *const restrict print,
	const char c
)
{
	if (unexpect(print->buff_pos >= print->buffer_len))
	{
		if (print->fd != -1)
			write(print->fd, print->buffer, print->buff_pos);
		ft_bzero(print->buffer, print->buffer_len);
		print->buff_pos = 0;
		return (0);
	}
	else
	{
		print->buffer[print->buff_pos++] = c;
		++print->nb_char;
	}
	return (1);
}

/**
 * @brief	redirects the arguments to the appropriate function.
 * 
 * @param	s		The format string.
 * @param	args	The arguments to format.
 * @param	print	The print structure.
 * 
 * @return	0.
*/
__attribute__((always_inline, used))
static inline int	_choose_arg__(
	const char *const restrict s,
	va_list args,
	t_print *const restrict print
)
{
	const char	symb = s[1];

	if (symb == 's')
		return (addstr__(va_arg(args, char *), print));
	else if (symb == 'c')
		return (print->add(print, va_arg(args, int)));
	else if (symb == 'p')
		return (writeptr(va_arg(args, void *), print));
	else if (symb == 'd' || symb == 'i')
		return (writedec(va_arg(args, int), print));
	else if (symb == 'u')
		return (writedec(va_arg(args, unsigned int), print));
	else if (symb == 'x')
		return (writehex(va_arg(args, unsigned int), print, LHEX_CHAR));
	else if (symb == 'X')
		return (writehex(va_arg(args, unsigned int), print, UHEX_CHAR));
	else if (symb == '%')
		return (print->add(print, '%'));
	else
	{
		print->add(print, '%');
		print->add(print, symb);
	}
	return (0);
}

/**
 * @brief	Parses the format string and redirects the arguments to the
 * appropriate function.
 * 
 * @param	s		The format string.
 * @param	args	The arguments to format.
 * @param	print	The print structure.
 * 
 * @return	The number of characters written.
*/
__attribute__((visibility("hidden"), used))
int	write_loop__(
	const char *s,
	va_list args,
	t_print *const restrict print
)
{
	const int		len = printf_strlen(s);
	register int	i;

	i = -1;
	while (++i < len && !print->error)
	{
		if (s[i] == '%')
		{
			_choose_arg__(s + i, args, print);
			++i;
		}
		else
			print->add(print, s[i]);
	}
	return (print->nb_char);
}

#pragma endregion Fonctions