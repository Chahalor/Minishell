/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _exec.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:49:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/05 14:33:44 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EXEC_H
# define _EXEC_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <allowed.h>
# include <errno.h>

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
	//...

/* -----| Modules   |----- */
# include "ft_printf.h"
# include "global_manager.h"
# include "signals.h"

typedef struct s_exec_data	t_exec_data;	/* Execution data structure */

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

extern int	_wait_childrens(
				t_exec_data *const restrict data
				);

extern int	_redirect(
				const int fd,
				const int new_fd
				);

#endif /* _EXEC_H */