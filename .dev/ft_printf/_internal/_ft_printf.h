/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:40:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/16 16:46:19 by nduvoid          ###   ########.fr       */
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
	
/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
# include "ft_printf.h"

/* -----| Modules  |----- */
	//...

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define PRINTF_BUFFER_SIZE		4096	/* */
# define PRINTF_HEX_BUFFER_SIZE	32		/* */
# define PRINTF_DEC_BUFFER_SIZE	10		/* */

# define LHEX_CHAR	"0123456789abcdef"	/* */
# define UHEX_CHAR	"0123456789ABCDEF"	/* */

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
	FALSE,	/* */
	TRUE	/* */
};

# endif	 /* E_BOOL */

# ifndef E_EXPECT
#  define E_EXPECT

enum e_expect
{
	unexpected = 0,	/* */
	expected = 1	/* */
};

# endif	 /* E_EXPECT */

/* ************************************************************************** */
/*                                 struct                                     */
/* ************************************************************************** */

struct s_print
{
	char	buffer[PRINTF_BUFFER_SIZE];	/**/
	int		buffer_len;					/**/
	int		nb_char;					/**/
	int		fd;							/**/
	char	error;						/**/
	int		(*add)(t_print *, const char c);	/* */
};

struct s_sprint
{
	char	*buffer;					/**/
	int		nb_char;					/**/
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

/* -----| utils    |----- */

extern int	ft_strlen(
				const char *const restrict str
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
					long nb,
					t_print *const restrict print,
					const char *const restrict base
					);
	
/* -----| fprintf |----- */
	//...

/* -----| sprintf |----- */
	//...

#endif /* _FT_PRINTF_H */