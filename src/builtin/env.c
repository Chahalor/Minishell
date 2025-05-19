/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/19 14:31:42 by nduvoid          ###   ########.fr       */
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
__attribute__((used)) char	bltin_env(
	const char *const restrict *const restrict args
)
{
	(void)args;
	write(STDERR_FILENO, "env is not implemented yet\n", 31);
	return (0);
}

#pragma endregion Fonctions