/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:47:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/11 17:00:42 by nduvoid          ###   ########.fr       */
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

# ifndef DEBUG
#  define DEBUG		0				/* 0: debug disabled, 1: debug enabled */
# endif	/* DEBUG */

# define ENABLE_RL	1				/* 0: disable read_line, 1: enable read_line */

#endif /* CONFIG_H */