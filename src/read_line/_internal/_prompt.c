/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _prompt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:06:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 10:41:43 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Internals |----- */
#include "_read_line.h"
#include "formating.h"

/* -----| Modules  |----- */
#include "read_line.h"

static inline int	__ansi_len(
	const char *const restrict str
)
{
	register int	__i;

	if (_UNLIKELY(str == NULL || str[0] != '\033' || str[1] != '['))
		return (0);
	__i = 2;
	while (str[__i] != '\0')
	{
		if ((str[__i] >= 'a' && str[__i] <= 'z')
			|| (str[__i] >= 'A' && str[__i] <= 'Z'))
			return (__i + 1);
		__i++;
	}
	return (0);
}

extern inline int	_prompt_length(
	const char *const restrict prompt
)
{
	register int	__i;
	register int	length;

	if (_UNLIKELY(!prompt))
		return (0);
	length = 0;
	__i = 0;
	while (prompt[__i])
	{
		if (prompt[__i] == '\033')
			__i += __ansi_len(&prompt[__i]);
		else
		{
			++__i;
			++length;
		}
	}
	return (length);
}
