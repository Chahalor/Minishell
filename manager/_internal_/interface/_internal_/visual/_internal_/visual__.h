/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual__.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:27:18 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/22 14:37:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL___H
# define VISUAL___H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
	//...

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
# include "types__.h"

/* -----| Modules  |----- */
	//...

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

/* -----| utils    |----- */

extern void		ft_bzero(
					const void *const restrict s,
					register const int n
					);

extern int		printf_strlen(
					const char *const restrict str
					);

extern t_print	_init_print(
					void *buffer,
					int fd,
					int buffer_len
					);

extern int		_add(
					t_print *const restrict print,
					const char c
					);

/* -----| printf  |----- */

extern int		write_loop__(
					const char *s,
					va_list args,
					t_print *const restrict print
					);

extern int		addstr__(
					const char *const restrict s,
					t_print *const restrict print
					);

extern int		adddec__(
					long dec,
					t_print *const restrict print
					);

extern int		addptr__(
					const void *const restrict ptr,
					t_print *const restrict print
					);

extern int		addhex__(
					unsigned long nb,
					t_print *const restrict print,
					const char *const restrict base
					);

/* -----| fprintf |----- */
	//...

/* -----| sprintf |----- */
	//...

#endif /* VISUAL___H */