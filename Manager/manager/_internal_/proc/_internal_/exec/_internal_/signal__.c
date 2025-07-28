/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/28 11:02:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "exec__.h"
#include "types__.h"

/* -----| Modules   |----- */
#include "../_public_/types.h"
#include "standards.h"

#pragma endregion Header
#pragma region Fonctions

static inline void	_update_env(
	const int exit_code
)
{
	if (expect(_manager()->env.set("?", exit_code) == 0))
		return ;
	ft_fprintf(STDERR_FILENO, "signal__: Failed to update $? variable\n");
}

/** */
__attribute__((always_inline, used))
static inline int	_signals(
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
		return (128 + WTERMSIG(status));
	}
	else
		return (128 + WTERMSIG(status));
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
__attribute__((used, always_inline))
static inline int	_analyse(
	const int status
)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (_signals(status));
	else if (WIFSTOPPED(status))
	{
		ft_fprintf(STDERR_FILENO, "Stopped\n");
		return (128 + WSTOPSIG(status));
	}
	else
		return (-1);
}

/**
 * @brief	Waits for all child processes to finish and updates their status.
 * 
 * @param	data	The execution data structure containing the child processes.
 * 
 * @return	Returns 0 on success.
 * @retval		0 if all child processes have been waited for successfully.
 * 
 * @version	1.0
 */
__attribute__((always_inline, used))
inline int	_exec_wait_childrens(
	t_exec_data *const restrict data
)
{
	int			status;
	t_exec_data	*curr;
	int			last_exit;

	status = 0;
	curr = (t_exec_data *)data;
	if (expect(curr->pid > 0 && waitpid(curr->pid, &status, 0)) != -1)
		curr->status = _analyse(status);
	last_exit = curr->status;
	if (expect(curr->pipe != NULL))
		last_exit = _exec_wait_childrens(curr->pipe);
	return (last_exit);
}

#pragma endregion Fonctions