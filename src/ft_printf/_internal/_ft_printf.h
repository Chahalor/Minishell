/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:40:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/24 15:31:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
# include "ft_printf.h"

/* -----| Modules  |----- */
	//...

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define PRINTF_BUFFER_SIZE		4096	/* Max number of char before a print */
# define PRINTF_HEX_BUFFER_SIZE	32		/* Max number of char in an hax number*/
# define PRINTF_DEC_BUFFER_SIZE	10		/* Max number of char in a int       */

# define LHEX_CHAR	"0123456789abcdef"	/* All char to write lower hex  */
# define UHEX_CHAR	"0123456789ABCDEF"	/* All char to write Huper hex */

/* ************************************************************************** */
/*                                 typedefs                                   */
/* ************************************************************************** */

typedef struct s_print	t_print;	/* struct for all printf in fd      */
typedef struct s_sprint	t_sprint;	/* struct for all printf in buffer */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

# ifndef E_BOOL
#  define E_BOOL

enum	e_bool
{
	FALSE,	/* This is false                                 */
	TRUE,	/* this is true (you realy need this comment ?) */
};

# endif	 /* E_BOOL */

# ifndef E_EXPECT
#  define E_EXPECT

enum e_expect
{
	unexpected = 0,	/* We expect this to be false */
	expected = 1	/* We expect this to be true */
};

# endif	 /* E_EXPECT */

/* ************************************************************************** */
/*                                 struct                                     */
/* ************************************************************************** */

struct s_print
{
	char	*buffer;							/* The buffer to add char in  */
	int		buffer_len;							/* The buffer max size        */
	int		buff_pos;							/* The index of the next add  */
	int		nb_char;							/* The number of char writed  */
	int		fd;									/* The fd to write            */
	char	error;								/* The error                  */
	int		(*add)(t_print *, const char c);	/* The function to add a char */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

/* -----| utils    |----- */

extern void		ft_bzero(
					const void *const restrict s,
					register const int n
					);

extern int		printf_strlen(
					const char *const restrict str
					);

extern t_print	_init_print(
					void *buffer,
					int fd,
					int buffer_len
					);

int				_add(
					t_print *const restrict print,
					const char c
					);

/* -----| printf  |----- */
int				write_loop(
					const char *s,
					va_list args,
					t_print *const restrict print
					);

int				writestr(
					const char *const restrict s,
					t_print *const restrict print
					);

int				writedec(
					long dec,
					t_print *const restrict print
					);

int				writeptr(
					const void *const restrict ptr,
					t_print *const restrict print
					);

int				writehex(
					unsigned long nb,
					t_print *const restrict print,
					const char *const restrict base
					);

/* -----| fprintf |----- */
	//...

/* -----| sprintf |----- */
	//...

#endif /* _FT_PRINTF_H */