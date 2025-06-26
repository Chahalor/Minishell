/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 14:03:12 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_C
# define HISTORY_C

/* -------- modules --------- */
	// ---- access ----- //
# include "history.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used))
//	(-public-)
extern char	load_history(void)	// v.1. >>> tag: exp->load_history
{
	return (_load_history(\
				(t_histo_ *restrict const)&get_manager(NULL)->histo));
}

// doc ...
__attribute__((cold, used))
//	(-public-)
extern void	unload_history(void)	// v.1. >>> tag: exp->unload_history
{
	return (_unload_history(\
				(t_histo_ *restrict const)&get_manager(NULL)->histo));
}

// doc ...
__attribute__((cold, used))
//	(-public-)
extern char	show_history(void)	// v.1. >>> tag: exp->show_history
{
	return (_show_history(\
				(t_histo_ *restrict const)&get_manager(NULL)->histo));
}

// doc ...
__attribute__((hot, used))
//	(-public-)
extern char	add_entry(\
	const char *restrict const command
)	// v.1. >>> tag: exp->add_entry
{
	return (_add_entry(\
				(t_histo_ *restrict const)&get_manager(NULL)->histo, \
				command));
}

// doc ...
__attribute__((hot, used))
//	(-public-)
extern char *get_entry(\
	const unsigned int index
)	// v.1. >>> tag: exp->get_entry
{
	return (_get_entry(\
				(t_histo_ *restrict const)&get_manager(NULL)->histo, \
				index));
}

#endif