/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:03:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/03 10:17:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
# include "mmanager.h"

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// ft_split.c

char		**ft_split(
				const char *const restrict s,
				const char c
				);

void		free_tab(
				char **tab
				);

// utils.c

extern int	ft_strncmp(
				const char *const restrict s1,
				const char *const restrict s2,
				size_t n
				);

extern int	ft_strlen(
				const char *const restrict str
				);

extern void	_neutral(
				void *restrict const area,
				const unsigned int size
				);

extern void	*memdup(
				const void *const restrict src,
				size_t size
				);

extern void	ft_memcpy(
				void *restrict dst,
				const void *const restrict src,
				size_t size
				);

// utils2.c

int			ft_atoi(
				const char *restrict str
				);

char		*path_join(
				const char *const restrict path1,
				const char *const restrict path2,
				const int size
				);

char		*ft_strchr(
				const char *const restrict str,
				const char *const restrict target
				);

int			arraylen(
				const void *const *array
				);

#endif /* UTILS_H */