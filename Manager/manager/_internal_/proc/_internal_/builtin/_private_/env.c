/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/28 16:47:37 by nduvoid          ###   ########.fr       */
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

static void	_help(void)
{
	_manager()->interface.printf(
		"Usage: env [options]\n"
		"Options:\n"
		"  -h, --help                display this help and exit\n"
	);
}

static inline struct int _parse(
	const char **args
)
{

}

/** */
__attribute__((used)) char	bltin_env(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	
}

#pragma endregion Fonctions