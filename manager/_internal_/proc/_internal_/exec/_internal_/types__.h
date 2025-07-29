/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 14:36:33 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES___H
# define TYPES___H

# undef TYPES___H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../../../standards/_public_/standards.h"

/* --------- enums ---------- */
	// ----- exec ------ //
# ifndef E_EXEC__
#  define E_EXEC__

// all internal exec module error codes.
enum e_exec_errors__	// v.1. >>> tag: def->e_exec_errors_
{
	exec_pipe_failed__	= -1,
};

# endif

/* --------- types ---------- */
	// ----- exec ------ //
# ifndef T_EXEC__
#  define T_EXEC__

typedef struct s_output__	t_output__;	// v.1. >>> tag: def->t_output_
typedef struct s_airdoc__	t_airdoc__;	// v.1. >>> tag: def->t_airdoc_
typedef struct s_exec__		t_exec__;	// v.1. >>> tag: def->t_exec

# endif

/* -------- structs --------- */
	// ----- exec ------ //
# ifndef S_EXEC__
#  define S_EXEC__

// internal output representation of exec module.
struct s_output__	// v.1. >>> tag: def->s_output_
{
	int				fd__;			/* File descriptor for the output file    */
	char			*file__;		/* Name of the output file                */
};

// internal airdoc representation of exec module.
struct s_airdoc__	// v.1. >>> tag: def->s_airdoc_
{
	int				fd__;			/* File descriptor for the heredoc        */
	unsigned int	len__;			/* Number of lines read                   */
	char			**storage__;	/* Array of strings to store the lines    */
};

// internal struct of exec module.
struct s_exec__		// v.1. >>> tag: def->s_exec
{
	char			builtin__;		/* is command builtin                     */
	pid_t			pid__;			/* process ID of the command              */
	int				status__;		/* status of the command                  */
	int				input__;		/* file descriptor for input redirection  */
	int				output__;		/* file descriptor for output redirection */
	int				type__;			/* type of redirection (infile, outfile)  */
	char			*name__;		/* command name                           */
	char			*cmd__;			/* command to execute                     */
	char			**args__;		/* arguments for the command              */
	t_exec__		*pipe__;		/* next commande to pipe output in        */
	t_exec__		*next__;		/* next commande to execute               */
};

# endif

#endif