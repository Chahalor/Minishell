/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _add.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:43:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/02 15:50:39 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Prototypes

char	*_get_file(
			const char *const restrict path
			);

char	*_get_dir(
			const char *const restrict path
			);

#pragma endregion Prototypes
#pragma region Functions

__attribute__((used))
static inline void	_add_builtin(
	t_rl_completion *const restrict completion,
	const char *const restrict path_file
)
{
	static const char	*builtins[] = {
		"cd", "echo", "env", "exit", "export",
		"pwd", "unset", "history", NULL};
	t_dirent			entry;
	register int		i;

	i = -1;
	while (builtins[++i])
	{
		if (ft_strncmp(builtins[i], path_file, ft_strlen(path_file)) == 0)
		{
			_neutral(entry.d_name, sizeof(entry.d_name));
			entry.d_type = DT_REG;
			ft_memcpy(entry.d_name, builtins[i], ft_strlen(builtins[i]));
			completion->entry[completion->nb_entries++]
				= memdup(&entry, sizeof(t_dirent));
		}
	}
}

/**
 * @brief	Store all commands in the PATH environment variable that
 *  match the given word in the completion data.
 * 
 * @param	word	The word to match against command names.
 * @param	data	The completion data structure to store results.
 * 
 * @return	The success status of the operation.
 * @retval		+0 on success
 * @retval		-1 on error
 * @retval		-2 on memory allocation failure.
 * 
 * @todo: replace getenv by the manager getenv function
*/
__attribute__((used))
extern inline int	_add_cmds(
	const char *const restrict word,
	t_rl_completion *const restrict dt
)
{
	char			**paths;
	register int	i;
	DIR				*dir;
	struct dirent	*entry;

	paths = ft_split(getenv("PATH"), ':');
	if (_UNLIKELY(!paths))
		return (-2);
	_add_builtin(dt, word);
	i = -1;
	while (paths[++i] && dt->nb_entries < _RL_COMP_LIMIT)
	{
		dir = opendir(paths[i]);
		if (_UNLIKELY(!dir))
			continue ;
		entry = readdir(dir);
		while (entry && dt->nb_entries < _RL_COMP_LIMIT)
		{
			_rl_completion_add(dt, word, entry);
			entry = readdir(dir);
		}
		closedir(dir);
	}
	return (free_tab(paths), 0);
}

/**
 * @brief	Store all files and directories in the current directory
 *  that match the given word in the completion data.
 * 
 *  @param	word	The word to match against file and directory names.
 *  @param	data	The completion data structure to store results.
 *
 *  @return	The success status of the operation.
 *  @retval		=0 on success
 *  @retval		+1 if the directory cannot be opened
 *  @retval		-1 on memory allocation failure.
*/
__attribute__((used))
extern inline int	_add_paths(
	const char *const restrict word,
	t_rl_completion *const restrict data
)
{
	char		*path_dir;
	char		*path_file;
	DIR			*dir;
	t_dirent	*entry;

	path_dir = _get_dir(word);
	path_file = _get_file(word);
	if (_UNLIKELY(!path_dir || !path_file))
		return (free(path_dir), free(path_file), -1);
	dir = opendir(path_dir);
	if (_UNLIKELY(!dir))
		return (1);
	entry = readdir(dir);
	while (entry && data->nb_entries < _RL_COMP_LIMIT)
	{
		_rl_completion_add(data, path_file, entry);
		entry = readdir(dir);
	}
	closedir(dir);
	return (mm_free(path_dir), mm_free(path_file), 0);
}

int	_rl_completion_add(
	t_rl_completion *comp,
	const char *const restrict word,
	struct dirent *entry
)
{
	register int	i;

	if (_UNLIKELY(!comp || !word))
		return (-1);
	if (ft_strncmp(entry->d_name, word, ft_strlen(word)) != 0)
		return (1);
	i = -1;
	while (++i < comp->nb_entries)
		if (ft_strncmp(comp->entry[i]->d_name, entry->d_name,
				ft_strlen(entry->d_name)) == 0)
			return (1);
	comp->entry[comp->nb_entries++] = memdup(entry, sizeof(t_dirent));
	return (0);
}

#pragma endregion Functions