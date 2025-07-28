/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server__.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:04:36 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/28 11:30:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SIGNALS_H
# define _SIGNALS_H

# pragma once

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif /* _GNU_SOURCE */

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