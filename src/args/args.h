/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:04:47 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 09:55:39 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
	//...

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
	//...

/* -----| Modules   |----- */
	//...

/* ************************************************************************** */
/*                                 Typedef                                    */
/* ************************************************************************** */

typedef struct s_args	t_args;	/* Structure to hold parsed arguments */

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

struct s_args
{
	int				argc;			/* Number of arguments         */
	char			**argv;			/* Array of argument strings  */
	char			**command;		/* Command string            */
	int				nb_cmds;		/* Nb Command               */
	unsigned char	error	: 1;	/* Error flag              */
	unsigned char	cmd		: 1;	/* Command flag           */
	unsigned char	help	: 1;	/* Help flag             */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

t_args	args_parser(
			const int argc,
			const char **argv
			);

#endif /* ARGS_H */