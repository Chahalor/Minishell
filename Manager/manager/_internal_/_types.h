/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/12 12:07:38 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TYPES_H
# define _TYPES_H

# undef _TYPES_H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../standards/standards.h"

/* --------- types ---------- */
	// ---- manager ---- //
# ifndef _T_MANAGER
#  define _T_MANAGER

typedef struct s_params_		t_params_;		// v.1. >>> tag: set->t_params
typedef struct s_manager_		t_manager_;		// v.1. >>> tag: set->t_manager

# endif

/* -------- structs --------- */
	// ---- manager ---- //
# ifndef _S_MANAGER
#  define _S_MANAGER

// TODO: perhaps we'll also create a prompt struct for prompt style parameters.
// if one of those struct is used between prompt and params, we'll need to create
// an object like module of those.

// params of the shell.
struct s_params_	// v.1. >>> tag: set->s_params
{
	// all of the specific parameters needed such as color infos ...
};

// core manager storage.
struct s_manager_	// v.1. >>> tag: set->s_manager
{
	t_mem					_memory;
	t_params_				params;
	t_state_				state;
	t_env_					env;
	t_histo_				histo;
	unsigned char			index;		// index of the section.
	unsigned int			order;		// order processed within the section.
	t_section_				*command;
	/*
	 * A command is splitted into multiples small commands and links.
	*/
	// >>>
	// Both the two structs here shall be used for a command. but
	// they both also shall be stored inside the manager struct.
	char					(*proc)(void);	// temp args.
	// shall call and use the processor struct. for this command.
	char					(*exec)(void);	// temp args.
	// shall call and use the exec struct. for this command.
};

# endif

#endif