/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/26 16:39:28 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_lexer.h"

/* -----| Modules   |----- */
#include "lexer.h"

#pragma endregion Header
#pragma region Fonctions

__attribute__((cold, visibility("hidden"))) char	*ft_strcat(
	const char *const restrict s1,
	const char *const restrict s2,
	const int size
)
{
	char *restrict		result;
	register const int	len_result = ft_strlen(s1) + ft_strlen(s2);
	register int		i;
	register int		j;

	result = mm_alloc(len_result + 1);
	if (__builtin_expect(!result, unexpected))
	{
		perror("ft_strcat(): mm_alloc() failed\n");
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j] && j < size)
	{
		result[i + j] = s2[j];
		++j;
	}
	result[i + j] = '\0';
	return (result);
}

static char	*get_in_path(
	const char *const restrict name
)
{
	char			**paths;
	register int	i;
	char 			*full_path;

	paths = ft_split(getenv("PATH"), ':');
	if (_UNLIKELY(!paths))
		return (perror("get_in_path(): ft_split() failed\n"), NULL);
	i = -1;
	while (paths[++i])
	{
		full_path = ft_strcat(paths[i], name, ft_strlen(name));
		if (_UNLIKELY(!full_path))
			return (perror("get_in_path(): ft_strcat() failed\n"), NULL);
		if (!access(full_path, F_OK))
			return (free_tab(paths), full_path);
		else
			mm_free(full_path);
	}
	return (free_tab(paths), perror("get_in_path(): command not found\n"),
		NULL);
}

/**
 * @version 0.1
*/
__attribute__((used)) t_exec_data	*built_exec_data(
	char *const restrict line
)
{
	t_exec_data		*data;

	data = (t_exec_data *)mm_alloc(sizeof(t_exec_data));
	if (_UNLIKELY(!data))
		return (perror("built_exec_data(): mm_alloc() failed\n"), NULL);
	data->args = ft_split(line, ' ');
	if (_UNLIKELY(!data->args))
		return (mm_free(data), perror("built_exec_data(): ft_split() failed\n"),
			NULL);
	if (!access(data->args[0], F_OK))
	{
		data->cmd = data->args[0];
		return (data);
	}
	data->cmd = get_in_path(data->args[0]);
	if (_UNLIKELY(!data->cmd))
		return (mm_free(data->args), mm_free(data), NULL);
	return (data);
}

/** */
__attribute__((hot)) t_exec_data	*lexer(
	const char *const restrict line
)
{
	char		**raw_cmds;
	t_exec_data	*data;
	t_exec_data	*current;

	raw_cmds = ft_split(line, '|');
	ft_fprintf(STDERR_FILENO, "raw_cmds: %s\n", *raw_cmds);
	data = built_exec_data(raw_cmds[0]);
	current = data;
	while (*++raw_cmds)
	{
		ft_fprintf(STDERR_FILENO, "raw_cmds: %s\n", *raw_cmds);
		current->pipe = built_exec_data(*raw_cmds);
		if (_UNLIKELY(!data))
			return (perror("lexer(): built_exec_data() failed"), NULL);
		if (data->pipe)
			data->pipe->next = data;
		else
			data->pipe = data;
		current = current->pipe;
	}
	if (_LIKELY(current != NULL))
		current->pipe = NULL;
	free_tab(raw_cmds);
	return (data);
}

#pragma endregion Fonctions