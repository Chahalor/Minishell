/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/27 13:06:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_builtin.h"

/* -----| Modules   |----- */
#include "builtin.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((used)) char	bltin_echo(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	register int	i;

	(void)fd_in;
	if (!args || !args[0])
		return (-1);
	else
	{
		i = 0;
		while (args[++i])
		{
			if (i > 0)
				write(fd_out, " ", 1);
			write(fd_out, args[i], ft_strlen(args[i]));
		}
	}
	return (write(fd_out, "\n", 1), 0);
}

#pragma endregion Fonctions