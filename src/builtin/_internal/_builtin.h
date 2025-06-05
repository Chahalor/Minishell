/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _builtin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:15:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/05 10:38:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUILTIN_H
# define _BUILTIN_H

# pragma once

# include "formating.h"

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_blt_link	t_blt_link;	/* Builtin link structure */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_echo_error
{
	echo_error_none = 0,			/* No error                          */
	echo_error_too_many_args = 1,	/* Too many arguments error         */
	echo_error_no_such_file = 2,	/* No such file or directory error */
};

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_blt_link
{
	const char	*name;								/* Builtin name           */
	char		(*func)(const char **, const int, const int);
};

struct s_args_echo
{
	unsigned char	nl		: 1;	/* Newline flag           */
	unsigned char	help	: 1;	/* Help flag             */
};

struct s_args_cd
{
	enum e_echo_error	error;			/* Error flag            */
	unsigned char		help	: 1;	/* Help flag            */
	unsigned char		oldpwd	: 1;	/* Oldpwd flag         */
	unsigned char		home	: 1;	/* Pwd flag           */
};

#endif /* _BUILTIN_H */