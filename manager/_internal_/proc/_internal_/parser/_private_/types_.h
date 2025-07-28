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

#ifndef TYPES__H
# define TYPES__H

# undef TYPES__H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "parser_.h"

/* --------- types ---------- */
	// ---- parser ----- //
# ifndef T_PARSE_
#  define T_PARSE_

typedef struct t_parse_	t_parse_;	// v.1. >>> tag: exp->t_parse_

# endif

/* -------- structs --------- */
	// ---- parser ----- //
# ifndef S_PARSE_
#  define S_PARSE_

// private struct of parser module.
struct s_parse_	// v.1. >>> tag: exp->s_parse_
{
	// data :
	t_token	token_;
	t_tree	*tree_;
	// >>>
	// access :
	char	(*parse_)(\
						const char *);
};

# endif

#endif