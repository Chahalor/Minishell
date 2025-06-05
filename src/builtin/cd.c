/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/05 10:49:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_builtin.h"
#include <unistd.h>
#include <sys/stat.h>

/* -----| Modules   |----- */
#include "builtin.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Displays the help message for the echo command.
 * 
 * @param	None
 * 
 * @return		Returns EXIT_FAILURE to indicate an error.
*/
__attribute__((always_inline, used)) static inline char	_help(void)
{
	ft_fprintf(2,
		BLUE "Usage:" RESET " cd [options] [dir]\n"
		YELLOW "Options:\n" RESET
		"  -, \t\tChange to the last directory\n"
		"  -h, --help\t\tDisplay this help and exit\n"
	);
	return (EXIT_FAILURE);
}

__attribute__((always_inline, used)) static inline char	_error(
	const enum e_echo_error error
)
{
	if (error == echo_error_too_many_args)
		ft_fprintf(2, SHELL_NAME ": cd: too many arguments\n");
	else if (error == echo_error_no_such_file)
		ft_fprintf(2, SHELL_NAME ": cd: no such file or directory\n");
	return (EXIT_FAILURE);
}

/**
 * @brief	Parses the arguments for the echo command.
 * 
 * @param	args	Arguments to parse.
 * 
 * @return		Returns a struct containing the parsed arguments.
*/
__attribute__((always_inline, used)) static inline struct s_args_cd	_parse(
	const char **args
)
{
	const int			argc = arraylen((const void *const *)args);
	struct s_args_cd	result;

	result = (struct s_args_cd){0};
	if (_UNLIKELY(!args || !*args))
		return (result);
	else if (argc > 2)
		result.error = echo_error_too_many_args;
	else if (!args[1])
		result.home = 1;
	else if (ft_strncmp(args[1], "-", 2) == 0)
		result.oldpwd = 1;
	else if (ft_strncmp(args[1], "--help", 7) == 0
			 || ft_strncmp(args[1], "-h", 3) == 0)
		result.help = 1;
	return (result);
}

__attribute__((always_inline, used)) static inline char	_check_path(
	const char *const restrict path
)
{
	struct stat	statbuf;

	if (_UNLIKELY(!path))
		return (echo_error_no_such_file);
	else if (access(path, F_OK) != F_OK)
		return (echo_error_no_such_file);
	else if (stat(path, &statbuf) != 0 && !S_ISDIR(statbuf.st_mode))
		return (echo_error_no_such_file);
	else
		return (echo_error_none);
}

/**
 * @todo: change the PWD/OLDPWD environment variables (in the manager)
*/
__attribute__((used)) char	bltin_cd(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const struct s_args_cd	opts = _parse(args);
	char					*dest;

	(void)fd_in;
	(void)fd_out;
	if (_UNLIKELY(opts.help))
		return (_help());
	else if (_UNLIKELY(opts.error))
		return (_error(opts.error));
	else if (opts.oldpwd)
		dest = getenv("OLDPWD");
	else if (opts.home)
		dest = getenv("HOME");
	else
		dest = (char *)args[1];
	if (_check_path(dest) != echo_error_none)
		return (_error(echo_error_no_such_file));
	else if (chdir(dest) != 0)
		return (_error(echo_error_no_such_file));
	else
		return (EXIT_SUCCESS);
}

#pragma endregion Fonctions