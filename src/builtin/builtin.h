/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:10:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/25 12:46:38 by nduvoid          ###   ########.fr       */
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

char		builtin_cd(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		builtin_echo(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		builtin_env(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		builtin_export(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		builtin_pwd(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		builtin_unset(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		builtin_exit(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		builtin_history(
				const char **args,
				const int fd_in,
				const int fd_out
				);

#endif /* BUILTIN_H */