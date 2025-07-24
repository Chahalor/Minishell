/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:57:59 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/24 08:19:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES___H
# define TYPES___H
# undef TYPES___H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <termios.h>
# include <unistd.h>
# include <stdlib.h>

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
	//...

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define _RL_HIST_SIZE	1024	/* Size of the history buffer                */
# define _RL_ALLOC_SIZE	1024	/* Size of every alloc/realloc of Read_line */
# define _RL_ANSI_BUFF	16		/* Size of the ANSI handler buffer         */
# define _RL_COMP_LIMIT	124		/* Limit of files for the completion      */

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct dirent			t_dirent;

typedef enum e_file				t_file_type;		/* File type enumeration  */
typedef enum e_rl_status		t_rl_status;		/* The status or rl:_read */
typedef enum e_rl_hist_access	t_rl_hist_access;	/* access to the history */
typedef enum e_rl_word_type		t_rl_word_type;		/* completions types    */

typedef struct s_rl_data		t_rl_data;			/* rl:_read data struct */
typedef struct s_rl_history		t_rl_history;		/* rl:hist data struct */
typedef struct s_rl_completion	t_rl_completion;	/* rl:completion struct */

typedef struct s_history		t_history;			/* history struct */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum	e_file
{
	e_not_found = 0,	/* File not found             */
	e_file,				/* File is a regular file    */
	e_directory,		/* File is a directory      */
	e_symlink,			/* File is a symbolic link */
	e_unknown,			/* Unknown file type      */
	e_executable,		/* File is executable    */
};

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

struct	s_history
{
	char	*storage[_RL_HIST_SIZE + 1];	/* history storage   */
	int		pos;							/* current position */
};

#endif /* TYPES___H */