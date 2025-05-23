/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/23 15:14:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_exec.h"

/* -----| Modules   |----- */
#include "exec.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((hot))	int	piping(
	t_exec_data *const restrict data,
	char *const envp[]
)
{
	pid_t	pid;
	pid_t	pid2;
	int		pipefd[2];

	if (_UNLIKELY(!data || !data->cmd || !data->args))
		return (perror("piping(): data is NULL"), -1);
	
	pipe(pipefd);

	pid = fork();
	if (pid == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(data->cmd, data->args, envp);
	}

	pid2 = fork(); 
	if (pid2 == 0)
	{
		// Enfant 2
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		close(pipefd[0]);
		execve(data->pipe->cmd, data->pipe->args, envp);
	}

	// Parent
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

#pragma endregion Fonctions