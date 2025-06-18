/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:08:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 09:29:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LINE_H
# define READ_LINE_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include "allowed.h"

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
# include "ft_printf.h"

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define RL_VERSION_MAJOR		0
# define RL_VERSION_MINOR		2
# define RL_VERSION_PATCH		0

# define _RL_HIST_SIZE	1024	/* Size of the history buffer */

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_history	t_history;		/* History struct */
typedef struct s_read_line	t_read_line;	/* Read line struct */

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct	s_history
{
	char	*storage[_RL_HIST_SIZE + 1];	/* history storage   */
	int		pos;							/* current position */
};

struct	s_read_line
{
	char *(*const		read_line)(const char *restrict prompt);
	char *(*const		add_history)(const char *const restrict line);
	void (*const		clear_history)(void);
	int (*const			load_history)(const char *const restrict filename);
	void (*const		reset_cmd)(void);
	t_history *(*const	get_all_history)(void);
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

t_read_line	*get_read_lines(void);

#endif /* READ_LINE_H */