/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:21:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/05 14:35:29 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOWED_H
# define ALLOWED_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include "dependencies.h"
/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
	//...

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

int				printf(const char *format, ...);
void			*malloc(size_t size);
void			free(void *ptr);
ssize_t			write(int fd, const void *buf, size_t count);
int				access(const char *pathname, int mode);
int				open(const char *pathname, int flags, ...);
ssize_t			read(int fd, void *buf, size_t count);
int				close(int fd);
pid_t			fork(void);
pid_t			wait(int *wstatus);
pid_t			waitpid(pid_t pid, int *wstatus, int options);
pid_t			wait3(int *wstatus, int options, struct rusage *rusage);
pid_t			wait4(pid_t pid, int *wstatus, int options,
					struct rusage *rusage);
void			(*signal(int sig, void (*handler)(int)))(int);
int				sigaction(int signum, const struct sigaction *act,
					struct sigaction *oldact);
int				sigemptyset(sigset_t *set);
int				sigaddset(sigset_t *set, int signum);
int				kill(pid_t pid, int sig);
void			exit(int status);
char			*getcwd(char *buf, size_t size);
int				chdir(const char *path);
int				stat(const char *pathname, struct stat *statbuf);
int				lstat(const char *pathname, struct stat *statbuf);
int				fstat(int fd, struct stat *statbuf);
int				unlink(const char *pathname);
int				execve(const char *pathname, char *const argv[],
					char *const envp[]);
int				dup(int oldfd);
int				dup2(int oldfd, int newfd);
int				pipe(int pipefd[2]);
DIR				*opendir(const char *name);
struct dirent	*readdir(DIR *dirp);
int				closedir(DIR *dirp);
char			*strerror(int errnum);
void			perror(const char *s);
int				isatty(int fd);
char			*ttyname(int fd);
int				ttyslot(void);
int				ioctl(int fd, unsigned long request, ...);
char			*getenv(const char *name);
int				tcsetattr(int fd, int optional_actions,
					const struct termios *termios_p);
int				tcgetattr(int fd, struct termios *termios_p);
int				tgetent(char *bp, const char *name);
int				tgetflag(const char *id);
int				tgetnum(const char *id);
char			*tgetstr(const char *id, char **area);
char			*tgoto(const char *cap, int col, int row);
int				tputs(const char *str, int affcnt, int (*putc)(int));

#endif /* ALLOWED_H */