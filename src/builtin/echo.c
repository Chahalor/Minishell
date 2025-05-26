/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/26 15:57:03 by nduvoid          ###   ########.fr       */
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
	const char **args
)
{
	register int	i;

	if (!args || !args[0])
		return (-1);
	else
	{
		i = -1;
		while (args[++i])
		{
			if (i > 0)
				write(STDOUT_FILENO, " ", 1);
			write(STDOUT_FILENO, args[i], ft_strlen(args[i]));
		}
	}
	return (write(STDOUT_FILENO, "\n", 1), 0);
}

#pragma endregion Fonctions