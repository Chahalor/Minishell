/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _redirections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:49:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/04 08:51:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REDIRECTIONS_H
# define _REDIRECTIONS_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <fcntl.h>

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
# include "_exec.h"
# include "exec.h"

/* -----| Modules   |----- */
# include "ft_printf.h"
# include "global_manager.h"
# include "signals.h"

/* ************************************************************************** */
/*                                 Macros                                     */
/* ************************************************************************** */

# define HEREDOC_ALLOC_SIZE	32	/* Size of the buffer for heredoc input */

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_exec_data	t_exec_data;	/* Execution data structure      */
typedef struct s_heredoc	t_heredoc;		/* Heredoc data structure       */
typedef struct s_infile		t_infile;		/* Input file data structure   */
typedef struct s_outfile	t_outfile;		/* Output file data structure */

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_heredoc
{
	char	**storage;	/* Array of strings to store the lines */
	int		fd;			/* File descriptor for the heredoc    */
	int		nb_lines;	/* Number of lines read              */
};

struct s_infile
{
	int		fd;			/* File descriptor for the input file */
	char	*file;		/* Name of the input file            */
};

struct s_outfile
{
	int		fd;			/* File descriptor for the output file */
	char	*file;		/* Name of the output file            */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

/* -----| Pipes    | ----- */

extern int	_piping(
				int pipe_fd[2],
				int *out_fd
				);

/* -----| In       | ----- */

extern int	_infile(
				const char *const restrict file
				);

/* -----| Out      | ----- */

extern int	_outtruc(
				const char *const restrict file
				);

extern int	_outappend(
				const char *const restrict file
				);

/* -----| HereDocs | ----- */

char		**heredoc(
				const char *const restrict delimiter,
				int fd
				);

#endif /* _REDIRECTIONS_H */