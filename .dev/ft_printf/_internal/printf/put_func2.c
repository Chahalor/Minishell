/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:55:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/16 16:45:00 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_ft_printf.h"

/* -----| Modules   |----- */
#include "ft_printf.h"

#pragma endregion Header
#pragma region Fonctions

int	writeuint(
	unsigned int uint,
	t_print *const restrict print
)
{
	char		buffer[PRINTF_DEC_BUFFER_SIZE];
	__int8_t	i;

	if (uint == 0)
		return (print->add(print, '0'));
	i = PRINTF_DEC_BUFFER_SIZE - 1;
	while (uint > 0 && i)
	{
		buffer[i--] = '0' + uint % 10;
		uint /= 10;
	}
	while (i < PRINTF_DEC_BUFFER_SIZE - 1)
		print->add(print, buffer[i++]);
	return (1);
}

static int	neg_writelhex(unsigned int nb, char *buffer)
{
	int	i;

	i = 15;
	while (nb > 0)
	{
		buffer[i--] = LHEX_CHAR[nb % 16];
		nb /= 16;
	}
	while (i >= 8)
	{
		buffer[i--] = 'f';
		nb /= 16;
	}
	return (write(1, &buffer[i + 1], 15 - i));
}

int	writelhex(
	int nb,
	t_print *const restrict print,
	const char *const restrict base
)
{
	char		buffer[PRINTF_HEX_BUFFER_SIZE];
	__int8_t	i;

	if (nb == -2147483647 - 1)
		return (writestr("80000000", print));
	else if (nb == 0)
		return (print->add(print, '0'));
	// else if (nb < 0)
	// 	return (neg_writelhex((unsigned int)nb, buffer));
	i = PRINTF_HEX_BUFFER_SIZE - 1;
	while (nb > 0)
	{
		buffer[i--] = base[nb % 16];
		nb /= 16;
	}
	while (i < PRINTF_HEX_BUFFER_SIZE - 1)
		print->add(print, buffer[i++]);
	return (1);
	// return (write(1, &buffer[i + 1], 15 - i));
}

/** */
__attribute__((used)) int writehex(
	long nb,
	t_print *const restrict print,
	const char *const restrict base
)
{
	char		buffer[PRINTF_HEX_BUFFER_SIZE];
	__int8_t	i;

	if (nb == -2147483647 - 1)
		return (writestr("80000000", print));
	else if (nb == 0)
		return (print->add(print, '0'));
	// else if (nb < 0)
	// 	return (neg_writelhex((unsigned int)nb, buffer));
	i = PRINTF_HEX_BUFFER_SIZE - 1;
	while (nb > 0)
	{
		buffer[i--] = base[nb % 16];
		nb /= 16;
	}
	while (i < PRINTF_HEX_BUFFER_SIZE - 1)
		print->add(print, buffer[i++]);
	return (1);
	// return (write(1, &buffer[i + 1], 15 - i));
}

static int	neg_writeuhex(unsigned int nb, char *buffer)
{
	int	i;

	i = 15;
	while (nb > 0)
	{
		buffer[i--] = UHEX_CHAR[nb % 16];
		nb /= 16;
	}
	while (i >= 8)
	{
		buffer[i--] = 'F';
		nb /= 16;
	}
	return (write(1, &buffer[i + 1], 15 - i));
}

int	writeuhex(int nb)
{
	char		buffer[16];
	__int8_t	i;

	if (nb == -2147483647 - 1)
		return (write(1, "80000000", 8));
	if (nb == 0)
		return (write(1, "0", 1));
	else if (nb < 0)
		return (neg_writeuhex((unsigned int)nb, buffer));
	i = 15;
	while (nb > 0)
	{
		buffer[i--] = UHEX_CHAR[nb % 16];
		nb /= 16;
	}
	return (write(1, &buffer[i + 1], 15 - i));
}

#pragma endregion Fonctions