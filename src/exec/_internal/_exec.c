/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _exec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/29 13:05:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_exec.h"

/* -----| Modules   |----- */
#include "exec.h"

#pragma endregion Header
#pragma region Fonctions

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
 */
__attribute__((always_inline, used)) static inline int	_analyse(
	const int status
)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
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
__attribute__((always_inline, used)) inline int	_wait_childrens(
	t_exec_data *const restrict data
)
{
	int						status;
	t_exec_data	*restrict	current;

	current = data;
	while (current)
	{
		if (current->pid)
		{
			waitpid(current->pid, &status, 0);
			current->status = _analyse(status);
		}
		current = data->next;
	}
	return (0);
}

#pragma endregion Fonctions