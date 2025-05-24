/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:37:23 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/24 15:43:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
	//...

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
	//# include "_ft_printf.h"

/* -----| Modules  |----- */
	//...

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

/* -----| Interface.c |----- */

int	ft_printf(
		const char *const restrict str, ...);

int	debug_printf(
		const char *const restrict str, ...);

int	ft_fprintf( const int fd, const char *const restrict str, ...);

int	ft_sprintf(char *const restrict buffer, const char *const restrict str,
		...);

#endif