/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/15 14:21:09 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_exec.h"

/* -----| Modules   |----- */
#include "exec.h"
#include <errno.h>

#pragma endregion Header
#pragma region Fonctions

__attribute__((deprecated)) char *ft_strcat(
	const char *const restrict s1,
	const char *const restrict s2,
	const int size
)
{
	char	*restrict result;
	register const int len_result = ft_strlen(s1) + ft_strlen(s2);
	register int	i;
	register int	j;

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

__attribute__((deprecated)) t_exec_data	*built_exec_data(
	char *const restrict line
)	// v.1. >> test fonction tkt
{
	t_exec_data	*data;
	register int	len_cmd;

	data = mm_alloc(sizeof(t_exec_data));
	if (!data)
	{
		perror("built_exec_data(): mm_alloc() failed\n");
		return (NULL);
	}
	else
	{
		data->args = ft_split(line, ' ');
		len_cmd = 0;
		while (data->args[0][len_cmd])
			++len_cmd;
		data->cmd = ft_strcat("/bin/", data->args[0], len_cmd);
		if (!data->cmd || !data->args)
		{
			perror("built_exec_data(): a memdup() failed");
			return (mm_free(data->cmd), mm_free(data->args), mm_free(data), NULL);
		}
	}
	return (data);
}

/** */
__attribute__((hot))	int	exec_cmd(
	t_exec_data *const restrict data,
	char *const envp[]
)
{
	int	pid;
	
	if (!data || !data->cmd || !data->args)
	{
		perror("exec_cmd(): data is NULL");
		return (-1);
	}
	pid = fork();
	ft_printf("pid: %d\n", pid);
	if (pid == -1)
	{
		perror("exec_cmd: fork() failed\n");
		return (-1);
	}
	else if (pid == 0)
	{
		ft_printf("execve: %s\n", data->cmd);
		const int out = execve(data->cmd, data->args, envp);
		exit_program(out, "execve()\n");
	}
	else
	{
		waitpid(pid, &data->status, 0);
		if (WIFEXITED(data->status))
			data->status = WEXITSTATUS(data->status);
		else
			data->status = -1;
	}
	// free(data->cmd);
	// free(data->args);
	// free(data);
	return (data->status);
}

#pragma endregion Fonctions