/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:46:56 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/26 12:23:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
# include "_internal/_exec.h"

/* -----| Modules   |----- */
# include "mmanager.h"
# include "utils.h"
# include "exit.h"

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_exec_data	t_exec_data;	/* Execution data structure */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_exec_data
{
	char		*cmd;	/* command to execute                           */
	char		**args;	/* arguments for the command                   */
	int			status;	/* status of the command                      */
	pid_t		pid;	/* process ID of the command                 */
	t_exec_data	*pipe;	/* next commande to pipe output in          */
	t_exec_data	*next;	/* next commande to execute after this one */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// exec.c

int			full_exec(
				t_exec_data *const restrict data,
				char *const envp[]
				);

// piping.c

int			piping(
				t_exec_data *const restrict data,
				char *const envp[]
				);

#endif /* EXEC_H */