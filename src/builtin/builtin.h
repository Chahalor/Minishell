/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:10:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 10:26:14 by nduvoid          ###   ########.fr       */
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
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
# include "_internal/_builtin.h"

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

// different builtin functions

char		bltin_cd(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_echo(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_env(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_export(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_pwd(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_unset(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_exit(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_history(
				const char **args,
				const int fd_in,
				const int fd_out
				);

#endif /* BUILTIN_H */