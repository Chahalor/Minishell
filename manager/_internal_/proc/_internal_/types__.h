/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/29 13:01:58 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TYPES_H
# define _TYPES_H

# undef _TYPES_H
# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./tokenizer/tokenizer.h"

/* --------- types ---------- */
	// --- processor --- //
# ifndef _T_PROCESSOR
#  define _T_PROCESSOR

typedef struct s_command_		t_command_;		// v.1. >>> tag: set->t_command
typedef struct s_redir_			t_redir_;		// v.1. >>> tag: set->t_redir
typedef struct s_section_		t_section_;		// v.1. >>> tag: set->t_section
typedef struct s_processor_		t_processor_;	// v.1. >>> tag: set->t_processor

# endif

/* -------- structs --------- */
	// --- processor --- //
# ifndef _S_PROCESSOR
#  define _S_PROCESSOR

// command representation.
struct s_command_	// v.1. >>> tag: set->s_command
{
	unsigned char			*cmd;			// command to execute.
	unsigned char			cond;			// condition to run command
											// (true / false / none).
	unsigned int			order;			// global processing order.
	char					**args;			// command args to proceed with.
};
// redirection representation (data forwarding).
struct s_redir_		// v.1. >>> tag: set->s_redir
{
	unsigned char			id;				// id of the redirection to process.
	unsigned int			order;			// global processing order.
	char					*src;			// source path to fetch data.
	char					*dest;			// destination path to forward data.
	/*
	 * If src / dest is leaved blank, it means it's either the order - 1
	 * or order + 1 command to be used as the source or destination for
	 * data forwarding.
	*/
	char					*content;		// content to forward.
};
// section of the redirects.
struct s_section_	// v.1. >>> tag: set->s_section
{
	t_command_				*cmd;			// commands to process.
	t_redir_				*redir;			// link / redirs to process.
	/*
	 * Shall hold up to 255 command / links inside channel 1 and 2.
	*/
};
// core command processor.
struct s_processor_	// v.1. >>> tag: set->s_processor
{
	unsigned char			_index;			// index of the section.
	unsigned int			_order;			// order within the section.
	t_tokenizer				_tokenizer;			// tokenized representation of the command.
	t_section_				*_command;		// processed command format.
	/*
	 * A command is splitted into multiples small commands and links.
	*/
	// >>>
	// methods goes here ...
};

# endif

#endif