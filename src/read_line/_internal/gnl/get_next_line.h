/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:35:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 07:55:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <stdlib.h>
# include <unistd.h>

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
# include "_get_next_line.h"

/* ************************************************************************** */
/*                                 Marcos                                     */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef GNL_ALLOC_SIZE
#  define GNL_ALLOC_SIZE 1024
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// get_next_line.c

char	*get_next_line(const int fd);
char	*gnl(const int fd);
int		count_lines(const int fd);

#endif