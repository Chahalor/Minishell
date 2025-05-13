/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:48:17 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 09:38:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	writechar(char c)
{
	c = (unsigned char)c;
	return (write(1, &c, 1));
}

int	writestr(char *s)
{
	int	wout;

	if (!s)
		return (write(1, "(null)", 6));
	wout = write(1, s, ft_strlen(s));
	return (wout);
}

static int	logic_writeptr(size_t nb, char *buffer)
{
	__uint8_t	i;

	i = 31;
	while (nb > 0)
	{
		buffer[i--] = LHEX_CHAR[nb % 16];
		nb /= 16;
	}
	return (write(1, &buffer[i + 1], 31 - i));
}

int	writeptr(void *ptr)
{
	int		nblen;
	ssize_t	write_output;
	size_t	adr;
	char	buffer[32];

	if (!ptr)
		return (write(1, "(nil)", 5));
	nblen = 0;
	adr = (size_t)ptr;
	write_output = write(1, "0x", 2);
	if (write_output == -1)
		return (-1);
	nblen += write_output;
	write_output = logic_writeptr(adr, buffer);
	if (write_output == -1)
		return (-1);
	return (nblen + write_output);
}
