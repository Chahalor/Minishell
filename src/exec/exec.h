/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:46:56 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/15 14:19:23 by nduvoid          ###   ########.fr       */
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
# include <string.h>

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
# include "_internal/_exec.h"

/* -----| Modules   |----- */
# include "mmanager.h"
# include "utils.h"
# include "exit.h"

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// exec.c

t_exec_data	*built_exec_data(
				char *const restrict line
				);

int			exec_cmd(
				t_exec_data *const restrict data,
				char *const envp[]
				);

#endif /* EXEC_H */