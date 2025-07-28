/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:40:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/22 10:02:35 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES___H
# define TYPES___H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <errno.h>
# include <string.h>

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
	//...

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define PRINTF_BUFFER_SIZE		4096	/* Max number of char before a print */
# define PRINTF_HEX_BUFFER_SIZE	32		/* Max number of char in an hex number*/
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

//...

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

//...

#endif /* TYPES___H */