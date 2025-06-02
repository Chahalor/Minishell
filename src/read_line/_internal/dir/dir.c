/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/02 17:42:56 by nduvoid          ###   ########.fr       */
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

void	_show_cmds(
	const char *const restrict word
)
{
	DIR				*dir;
	struct dirent	*entry;
	const char		*path = getenv("PATH");
	char			**paths;
	register int	i;

	if (!path || !*path)
		return ;
	paths = ft_split(path, ':');
	if (_UNLIKELY(!paths))
		return ;
	i = -1;
	while (paths[++i])
	{
		dir = opendir(paths[i]);
		if (!dir)
			continue ;
		while ((entry = readdir(dir)))
			if (ft_strncmp(entry->d_name, word, ft_strlen(word)) == 0)
				ft_printf("%s ", entry->d_name);
		closedir(dir);
	}
	free_tab(paths);
}

/** */
int	completion(
	t_rl_data *const restrict data
)
{
	char			**words;
	register int	nb_words;
	register int	i;
	int				token;

	words = ft_split(data->result, ' ');
	if (_UNLIKELY(!words))
		return (data->status = error, -1);
	nb_words = 0;
	while (words[nb_words])
		++nb_words;
	token = tokenize(words[nb_words - 1]);
	if (token == token_cmd)
		return (_show_cmds(words[nb_words - 1]), free_tab(words), 0);
	else if (token == token_path || token == token_path_file || token == token_path_dir)
		return (_show_paths(words[nb_words - 1], data), free_tab(words), 0);
	else
		return (free_tab(words), -1);
}

#pragma endregion Fonctions