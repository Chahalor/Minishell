/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:48:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/22 10:10:36 by nduvoid          ###   ########.fr       */
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
 * @brief	Adds a string to the buffer.
 * 
 * @param	s		The string to add.
 * @param	print	The print structure.
 * 
 * @return	1
*/
__attribute__((visibility("hidden"), used))
int	addstr__(
	const char *const restrict s,
	t_print *const restrict print
)
{
	register unsigned int	i;

	if (unexpect(s == NULL))
		return (addstr__("(null)", print));
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
__attribute__((visibility("hidden"), used))
int	addhex__(
	unsigned long nb,
	t_print *const restrict print,
	const char *const restrict base
)
{
	char				buffer[PRINTF_HEX_BUFFER_SIZE];
	register __int8_t	i;

	if (unexpect(nb == 0))
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
__attribute__((visibility("hidden"), used))
int	addptr__(
	const void *const restrict ptr,
	t_print *const restrict print
)
{
	const size_t	addr = (size_t)ptr;

	if (unexpect(!ptr))
		return (addstr__("(nil)", print));
	addstr__("0x", print);
	if (unexpect(print->error))
		return (-1);
	return (addhex__(addr, print, LHEX_CHAR));
}

/**
 * @brief	Adds a decimal number to the buffer.
 * 
 * @param	dec		The number to add.
 * @param	print	The print structure.
 * 
 * @return	1
*/
__attribute__((visibility("hidden"), used))
int	adddec__(
	long dec,
	t_print *const restrict print
)
{
	char					buffer[PRINTF_DEC_BUFFER_SIZE];
	register __int8_t		i;
	register unsigned long	num;

	if (__builtin_expect(dec == LONG_MIN, 0))
		return (addstr__("-9223372036854775808", print));
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