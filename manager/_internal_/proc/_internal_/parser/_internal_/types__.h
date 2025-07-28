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

#ifndef TYPES___H
# define TYPES___H

# undef TYPES___H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../../standards/_public_/standards.h"

/* --------- types ---------- */
	// ---- parser ----- //
# ifndef T_PARSE__
#  define T_PARSE__

typedef struct s_parse__	t_parse__;	// v.1. >>> tag: def->t_parse

# endif

/* -------- structs --------- */
	// ---- parser ----- //
# ifndef S_PARSE__
#  define S_PARSE__

// internal struct of parser module.
struct s_parse__	// v.1. >>> tag: def->s_parse
{
	// data :
	t_token	token__;
	t_tree	*tree__;
	// >>>
	// access :
	char	(*parse__)(\
						const char *);
};

# endif

#endif