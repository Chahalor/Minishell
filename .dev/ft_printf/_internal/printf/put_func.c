/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:48:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/16 16:51:30 by nduvoid          ###   ########.fr       */
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
__attribute__((used)) int	writestr(
	const char *const restrict s,
	t_print *const restrict print
)
{
	register int	i;

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

/** */
__attribute__((used)) int	writehex(
	long nb,
	t_print *const restrict print,
	const char *const restrict base
)
{
	char		buffer[PRINTF_HEX_BUFFER_SIZE];
	__int8_t	i;

	if (__builtin_expect(nb == -2147483647 - 1, unexpected))
		return (writestr("80000000", print));
	else if (__builtin_expect(nb == 0, unexpected))	// @todo: check if we need thsi test
		return (print->add(print, '0'));
	i = PRINTF_HEX_BUFFER_SIZE - 1;
	while (nb > 0)
	{
		buffer[i--] = base[nb % 16];
		nb /= 16;
	}
	while (i < PRINTF_HEX_BUFFER_SIZE - 1)
		print->add(print, buffer[i++]);
	return (1);
}

/** */
__attribute__((used)) int	writeptr(
	const void *const restrict ptr,
	t_print *const restrict print
)
{
	size_t				addr;
	char				buffer[PRINTF_HEX_BUFFER_SIZE];
	register __uint8_t	i;

	if (__builtin_expect(!ptr, unexpected))
		return (writestr("(nil)", print));
	writestr("0x", print);
	if (__builtin_expect(print->error, unexpected))
		return (-1);
	addr = (size_t)ptr;
	return (writehex(addr, print, LHEX_CHAR));
}

/** */
__attribute__((used)) int writedec(
	long dec,
	t_print *const restrict print
)
{
	char				buffer[PRINTF_DEC_BUFFER_SIZE];
	register __int8_t	i;

	if (__builtin_expect(dec == -2147483647 - 1, unexpected))
		return (writestr("-2147483648", print));
	else if (__builtin_expect(dec == 0, unexpected))
		return (print->add(print, '0'));
	i = PRINTF_DEC_BUFFER_SIZE - 1;
	while (dec > 0)
	{
		buffer[i--] = '0' + dec % 10;
		dec /= 10;
	}
	while (i < PRINTF_DEC_BUFFER_SIZE - 1)
		print->add(print, buffer[i++]);
	return (1);
}

#pragma endregion Fonctions