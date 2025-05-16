/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:36:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/16 16:23:17 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline int	write_arg(
	const char *const restrict s,
	va_list args,
	t_print *const restrict print
)
{
	char	symb;

	symb = s[1];
	if (symb == 'c')
		return (print->add(print, va_arg(args, char)));
	else if (symb == 's')
		return (writestr(va_arg(args, char *), print));
	else if (symb == 'p')
		return (writeptr(va_arg(args, void *), print));
	else if (symb == 'd' || symb == 'i')
		return (writedec(va_arg(args, int), print));
	else if (symb == 'u')
		return (writeuint(va_arg(args, unsigned int), print));
	else if (symb == 'x')
		return (writelhex(va_arg(args, int), print));
	else if (symb == 'X')
		return (writeuhex(va_arg(args, int)));
	else if (symb == '%')
		return (print->add(print, '%'));
	else
		return (0);
}

/** */
__attribute__((used)) int	write_loop(
	const char *s,
	va_list args,
	t_print *const restrict print
)
{
	const int		len = ft_strlen(s);
	register int	i;

	i = -1;
	while (++i < len && !print->error)
	{
		if (s[i] == '%')
			write_arg(s, args, print);
		else
			print->add(print, s[i]);
	}
}

#pragma endregion Fonctions