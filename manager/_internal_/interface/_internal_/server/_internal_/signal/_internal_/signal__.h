/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal__.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:04:36 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/22 15:07:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SIGNALS_H
# define _SIGNALS_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <bits/types.h>
# include <signal.h>

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
	//...

/* -----| Modules   |----- */
	//...

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

extern void	_sigint_handler__(
				int signal,
				siginfo_t *info,
				void *context
				);

extern void	_sigquit_handler__(
				int signal,
				siginfo_t *info,
				void *context
				);

extern void	_sigstp_handler__(
				int signal,
				siginfo_t *info,
				void *context
				);

extern int	_reset_signal(void);

#endif /* _SIGNALS_H */