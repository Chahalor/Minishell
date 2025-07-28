/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:46:56 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/24 08:40:53 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# undef TYPES_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <sys/types.h>

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
# include "../_internal_/types__.h"

/* -----| Modules   |----- */
	//...

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


#endif /* !TYPES_H */