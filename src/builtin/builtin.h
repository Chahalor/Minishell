/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:10:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/26 15:56:02 by nduvoid          ###   ########.fr       */
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
	//...

/* -----| Modules  |----- */
# include "utils.h"
# include "exit.h"

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// builtin.c

extern char	is_builtin(
				const char *const restrict args
				);

char	exec_builtin(
				const char *const restrict args
				);

// different builtin functions

char		bltin_cd(
				const char **args
				);

char		bltin_echo(
				const char **args
				);

char		bltin_env(
				const char **args
				);

char		bltin_export(
				const char **args
				);

char		bltin_pwd(
				const char **args
				);

char		bltin_unset(
				const char **args
				);

#endif /* BUILTIN_H */