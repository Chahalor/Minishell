/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:47:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/15 13:33:09 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# pragma once

/* ************************************************************************** */
/*                                 Config                                     */
/* ************************************************************************** */

# ifndef VERIONS
#  define VERSION_MAJOR		0		/* major version number   */
#  define VERSION_MINOR		1		/* minor version number  */
#  define VERSION_PATCH		0		/* patch version number */
#  define VERSION_STRING	"0.1.0"	/* version string      */
#  define VERIONS
# endif	/* VERIONS */

# define _LIKELY	__glibc_likely		/* __builtin_expect((cond), 1) */
# define _UNLIKELY	__glibc_unlikely	/* __builtin_expect((cond), 0) */

# ifndef DEBUG
#  define DEBUG		0				/* 0: debug disabled, 1: debug enabled */
# endif	/* DEBUG */

# define ENABLE_RL	1				/* 0: disable read_line, 1: enable it */

# define PS1	"\e[1;34m$USER\e[0m@\e[1;32m$PWD\e[0m[\e[1;32m$?\e[0m]> "
# define PS2	"\e[1;32mheredoc\e[0m> "
# define DEFAULT_HEREDOC		"heredoc> "			/* default heredoc prompt */
# define SHELL_NAME				"minishell"			/* shell name            */
# define DEFAULT_EXIT_MESSAGE	"Exit 👻"			/* exit message         */

# define DEFAULT_HISTORY_FILE	"~/.minihistory"	/* default file */

# define PARSER_ALLOC_SIZE		16		/* default parser allocation size */
# define _RL_HIST_SIZE			4096	/* Size of the history buffer    */

#endif /* CONFIG_H */