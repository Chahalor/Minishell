/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:26:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/29 11:37:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static inline t_uint	_get_size(
	unsigned int n
)
{
	t_uint	size;

	size = (n < 0 || n == 0);
	while (n > 0)
	{
		n /= 10;
		++size;
	}
	return (size);
}

char	*ft_itoa(
	const int n
)
{
	unsigned int	nb;
	char			*str;
	int				len;

	nb = (unsigned int)-n * (n < 0) + (unsigned int)n * (n >= 0);
	len = _get_size(nb);
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
