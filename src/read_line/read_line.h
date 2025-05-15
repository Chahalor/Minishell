/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:08:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/15 09:06:44 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LINE_H
# define READ_LINE_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <termios.h>
# include <unistd.h>
# include <stdio.h>

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
	//...

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define RL_VERSION_MAJOR		0
# define RL_VERSION_MINOR		1
# define RL_VERSION_PATCH		0

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

# if ENABLE_RL == 1

char	*read_line(
			const char *restrict prompt
			);

char	*rl_add_history(
			const char *const restrict line
			);

void	rl_clear_history(void);

int		rl_load_history(
			const char *const restrict filename
			);

void	reset_cmd(void);

# endif

#endif /* READ_LINE_H */