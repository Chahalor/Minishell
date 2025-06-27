/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/27 12:58:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE

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

extern char	*_get_dir(
				const char *const restrict path
				);

extern char	*_get_file(
				const char *const restrict path
				);

extern void	_add_builtin(
				t_rl_completion *const restrict completion,
				const char *const restrict path_file
				);

#pragma endregion Prototypes
#pragma region Fonctions

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
__attribute__((used)) static inline int	_show_cmds(
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
			if (ft_strncmp(entry->d_name, word, ft_strlen(word)) == 0)
				dt->entry[dt->nb_entries++] = memdup(entry, sizeof(t_dirent));
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
__attribute__((used)) static inline int	_show_paths(
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
		if (ft_strncmp(entry->d_name, path_file, ft_strlen(path_file)) == 0
			&& (entry->d_name[0] != '.' || path_file[0] == '.'))
			data->entry[data->nb_entries++] = memdup(entry, sizeof(t_dirent));
		entry = readdir(dir);
	}
	closedir(dir);
	return (mm_free(path_dir), mm_free(path_file), 0);
}

/**
 *  @brief	Display the completion entries in the terminal.
 * 
 *  @param	completion	The completion data containing entries to display.
 *  @param	data		The read line data structure for prompt and result.
 * 
 * @return	Returns 0
 * 
 * @version 1.0
 */
static inline int	_show(
	t_rl_completion *const restrict completion,
	t_rl_data *const restrict data
)
{
	register int	i;
	t_file_type		type;

	write(STDOUT_FILENO, "\r\n", 2);
	i = -1;
	while (++i < completion->nb_entries)
	{
		type = check_path(completion->entry[i]->d_name, F_OK | X_OK);
		if (type == e_directory)
			ft_printf(BOLD BLUE "%s/ " RESET, completion->entry[i]->d_name);
		else if (type == e_symlink)
			ft_printf(BOLD MAGENTA "%s@ " RESET, completion->entry[i]->d_name);
		else if (type == e_executable)
			ft_printf(BOLD GREEN "%s* " RESET, completion->entry[i]->d_name);
		else
			ft_printf(BOLD "%s " RESET, completion->entry[i]->d_name);
	}
	if (_LIKELY(i))
		ft_printf("\r\n%s%s", data->prompt, data->result);
	return (0);
}

/**
 * @brief	Replace the last word in the result with the completion word.
 * 
 *  @param	completion	The completion data containing the word to replace.
 *  @param	data		The read line data structure for prompt and result.
 * 
 *  @return	Returns 0
 */
static inline int	_replace(
	t_rl_completion *const restrict completion,
	t_rl_data *const restrict data
)
{
	const char *const	word = completion->entry[0]->d_name;
	register int		i;

	i = data->line_length;
	while (i > 0 && data->result[i - 1] != ' ' && data->result[i - 1] != '/')
		--i;
	_neutral(data->result + i, data->line_length - i);
	data->cursor_pos = i;
	data->line_length = i;
	_rl_add(data, word, rl_str);
	if (completion->entry[0]->d_type == DT_DIR)
		_rl_add(data, "/", rl_chr);
	ft_printf("\033[2K\r%s%s", data->prompt, data->result);
	return (0);
}

/**
 *  @brief	Handle the completion of the last word in the result.
 * 
 *  @param	data	The read line data structure containing the result.
 * 
 *  @return	Returns 0 on success, -1 on error.
 *  @retval		+0 on success
 *  @retval		-1 on error (memory allocation failure or no entries found).
 * 
 *  @version 1.1
*/
int	completion(
	t_rl_data *const restrict data
)
{
	char			**words;
	register int	nb_words;
	int				token;
	t_rl_completion	completion;

	_neutral(&completion, sizeof(t_rl_completion));
	words = ft_split(data->result, ' ');
	if (_UNLIKELY(!words))
		return (-1);
	nb_words = arraylen((const void *const *)words);
	token = tokenize(words[nb_words - 1]);
	if (token == token_cmd)
		_show_cmds(words[nb_words - 1], &completion);
	else if (token > token_cmd && token < unknown)
		_show_paths(words[nb_words - 1], &completion);
	if (completion.nb_entries == 1)
		_replace(&completion, data);
	else if (completion.nb_entries > 0)
		_show(&completion, data);
	return (free_tab(words), _free_completion(&completion), 0);
}

#pragma endregion Fonctions