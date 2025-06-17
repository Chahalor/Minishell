/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _signals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/17 14:30:46 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline int	_signals(
	const int status
)
{
	if (WTERMSIG(status) == SIGINT)
		return (130);
	else if (WTERMSIG(status) == SIGQUIT)
	{
		ft_fprintf(STDERR_FILENO, "Quit\n");
		return (131);
	}
	else if (WTERMSIG(status) == SIGTERM)
	{
		ft_fprintf(STDERR_FILENO, "Terminated\n");
		return (143);
	}
	else if (WTERMSIG(status) == SIGKILL)
	{
		ft_fprintf(STDERR_FILENO, "Killed\n");
		return (137);
	}
	else if (WCOREDUMP(status))
	{
		ft_fprintf(STDERR_FILENO, "Core dumped\n");
		return (128 + WTERMSIG(status) + 128);
	}
	else
		return (128 + WTERMSIG(status));
}

/** */
__attribute__((always_inline, used)) static inline int	_stop(
	const int status
)
{
	ft_fprintf(STDERR_FILENO, "Stopped\n");
	return (128 + WSTOPSIG(status));
}

/**
 * @brief	Analyses the status of a child process.
 * 
 * @param	status	The status returned by waitpid.
 * 
 * @return	Returns the exit status of the child process.
 * @retval		>0 if the child process exited normally.
 * @retval		<0 if the child process was terminated by a signal.
 * 
 * @version	1.0
 * 
 * @todo: should update the $? variable in the shell.
 */
__attribute__((used)) int	_analyse(
	const int status
)
{
	ft_fprintf(STDERR_FILENO, "Status: %d\n", status);
	if (WIFEXITED(status))
	{
		ft_fprintf(STDERR_FILENO, "Exited with status %d\n", WEXITSTATUS(status));
		return (WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status))
		return (_signals(status));
	else if (WIFSTOPPED(status))
		return (_stop(status));
	else
		return (-1);
}

#pragma endregion Fonctions