/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:55:00 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 09:38:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	writeuint(unsigned int uint)
{
	char		buffer[10];
	__int8_t	i;

	if (uint == 0)
		return (write(1, "0", 1));
	i = 9;
	while (uint > 0)
	{
		buffer[i--] = '0' + uint % 10;
		uint /= 10;
	}
	return (write(1, &buffer[i + 1], 9 - i));
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

int	writelhex(int nb)
{
	char		buffer[16];
	__int8_t	i;

	if (nb == -2147483647 - 1)
		return (write(1, "80000000", 8));
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb < 0)
		return (neg_writelhex((unsigned int)nb, buffer));
	i = 15;
	while (nb > 0)
	{
		buffer[i--] = LHEX_CHAR[nb % 16];
		nb /= 16;
	}
	return (write(1, &buffer[i + 1], 15 - i));
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
