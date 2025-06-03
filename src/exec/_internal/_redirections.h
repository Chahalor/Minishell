/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _redirections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:49:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/03 16:12:28 by nduvoid          ###   ########.fr       */
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

# define HEREDOC_ALLOC_SIZE 64	/* Size of the buffer for heredoc input */

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_exec_data	t_exec_data;	/* Execution data structure */

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

extern int	heredoc(
				const char *const restrict delimiter,
				int fd
				);

#endif /* _REDIRECTIONS_H */