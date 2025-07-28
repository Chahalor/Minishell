/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interraction.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:28:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/23 17:31:37 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERACTION_H
# define INTERACTION_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
	//...

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
# include "../_internal_/types__.h"
# include "../_internal_/interraction__.h"

/* -----| Modules  |----- */
	//...

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_history	t_history;

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */


struct	s_history
{
	char	*storage[_RL_HIST_SIZE + 1];	/* history storage   */
	int		pos;							/* current position */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

char	*read_line(
				const char *const restrict prompt
				);

char	*rl_add_history(
				const char *const restrict line
				);

void	rl_clear_history(void);

int		rl_load_history(
				const char *const restrict filename
				);

t_history	*rl_get_history(void);

void	rl_reset_cmd(void);

#endif /* !INTERACTION_H */