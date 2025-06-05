/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dependencies.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:28:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/05 14:34:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEPENDENCIES_H
# define DEPENDENCIES_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <stdio.h>		// printf, perror
# include <stdlib.h>	// malloc, free, exit, getenv
# include <unistd.h>	// write, access, read, close, fork, pipe, dup, dup2,
						//	isatty, ttyname, ttyslot
# include <fcntl.h>		// open
# include <sys/types.h>	// wait, waitpid, wait3, wait4, stat, lstat, fstat,
						//	opendir
# include <sys/wait.h>	// wait, waitpid, wait3, wait4
# include <signal.h>	// signal, sigaction, sigemptyset, sigaddset, kill
# include <string.h>	// strerror
# include <dirent.h>	// opendir, readdir, closedir
# include <sys/ioctl.h>	// ioctl
# include <termios.h>	// tcsetattr, tcgetattr
# include <termcap.h>	// tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <sys/stat.h>	// stat, lstat, fstat
# include <errno.h>		// errno

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
	//...

#endif /* DEPENDENCIES_H */