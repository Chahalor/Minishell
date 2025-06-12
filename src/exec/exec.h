/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:46:56 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/12 15:27:56 by nduvoid          ###   ########.fr       */
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
# include "allowed.h"

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
# include "_internal/_exec.h"

/* -----| Modules   |----- */
# include "mmanager.h"
# include "builtin.h"
# include "utils.h"
# include "exit.h"

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_pipe_data	t_pipe_data;	/* Pipe data structure       */
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
	char		*cmd;	/* command to execute                                */
	char		**args;	/* arguments for the command                        */
	int			status;	/* status of the command                           */
	pid_t		pid;	/* process ID of the command                      */
	int			fd_in;	/* file descriptor for input redirection         */
	int			fd_out;	/* file descriptor for output redirection       */
	int			type;	/* type of redirection (e.g., infile, outfile) */
	t_exec_data	*pipe;	/* next commande to pipe output in            */
	t_exec_data	*next;	/* next commande to execute after this one   */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// exec.c

int			full_exec(
				t_exec_data *const restrict data,
				char *const envp[]
				);

// heredoc.c

int			heredoc(
				const char *const restrict delimiter,
				int fd
				);

int			heredoc_all(
				const char *const restrict delimiter
				);

#endif /* EXEC_H */