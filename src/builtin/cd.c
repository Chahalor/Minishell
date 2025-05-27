/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/27 13:08:16 by nduvoid          ###   ########.fr       */
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
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	(void)fd_in;
	(void)fd_out;
	ft_printf("cd: <%s>\n", args[1]);
	if (__builtin_expect(!args || !args[1], unexpected))
		chdir(getenv("HOME"));
	else
		if (__builtin_expect(chdir(args[1]), unexpected))
			return (perror("cd: chdir() failed"), 1);
	return (0);
}

#pragma endregion Fonctions