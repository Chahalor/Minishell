/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:48:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/19 10:23:10 by nduvoid          ###   ########.fr       */
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
 * @brief	Adds a string to the buffer.
 * 
 * @param	s		The string to add.
 * @param	print	The print structure.
 * 
 * @return	1
*/
__attribute__((used)) int	writestr(
	const char *const restrict s,
	t_print *const restrict print
)
{
	register unsigned int	i;

	if (__builtin_expect(!s, unexpected))
		return (writestr("(null)", print));
	else
	{
		i = -1;
		while (s[++i])
			print->add(print, s[i]);
	}
	return (i);
}

/**
 * @brief	Adds a hex number to the buffer.
 * 
 * @param	nb		The number to add.
 * @param	print	The print structure.
 * 
 * @return	1
*/
__attribute__((used)) int	writehex(
	unsigned long nb,
	t_print *const restrict print,
	const char *const restrict base
)
{
	char				buffer[PRINTF_HEX_BUFFER_SIZE];
	register __int8_t	i;

	if (__builtin_expect(nb == 0, unexpected))
		return (print->add(print, '0'));
	i = PRINTF_HEX_BUFFER_SIZE - 1;
	while (nb > 0)
	{
		buffer[i--] = base[nb % 16];
		nb /= 16;
	}
	while (++i < PRINTF_HEX_BUFFER_SIZE)
		print->add(print, buffer[i]);
	return (1);
}

/**
 * @brief	Adds a pointer to the buffer.
 * 
 * @param	ptr		The pointer to add.
 * @param	print	The print structure.
 * 
 * @return	1
*/
__attribute__((used)) int	writeptr(
	const void *const restrict ptr,
	t_print *const restrict print
)
{
	const size_t	addr = (size_t)ptr;

	if (__builtin_expect(!ptr, unexpected))
		return (writestr("(nil)", print));
	writestr("0x", print);
	if (__builtin_expect(print->error, unexpected))
		return (-1);
	return (writehex(addr, print, LHEX_CHAR));
}

/**
 * @brief	Adds a decimal number to the buffer.
 * 
 * @param	dec		The number to add.
 * @param	print	The print structure.
 * 
 * @return	1
*/
__attribute__((used)) int	writedec(
	long dec,
	t_print *const restrict print
)
{
	char					buffer[PRINTF_DEC_BUFFER_SIZE];
	register __int8_t		i;
	register unsigned long	num;

	if (__builtin_expect(dec == LONG_MIN, 0))
		return (writestr("-9223372036854775808", print));
	else if (__builtin_expect(dec == 0, 0))
		return (print->add(print, '0'));
	else if (dec < 0)
	{
		num = dec * -1;
		print->add(print, '-');
	}
	else
		num = dec;
	i = PRINTF_DEC_BUFFER_SIZE - 1;
	while (num > 0)
	{
		buffer[i--] = '0' + (num % 10);
		num /= 10;
	}
	while (++i < PRINTF_DEC_BUFFER_SIZE)
		print->add(print, buffer[i]);
	return (1);
}

#pragma endregion Fonctions