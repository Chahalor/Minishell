/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _lexer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:28:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/26 10:00:10 by nduvoid          ###   ########.fr       */
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
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef enum e_token_type	t_token_type;	/* Token types         */

typedef struct s_token		t_token;		/* Token structure  */

typedef struct s_exec_data	t_exec_data;	/* Execution data structure */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_token_type
{
	TOKEN_CMD,
	TOKEN_PIPE,
	TOKEN_QUOTE,
	TOKEN_DQUOTE,
	TOKEN_GREATER,
	TOKEN_LESS,
	TOKEN_DGREATER,
	TOKEN_DLESS,
	TOKEN_WORD,
	PARSER_ERR_NONE,
	PARSER_ERR_MISSING_QUOTE,
	PARSER_ERR_UNEXPECTED_TOKEN,
	PARSER_ERR_INVALID_REDIRECTION,
	PARSER_ERR_MEMORY_ALLOCATION
};

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_token
{
	char	*value;
	int		type;
	int		size;
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

char		*_get_bin(
				char *name
				);

#endif /* _LEXER_H */