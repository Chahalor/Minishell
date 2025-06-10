/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:19:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/10 08:30:00 by nduvoid          ###   ########.fr       */
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

typedef enum e_file	t_file_type;	/* File type enumeration */

typedef struct s_ast	t_ast;		/* Abstract syntax tree structure */
typedef struct s_lexer	t_lexer;	/* Lexer structure */
typedef struct s_token	t_token;	/* Token structure */

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
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

t_exec_data	*lexer(
				const char *const restrict line
				);

// t_ast	*tokenize_line(
// 				const char *const restrict line
// 				);

t_ast	*parse_pipeline(
				t_lexer *lxr
				);

t_ast	*full_ast(
				char **input
				);

void	token_free_all(
				t_token *toks
				);

void	ast_destroy(
				t_ast *n
				);

#endif /* LEXER_H */