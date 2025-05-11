/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:57:59 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/11 15:51:41 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _READ_LINE_H
# define _READ_LINE_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <termios.h>
# include <unistd.h>
# include <stdlib.h>

/* -----| Globals   |----- */
# include "config.h"

/* -----| Internals |----- */
# include "read_line.h"

/* -----| Modules  |----- */
# include "utils.h"

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define RL_MAX_BUFFER	4096

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// _utils.c

extern void	_set_raw(
				struct termios *t
				);

extern void	_set_default(
				struct termios *t
				);

extern void	move_cursor(
				const int row,
				const int col
				);

#endif /* _READ_LINE_H */