/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interraction__.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:57:59 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/28 09:38:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INTERACTION___H
# define _INTERACTION___H

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
# include "manager_.h"

/* -----| Modules  |----- */
	//...

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// _read_line.c

void		_rl_reset_cmd(void);
t_history	*_rl_get_all(void);

// _init.c

extern void	_init_cmd(
				t_rl_data *const restrict data
				);

// _read.c

int			_rl_add__(
				t_rl_data *const restrict data,
				const char *const restrict c,
				int mode
				);

int			_rl_remove__(
				t_rl_data *const restrict data
				);

int			refresh_line(
				t_rl_data *const restrict data
				);

int			_read(
				t_rl_data *const restrict data
				);

// _utils.c

extern void	_rl_set_raw__(
				struct termios *t
				);

extern void	_rl_set_default__(
				struct termios *t
				);

extern void	move_cursor(
				const int row,
				const int col
				);

extern void	save_cursor(void);

extern void	restore_cursor(void);

// history/history.c

char		*_history_manager(
				const int access,
				const char *const restrict line
				);

// history/_load.c

int			_load_history(
				const char *const restrict filename,
				t_rl_history *const restrict data
				);

// ansi/_ansi.c

int			_rl_move__(
				t_rl_data *const restrict data,
				const char *const restrict cmd
				);

int			_rl_handle_ansi__(
				t_rl_data *const restrict data
				);

// dir/_free.c

extern void	_rl_free_completion__(
				t_rl_completion *const restrict data
				);

// dir/_tokenize.c

int			is_dir(
				const char *const restrict path
				);

int			is_file(
				const char *const restrict word
				);

int			_rl_tokenize__(
				const char *const restrict word
				);

// dir/dir.c

int			completion(
				t_rl_data *const restrict data
				);

// init__.c

char	*_rl_read_line__(
				const char *const restrict prompt
				);

void	_rl_reset_cmd__(void);

#endif /* _INTERACTION___H */