/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _global_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:52:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/24 15:36:21 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GLOBAL_MANAGER_H
# define _GLOBAL_MANAGER_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <sys/types.h>
# include <linux/limits.h>
# include <unistd.h>

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
	//...

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

/* -----| Types   |----- */
	//...

/* -----| Enums   |----- */

typedef enum e_gbl_access_			t_gbl_access;	/**/

/* -----| Structs |----- */

typedef struct s_global_manager_	t_global_manager;	/**/

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_gbl_access_
{
	_do_init,			/* Initialize the global manager */
	_get_last_child,	/* Get the last child pid       */
	_set_last_child,	/* Set the last child pid      */
	_get_current_path,	/* Get the current path       */
	_set_current_path,	/* Set the current path      */
};

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_global_manager_
{
	pid_t	last_child;				/* Pid if the last children */
	char	current_path[PATH_MAX];	/* Current path            */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

//...

#endif /* _GLOBAL_MANAGER_H */