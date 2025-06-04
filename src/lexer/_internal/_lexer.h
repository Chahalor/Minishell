/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _lexer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:28:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/04 10:47:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEXER_H
# define _LEXER_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
	//...

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
# include "lexer.h"

/* -----| Modules   |----- */
	//...

/* ************************************************************************** */
/*                                 Sypedefs                                   */
/* ************************************************************************** */

typedef enum e_token_type	t_token_type;	/* Token type enumeration */

typedef struct s_token		t_token;		/* Token structure */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_token_type {
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_HEREDOC,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND
};

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_token
{
	t_token_type	type;	/* Type of the token           */
	char			*value;	/* Value of the token         */
	struct s_token	*next;	/* Pointer to the next token */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */


// build/pipes

t_exec_data	*build_pipe(
				t_token *tokens
				);

// build/infile

t_exec_data	*build_infile(
				const t_token *const restrict tokens
				);

// build/outfile

t_exec_data	*build_outfile(
				const t_token *const restrict tokens
				);

// build/heredoc

t_exec_data	*build_heredoc(
				const t_token *const restrict tokens
				);

// _lexer

t_token		*lex(
				const char *const restrict input
				);

void		print_tokens(
				t_token *tok
				);

#endif /* _LEXER_H */