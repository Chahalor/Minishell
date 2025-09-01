/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/01 14:17:26 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_builtin.h"
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

/* -----| Modules   |----- */
#include "builtin.h"
#include "env.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Displays the help message for the cd command.
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

/**
 * @brief	Displays an error message based on the provided error code.
 * 
 * @param	error Error code indicating the type of error.
 * @param	filename Name of the file or directory involved in the error.
 * 
 * @return	Returns EXIT_FAILURE to indicate an error.
*/
__attribute__((always_inline, used)) static inline char	_error(
	const enum e_builtin_error error,
	const char *const filename
)
{
	ft_fprintf(2, RED "cd: <%s>: %s\n" RESET, filename, strerror(error));
	return (EXIT_FAILURE);
}

/**
 * @brief	Parses the arguments for the cd command.
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
		result.error = builtin_error_too_many_args;
	else if (!args[1])
		result.home = 1;
	else if (ft_strncmp(args[1], "-", 2) == 0)
		result.oldpwd = 1;
	else if (ft_strncmp(args[1], "--help", 7) == 0
		|| ft_strncmp(args[1], "-h", 3) == 0)
		result.help = 1;
	return (result);
}

/**
 * @brief	Checks if the given path is a valid directory.
 * 
 * @param	path	Path to check.
 * 
 * @return	If the path is valid
 * @retval		builtin_error_none if the path is a valid directory.
 * @retval		builtin_error_no_such_file if the path does not exist.
 * @retval		builtin_error_not_a_directory if the path is not a directory.
 */
__attribute__((always_inline, used)) static inline char	_check_path(
	const char *const restrict path
)
{
	struct stat	statbuf;

	if (_UNLIKELY(!path || !*path || access(path, F_OK) != F_OK))
		return (ENOENT);
	else if (stat(path, &statbuf) != 0)
		return (errno);
	else if (!S_ISDIR(statbuf.st_mode))
		return (ENOTDIR);
	else
		return (builtin_error_none);
}

/**
 * @brief	Changes the current working directory.
 * 
 * @param	args	Arguments for the command.
 * @param	fd_in	Input file descriptor (not used).
 * @param	fd_out	Output file descriptor (not used).
 * 
 * @return	The exit status of the command.
 * @retval		EXIT_SUCCESS if the command was successful.
 * @retval		EXIT_FAILURE if an error occurred
 * 		(e.g., too many arguments, no such file or directory, not a directory).
 * 
 * @version	2.0
 * 
 * @todo: change the HOME/OLDPWD environment variables (in the manager)
*/
__attribute__((used)) char	builtin_cd(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const char				*dests[2] = {"HOME", "OLDPWD"};
	const struct s_args_cd	opts = _parse(args);
	char					*cwd;
	char					*dest;
	int						error;

	(void)fd_in;
	(void)fd_out;
	if (_UNLIKELY(opts.help))
		return (_help());
	else if (_UNLIKELY(opts.error))
		return (_error(opts.error, NULL));
	else if (opts.oldpwd || opts.home)
		dest = env_find((void *)dests[opts.oldpwd == 1]);
	else
		dest = (char *)args[1];
	error = _check_path(dest);
	if (error)
		return (_error(error, dest));
	else if (chdir(dest) != 0)
		return (_error(errno, dest));
	cwd = getcwd(NULL, 0);
	env_export("OLDPWD", env_find("PWD"));
	env_export("PWD", cwd);
	return (free(cwd), EXIT_SUCCESS);
}

#pragma endregion Fonctions