/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _exec.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:49:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/28 17:24:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EXEC_H
# define _EXEC_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <signal.h>

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
	//...

/* -----| Modules   |----- */
# include "ft_printf.h"
# include "global_manager.h"

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

extern int	_wait_childrens(
				t_exec_data *const restrict data
				);

#endif /* _EXEC_H */