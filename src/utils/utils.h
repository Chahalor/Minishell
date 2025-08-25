/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:03:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/25 10:35:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include "allowed.h"

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
# include "mmanager.h"

typedef enum e_file	t_file_type;	/* File type enumeration */

enum	e_file
{
	e_not_found = 0,	/* File not found             */
	e_file,				/* File is a regular file    */
	e_directory,		/* File is a directory      */
	e_symlink,			/* File is a symbolic link */
	e_unknown,			/* Unknown file type      */
	e_executable,		/* File is executable    */
};

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

int			is_nbr(
				const char *const restrict str
				);

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

// files.c

int			check_path(
				const char *const restrict path,
				const int flags
				);

// ft_itoa.c

char		*ft_itoa(
				const int n
				);

#endif /* UTILS_H */