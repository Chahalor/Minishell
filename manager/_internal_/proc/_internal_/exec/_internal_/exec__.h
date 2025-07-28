/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec__.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:49:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/24 09:25:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC___H
# define EXEC___H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <sys/wait.h>

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
# include "./types__.h"

/* -----| Modules   |----- */
	//...



/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

extern int	_exec_wait_childrens(
				t_exec_data *const restrict data
				);

int			exec_bin__(
				t_exec_data *const restrict data,
				char *const envp[],
				const int prev_read,
				const int out_fd
				);

/* -----| HereDocs | ----- */

int			_heredoc__(
				const char *const restrict delimiter,
				int fd
				);

#endif /* !EXEC___H */