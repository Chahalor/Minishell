/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:26:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/27 11:57:14 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_itoa(
	const int n
)
{
	unsigned int	nb;
	char			*str;
	int				len;

	if (n < 0)
		nb = (unsigned int)(-n);
	else
		nb = (unsigned int)n;
	len = (n < 0 || nb == 0);
	{
		unsigned int tmp = nb;
		while (tmp > 0)
		{
			tmp /= 10;
			++len;
		}
	}
	str = mm_alloc(sizeof(char) * (len + 1));
	if (_UNLIKELY(!str))
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[--len] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

