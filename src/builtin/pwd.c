/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/05 13:15:01 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline char	_parse(
	const char **args
)
{
	register int	i;

	if (_UNLIKELY(!args || !*args))
		return (1);
	i = 0;
	while (args[++i])
	{
		if (ft_strncmp(args[i], "--help", 7) == 0
			|| ft_strncmp(args[i], "-h", 3) == 0)
			return (1);
	}
	return (0);
}

__attribute__((always_inline, used)) static inline char	_help(void)
{
	ft_fprintf(2,
		BLUE "Usage:" RESET " pwd [options]\n"
		"show the current working directory\n"
		YELLOW "Options:\n" RESET
		"  -h, --help\t\tDisplay this help and exit\n"
		);
	return (EXIT_FAILURE);
}

/** */
__attribute__((used)) char	bltin_pwd(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const char	help = _parse(args);
	const char	*pwd = getcwd(NULL, 0);

	(void)fd_in;
	if (_UNLIKELY(!args || help))
		return (_help());
	else if (_UNLIKELY(!pwd))
		return (ft_perror("pwd: getcwd failed"), builtin_error_no_such_file);
	else
	{
		ft_fprintf(fd_out, "%s\n", pwd);
		free((void *)pwd);
		return (EXIT_SUCCESS);
	}
}

#pragma endregion Fonctions