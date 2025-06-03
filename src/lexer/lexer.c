/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/03 11:32:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_lexer.h"

/* -----| Modules   |----- */
#include "lexer.h"

#pragma endregion Header
#pragma region Fonctions

/* -----| Utils Functions |---- */

/**
 * @brief	Checks the type of a file at the given path.
 * 
 * @param	path		The path to the file to check.
 * @param	access_mode	The access mode to check (F_OK, R_OK, W_OK, X_OK).
 * 
 * @return	Returns the type of the file.
 * @retval		0, not_found if the file does not exist.
 * @retval		1, file if the file is a regular file.
 * @retval		2, directory if the file is a directory.
 * @retval		3, symlink if the file is a symbolic link.
 * @retval		4, unknown if the file type is unknown.
 * 
 * @version	1.0
 */
__attribute__((used)) static t_file_type	check_path(
	const char *const restrict path,
	const int access_mode
)
{
	struct stat	file_stat;

	if (_UNLIKELY(!path))
		return (0);
	else if (access(path, access_mode))
		return (e_not_found);
	else
	{
		if (stat(path, &file_stat) < 0)
			return (perror("check_file(): stat() failed\n"), 0);
		else if (S_ISREG(file_stat.st_mode))
			return (e_file);
		else if (S_ISDIR(file_stat.st_mode))
			return (e_directory);
		else if (S_ISLNK(file_stat.st_mode))
			return (e_symlink);
		else
			return (e_unknown);
	}
}

/**
 * @brief	Searches for a command in the PATH environment variable.
 * 
 * @param	name	The name of the command to search for.
 * 
 * @return	Returns the full path of the command if found, NULL otherwise.
 * @retval		NULL if the command is not found or if an error occurs.
 * 
 * @version	1.0
 */
static char	*get_in_path(
	const char *const restrict name
)
{
	char			**paths;
	char			*full_path;
	register int	i;

	paths = ft_split(getenv("PATH"), ':');
	if (_UNLIKELY(!paths))
		return (perror("get_in_path(): ft_split() failed"), NULL);
	i = -1;
	while (paths[++i])
	{
		full_path = path_join(paths[i], name, ft_strlen(name));
		if (_UNLIKELY(!full_path))
			return (perror("get_in_path(): path_join() failed"), NULL);
		if (check_path(full_path, F_OK | X_OK) == e_file)
			return (free_tab(paths), full_path);
		else
			mm_free(full_path);
	}
	return (free_tab(paths), NULL);
}

/* -----| Core Functions  |---- */

/**
 * @brief	Builds the execution data structure from a command line.
 * 
 * @param	line	The command line to parse.
 * 
 * @return	Returns a pointer to the execution data structure.
 * @retval		NULL if the command line is invalid or if an error occurs.
 * @retval		data if the command line is valid and the execution data struct
 * 
 * @note it checks if the command is a file. And if it is not, it searches
 * 			for the command in the PATH environment variable.
 * 
 * @version	2.0
*/
__attribute__((used)) static t_exec_data	*built_exec_data(
	char *const restrict line
)
{
	t_exec_data		*data;

	data = (t_exec_data *)mm_alloc(sizeof(t_exec_data));
	*data = (t_exec_data){0};
	if (_UNLIKELY(!data))
		return (perror("built_exec_data(): mm_alloc() failed\n"), NULL);
	data->args = ft_split(line, ' ');
	if (_UNLIKELY(!data->args))
		return (mm_free(data), perror("built_exec_data(): ft_split() failed\n"),
			NULL);
	if (check_path(data->args[0], F_OK | X_OK) == e_file
		|| get_builtins(data->args[0]))
	{
		data->cmd = data->args[0];
		return (data);
	}
	else
		data->cmd = get_in_path(data->args[0]);
	if (_UNLIKELY(!data->cmd))
		data->cmd = data->args[0];
	return (data);
}

/**
 * @brief	Lexer function that parses a command line and builds an execution
 * 				data structure from it.
 * 
 * @param	line	The command line to parse.
 * 
 * @return	Returns a pointer to the execution data structure.
 * @retval		NULL if the command line is invalid or if an error occurs.
 * @return		data if the command line is valid and the execution data
 * 					structure is built successfully.
*/
__attribute__((hot)) t_exec_data	*lexer(
	const char *const restrict line
)
{
	char			**raw_cmds;
	t_exec_data		*data;
	t_exec_data		*current;
	register int	i;

	raw_cmds = ft_split(line, '|');
	if (_UNLIKELY(!raw_cmds))
		return (perror("lexer(): ft_split() failed"), NULL);
	data = NULL;
	i = -1;
	while (!data && raw_cmds[++i])
		data = built_exec_data(raw_cmds[i]);
	current = data;
	while (raw_cmds[++i])
	{
		current->pipe = built_exec_data(raw_cmds[i]);
		if (_LIKELY(current->pipe != NULL))
			current = current->pipe;
	}
	if (_UNLIKELY(!current && raw_cmds[i]))
		return (free_tab(raw_cmds), NULL);
	else if (_LIKELY(current != NULL))
		current->pipe = NULL;
	return (free_tab(raw_cmds), data);
}

#pragma endregion Fonctions