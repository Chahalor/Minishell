/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer__.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 14:35:34 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE__H
# define TREE__H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/tree__.h"

	// ----- local ----- //
# include "./types_.h"

/* ------- prototypes ------- */
	// ---- private ---- //
// access :
extern t_tree_			*_tree_get(\
							t_tree_	*restrict const new_
							)
						__attribute__((\
							hot, used, \
							visibility("hidden")));
extern t_tree_			*_tree_self(void)
						__attribute__((\
							hot, used, \
							visibility("hidden")));
// builtin :
extern char				_tree_builtin(\
							const char *restrict const target_
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// add :
extern char				_tree_cmd(\
							t_tree **cmd_,
							const unsigned int size_
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
extern t_tree_			*_tree_pipe(\
							const t_tree_ *const left_,
							const t_tree_ *const right_
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
extern char				_tree_redir(\
							t_tree *restrict const cmd_,
							const t_tree_redir_type__ type_,
							const char *restrict const target_
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// remove :
extern char				*_tree_unload_redir(\
							t_tree_redir_ *redir_
							)
						__attribute__((\
							hot, used, \
							visibility("hidden")));
extern void				_tree_unload(void)
						__attribute__((\
							hot, used, \
							visibility("hidden")));
// find :
extern t_tree_redir_	**_find_last_redir(\
							t_tree *restrict const cmd_
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// size :
extern int				_tree_size(\
							const t_token_object *restrict const token_
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// parse :
extern char				_tree_parse_redir(\
							const t_token_object *token_
							)
						__attribute__((\
							hot, used, \
							visibility("hidden")));
extern t_tree_			*_tree_parse_cmd(\
							const t_token_object *token_
							)
						__attribute__((\
							hot, used, \
							visibility("hidden")));
extern t_tree_			*_tree_parse(\
							const t_token_object *token_
							)
						__attribute__((\
							hot, used, \
							visibility("hidden")));

#endif