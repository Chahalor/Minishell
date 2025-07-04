/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:57:59 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/27 12:55:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _READ_LINE_H
# define _READ_LINE_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include "allowed.h"

/* -----| Globals   |----- */
# include "config.h"

/* -----| Internals |----- */
# include "read_line.h"

/* -----| Modules  |----- */
# include "utils.h"
# include "gnl/get_next_line.h"
# include "ft_printf.h"
# include "exit.h"
# include "formating.h"

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define _RL_ALLOC_SIZE	1024	/* Size of every alloc/realloc of Read_line */
# define _RL_ANSI_BUFF	16		/* Size of the ANSI handler buffer         */
# define _RL_COMP_LIMIT	124		/* Limit of files for the completion      */

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct dirent			t_dirent;

typedef enum e_rl_status		t_rl_status;		/* The status or rl:_read */
typedef enum e_rl_hist_access	t_rl_hist_access;	/* access to the history */
typedef enum e_rl_word_type		t_rl_word_type;		/* completions types    */

typedef struct s_rl_data		t_rl_data;			/* rl:_read data struct */
typedef struct s_rl_history		t_rl_history;		/* rl:hist data struct */
typedef struct s_rl_completion	t_rl_completion;	/* rl:completion struct */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum	e_rl_status
{
	error,		/* Error                 */
	eof,		/* End of file (Ctrl+D) */
	interr,		/* Interrupt (Ctrl+C)  */
	exiting,	/* Exiting mode       */
	normal,		/* Normal mode       */
	past,		/* Pasting text     */
};

enum	e_rl_hist_access
{
	rl_get_next,	/* get a line from the history          */
	rl_get_prev,	/* get a line from the history         */
	rl_get_all,		/* get all the lines from the history */
	rl_add,			/* add a line to the history         */
	rl_reset_pos,	/* reset the history position       */
	rl_clear,		/* clear the history               */
	rl_load,		/* load the history from a file   */
};

enum	e_rl_word_type
{
	token_cmd,			/* Command token (e.g., "ls" or "gre")           */
	token_path_file,	/* Path to a file (e.g., "/path/to/file.txt")   */
	token_path_dir,		/* Path to a directory (e.g., "/path/to/dir/") */
	token_path,			/* Path to a someting (e.g., "path/to/some")  */
	unknown,			/* Unknown token type (e.g., "1234")         */
};

enum e_rl_mode
{
	rl_chr,	/* Add a single character to the line */
	rl_str,	/* Add a string to the line          */
};

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct	s_terms
{
	struct termios	oldt;	/* Old terminal settings       */
	struct termios	raw;	/* Raw terminal settings      */
	struct termios	resore;	/* Restore terminal settings */
};

struct	s_rl_data
{
	char			*result;		/* The result string                */
	int				line_length;	/* The length of the line          */
	int				cursor_pos;		/* The position of the cursor     */
	char			*prompt;		/* The prompt string             */
	int				prompt_length;	/* The length of the prompt     */
	t_rl_status		status;			/* The status of the read_line */
	struct s_terms	terms;			/* The terminal settings      */
};

struct	s_rl_history
{
	char	*storage[_RL_HIST_SIZE + 1];	/* history storage                */
	int		pos;							/* current position              */
	int		size;							/* number of cmd in the history */
	int		fd;								/* history file descriptor     */
};

struct s_rl_completion
{
	struct dirent	*entry[_RL_COMP_LIMIT];		/* current directory entry */
	int				nb_entries;					/* number of entries      */
};

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

int			_rl_add(
				t_rl_data *const restrict data,
				const char *const restrict c,
				int mode
				);

int			_remove(
				t_rl_data *const restrict data
				);

int			refresh_line(
				t_rl_data *const restrict data
				);

int			_read(
				t_rl_data *const restrict data
				);

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

int			_move(
				t_rl_data *const restrict data,
				const char *const restrict cmd
				);

int			handle_ansi(
				t_rl_data *const restrict data
				);

// dir/_free.c

extern void	_free_completion(
				t_rl_completion *const restrict data
				);

// dir/_tokenize.c

int			is_dir(
				const char *const restrict path
				);

int			is_file(
				const char *const restrict word
				);

int			tokenize(
				const char *const restrict word
				);

// dir/dir.c

int			completion(
				t_rl_data *const restrict data
				);

#endif /* _READ_LINE_H */