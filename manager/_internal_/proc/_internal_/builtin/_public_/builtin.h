/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:10:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/24 10:02:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
	//...

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
# include "../_internal_/builtin__.h"
# include "../_internal_/types__.h"

/* -----| Modules  |----- */
# include "exec.h"
# include "utils.h"
# include "exit.h"

typedef struct s_exec_data	t_exec_data;	/* Execution data structure */

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// builtin.c

t_blt_link	*get_builtins(
				const char *const restrict args
				);

char		exec_builtin_fork(
				t_exec_data *args,
				char *const envp[],
				const int fd_in,
				const int fd_out
				);

char		exec_builtin(
				t_exec_data *args,
				char *const envp[],
				const int fd_in,
				const int fd_out
				);

#endif /* BUILTIN_H */