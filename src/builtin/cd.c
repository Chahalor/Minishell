/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/26 15:56:56 by nduvoid          ###   ########.fr       */
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
__attribute__((used)) char	bltin_cd(
	const char **args
)
{
	ft_printf("cd: <%s>\n", args[1]);
	if (__builtin_expect(!args || !args[1], unexpected))
		chdir(getenv("HOME"));
	else
	{
		if (__builtin_expect(chdir(args[1]), unexpected))
		{
			perror("cd");
			return (-1);
		}
	}
	return (0);
}

#pragma endregion Fonctions