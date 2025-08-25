/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _builtin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:15:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/25 12:27:01 by nduvoid          ###   ########.fr       */
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

enum e_builtin_error
{
	builtin_error_none = 0,				/* No error                          */
	builtin_error_too_many_args = 1,	/* Too many arguments error         */
	builtin_error_no_such_file = 2,		/* No such file or directory error */
	builtin_error_not_a_directory = 3,	/* Not a directory error          */
	builtin_error_not_numeric = 4,		/* Not a numeric argument error  */
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
	int				start;			/* Start for the echo      */
	unsigned char	nl		: 1;	/* Newline flag           */
	unsigned char	help	: 1;	/* Help flag             */
};

struct s_args_cd
{
	enum e_builtin_error	error;			/* Error flag            */
	unsigned char			help	: 1;	/* Help flag            */
	unsigned char			oldpwd	: 1;	/* Oldpwd flag         */
	unsigned char			home	: 1;	/* Pwd flag           */
};

struct s_args_exit
{
	unsigned int	exit_code	: 16;	/* Exit code               */
	char			error;				/* Error flag             */
	unsigned char	help		: 1;	/* Help flag             */
};

struct s_args_export
{
	int	help;	/**/
	int	error;	/**/
};

#endif /* _BUILTIN_H */