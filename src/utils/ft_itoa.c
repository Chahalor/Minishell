/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:26:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/25 10:33:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_itoa(
	const int n
)
{
	const int		is_negative = (n < 0);
	const int		nb = (n * (-1 * is_negative) + (n * (!is_negative)));
	char			*str;
	int				len;
	unsigned int	tmp;

	len = (is_negative || n == 0);
	tmp = n * (-1 * is_negative) + (n * (!is_negative));
	while (tmp)
	{
		tmp /= 10;
		++len;
	}
	str = mm_alloc(sizeof(char) * (len + 1));
	if (_UNLIKELY(!str))
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		str[--len] = (nb % 10) + '0';
		tmp = nb / 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}
