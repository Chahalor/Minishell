/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/19 14:33:56 by nduvoid          ###   ########.fr       */
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
__attribute__((used)) char	bltin_pwd(
	const char *const restrict *const restrict args
)
{
	(void)args;
	return (write(STDERR_FILENO, "pwd is not implemented yet\n", 27), 0);
}

#pragma endregion Fonctions