/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:19:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/01 14:52:39 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <sys/stat.h>

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
# include "_internal/_lexer.h"

/* -----| Modules   |----- */
# include "exec.h"

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_ast	t_ast;		/* Abstract syntax tree structure */
typedef struct s_lexer	t_lexer;	/* Lexer structure               */
typedef struct s_token	t_token;	/* Token structure              */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

t_exec_data	*lexer(
				const char *const restrict line
				);

// t_ast	*tokenize_line(
// 				const char *const restrict line
// 				);

t_ast		*parse_pipeline(
				t_lexer *lxr
				);

t_ast		*full_ast(
				char **input
				);

void		token_free_all(
				t_token *toks
				);

void		ast_destroy(
				t_ast *n
				);

t_exec_data	*token_to_exec(
				t_token **tokens
				);

t_token		**tokenize_line(
				const char *const restrict line,
				int *const restrict count
				);

void		print_tokens(
				t_token **tokens,
				const int count
				);

void		print_exec(
				const t_exec_data *const restrict exec
				);

#endif /* LEXER_H */