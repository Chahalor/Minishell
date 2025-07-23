/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:57:59 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/23 18:21:13 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _READ_LINE_H
# define _READ_LINE_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
	//...

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
# include "types__.h"

/* -----| Modules  |----- */
	//...

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// read_line__.c
extern void			_rl_reset_cmd(void);
extern t_history	*_rl_get_all(void);

// init__.c
extern char			*_rl_read_line__(
						const char *const restrict prompt
						);

extern void			_rl_reset_cmd(void);

extern void			_init_cmd(
						t_rl_data *const restrict data
						);

// manage__.c
extern int			_rl_add__(
						t_rl_data *const restrict data,
						const char *const restrict c,
						int mode
						);

// read__.c
extern int			_rl_remove__(
						t_rl_data *const restrict data
						);

extern int			_rl_read__(
						t_rl_data *const restrict data
						);

// utils__.c
extern void			_rl_set_raw__(
						struct termios *t
						);

extern void			_rl_set_default__(
						struct termios *t
						);

// history/history__.c

extern void			*_history_manager__(
						const int access,
						const char *const restrict line
						);

// history/load__.c

extern int			_load_history__(
						const char *const restrict filename,
						t_rl_history *const restrict data
						);

// ansi/_ansi.c

extern int			_move(
						t_rl_data *const restrict data,
						const char *const restrict cmd
						);

extern int			handle_ansi(
						t_rl_data *const restrict data
						);

// dir/_free.c

extern void			_free_completion(
						t_rl_completion *const restrict data
						);

// dir/_tokenize.c

extern int			is_dir(
						const char *const restrict path
						);

extern int			is_file(
						const char *const restrict word
						);

extern int			tokenize(
						const char *const restrict word
						);

// dir/dir.c

extern int			completion(
						t_rl_data *const restrict data
						);

#endif /* _READ_LINE_H */