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

#ifndef TREE___H
# define TREE___H

# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "./types__.h"

	// ---- private ---- //
# include "../_private_/tree_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char				__tree_init(\
							t_tree_ *restrict const tree__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// access :
extern t_tree_			*__tree_get(\
							t_tree_	*restrict const new__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
extern t_tree_			*__tree_self(void)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// builtin :
extern char				__tree_builtin(\
							t_mem *restrict const mem__,
							const char *restrict const target__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// add :
extern char				__tree_cmd(\
							t_mem *restrict const mem__,
							t_tree **cmd__,
							const unsigned int size__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
extern t_tree_			*__tree_pipe(\
							t_mem *restrict const mem__,
							const t_tree_ *const left__,
							const t_tree_ *const right__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
extern char				__tree_redir(\
							t_mem *restrict const mem__,
							t_tree *restrict const cmd__,
							const t_tree_redir_type__ type__,
							const char *restrict const target__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// remove :
extern char				*__tree_unload_redir(\
							t_mem *restrict const mem__,
							t_tree_redir_ *redir__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
extern void				__tree_unload(\
							t_tree_ *tree__,
							t_mem *restrict const mem__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// find :
extern t_tree_redir_	**__find_last_redir(\
							t_tree *restrict const cmd__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// size :
extern int				__tree_size(\
							const t_token_object__ *restrict const token__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// parse :
extern char				__tree_parse_redir(\
							t_mem *restrict const mem__,
							t_tree_ *restrict const cmd__,
							const t_token_object__ *token__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
extern t_tree_			*__tree_parse_cmd(\
							t_mem *restrict const mem__,
							const t_token_object__ *token__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
extern t_tree_			*__tree_parse(\
							const t_token_object__ *token__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// tree :
extern char				__tree(\
							const t_token_object__ *token__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));

#endif