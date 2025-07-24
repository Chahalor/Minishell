/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/24 10:15:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "builtin_.h"
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

/* -----| Modules   |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((used)) char	bltin_env(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	(void)args;
	(void)fd_in;
	(void)fd_out;
	write(STDERR_FILENO, "env is not implemented yet\n", 27);	// @todo: just add the manager call
	return (0);
}

#pragma endregion Fonctions