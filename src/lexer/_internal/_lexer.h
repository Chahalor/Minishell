/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _lexer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:28:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/12 10:38:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEXER_H
# define _LEXER_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

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
typedef struct s_exec_data	t_exec_data;	/* Execution data structure */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

typedef enum e_tok_type
{
	TOK_WORD,
	TOK_PIPE,
	TOK_LESS,
	TOK_GREAT,
	TOK_DLESS,
	TOK_DGREAT,
	TOK_EOF,
	TOK_ERR
}	t_tok_type;

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}	t_redir_type;

typedef enum e_node_type
{
	NODE_CMD,
	NODE_PIPE
}	t_node_type;

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

typedef struct s_token
{
	t_tok_type				type;
	char					*value;
}	t_token;

typedef struct s_lexer
{
	t_token					*tokens;
	size_t					pos;
}	t_lexer;

typedef struct s_redir
{
	t_redir_type			type;
	char					*file;
	struct s_redir			*next;
}	t_redir;

typedef struct s_cmd
{
	char					**argv;
	t_redir					*redirs;
}	t_cmd;

typedef struct s_ast
{
	t_node_type				type;
	union
	{
		t_cmd				cmd;
		struct
		{
			struct s_ast	*lhs;
			struct s_ast	*rhs;
		}					pipe;
	}						data;
}	t_ast;

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

void		print_tokens(
				t_token *tok
				);

char		*_get_bin(
				char *name
				);

#endif /* _LEXER_H */