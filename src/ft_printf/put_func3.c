/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_func3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:19:16 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 09:38:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	logic_writedec(int nb)
{
	char		buffer[10];
	__int8_t	i;

	i = 9;
	while (nb > 0)
	{
		buffer[i--] = '0' + nb % 10;
		nb /= 10;
	}
	return (write(1, &buffer[i + 1], 9 - i));
}

int	writedec(int dec)
{
	int	nb_char;
	int	wout;

	nb_char = 0;
	if (dec == -2147483647 - 1)
		return (write(1, "-2147483648", 11));
	else if (dec == 0)
		return (write(1, "0", 1));
	if (dec < 0)
	{
		dec *= -1;
		wout = write(1, "-", 1);
		if (wout == -1)
			return (-1);
		nb_char += 1;
	}
	return (logic_writedec(dec) + nb_char);
}
