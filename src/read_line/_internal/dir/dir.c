/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/03 11:18:13 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"
#include <dirent.h>

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((always_inline, used)) static inline char	*_get_dir(
	const char *const restrict path
)
{
	register int	i;
	char			*result;

	if (_UNLIKELY(!path || !*path))
		return (NULL);
	i = ft_strlen(path);
	while (i > 0 && path[i - 1] != '/')
		--i;
	if (!path[i])
		++i;
	result = mm_alloc(i + 1);
	if (_UNLIKELY(!result))
		return (NULL);
	ft_memcpy(result, path, i);
	result[i] = '\0';
	return (result);
}

/** */
__attribute__((always_inline, used)) static inline char	*_get_file(
	const char *const restrict path
)
{
	register int	i;
	char			*result;

	if (_UNLIKELY(!path || !*path))
		return (NULL);
	i = ft_strlen(path);
	while (i > 0 && path[i - 1] != '/')
		--i;
	result = mm_alloc(ft_strlen(path) - i + 1);
	if (_UNLIKELY(!result))
		return (NULL);
	ft_memcpy(result, path + i, ft_strlen(path) - i);
	result[ft_strlen(path) - i] = '\0';
	return (result);
}

/**
 * @todo: replace getenv by the manager getenv function
*/
__attribute__((used)) static inline int	_show_cmds(
	const char *const restrict word,
	t_rl_completion *const restrict data
)
{
	char			**paths;
	register int	i;
	DIR				*dir;
	struct dirent	*entry;

	paths = ft_split(getenv("PATH"), ':');
	if (_UNLIKELY(!paths))
		return (-2);
	i = -1;
	while (paths[++i])
	{
		dir = opendir(paths[i]);
		if (_UNLIKELY(!dir))
			continue ;
		entry = readdir(dir);
		while (entry && data->nb_entries < _RL_COMP_LIMIT)
		{
			if (ft_strncmp(entry->d_name, word, ft_strlen(word)) == 0)
				data->entry[data->nb_entries++] = memdup(entry,
						sizeof(struct dirent));
			entry = readdir(dir);
		}
		closedir(dir);
	}
	return (free_tab(paths), 0);
}

/** */
__attribute__((used)) static inline int	_show_paths(
	const char *const restrict word,
	t_rl_completion *const restrict data
)
{
	char			*path_dir;
	char			*path_file;
	DIR				*dir;
	struct dirent	*entry;

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
		if (entry->d_name[0] != '.' \
			&& ft_strncmp(entry->d_name, path_file, ft_strlen(path_file)) == 0)
			data->entry[data->nb_entries++] = memdup(entry,
					sizeof(struct dirent));
		entry = readdir(dir);
	}
	closedir(dir);
	return (mm_free(path_dir), mm_free(path_file), 0);
}

// static inline int	_end(
// 	t_rl_completion *const restrict completion,
// 	t_rl_data *const restrict data,
// 	const char *const restrict word
// )
// {
// 	register int	i;

// 	(void)word;
// 	if (!completion->nb_entries)
// 		return (1);
// 	write(STDOUT_FILENO, "\r\n", 2);
// 	i = -1;
// 	while (++i < completion->nb_entries)
// 		ft_printf("%s ", completion->entry[i]->d_name);
// 	ft_printf("\r\n%s%s", data->prompt, data->result);
// 	return (0);
// }

/** */
int	completion(
	t_rl_data *const restrict data
)
{
	char			**words;
	register int	nb_words;
	int				token;
	t_rl_completion	completion;
	register int	i;

	_neutral(&completion, sizeof(t_rl_completion));
	words = ft_split(data->result, ' ');
	if (_UNLIKELY(!words))
		return (data->status = error, -1);
	nb_words = arraylen((const void *const *)words);
	token = tokenize(words[nb_words - 1]);
	if (token == token_cmd)
		_show_cmds(words[nb_words - 1], &completion);
	else if (token > token_cmd && token < unknown)
		_show_paths(words[nb_words - 1], &completion);
	if (!completion.nb_entries)
		return (1);
	write(STDOUT_FILENO, "\r\n", 2);
	i = -1;
	while (++i < completion.nb_entries)
		ft_printf("%s ", completion.entry[i]->d_name);
	ft_printf("\r\n%s%s", data->prompt, data->result);
	return (free_tab(words), _free_completion(&completion), 0);
}

#pragma endregion Fonctions