/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 14:36:33 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# undef TYPES_H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "parser.h"

/* --------- types ---------- */
	// ---- parser ----- //
# ifndef T_PARSE
#  define T_PARSE

typedef struct s_parse	t_parse;	// v.1. >>> tag: exp->t_parse

# endif

/* -------- structs --------- */
	// ---- parser ----- //
# ifndef S_PARSE
#  define S_PARSE

// public struct of parser module.
struct s_parse	// v.1. >>> tag: exp->s_parse
{
	// data :
	t_token	token;
	t_tree	*tree;
	// >>>
	// access :
	char	(*parse)(\
					const char *);
};

# endif

#endif