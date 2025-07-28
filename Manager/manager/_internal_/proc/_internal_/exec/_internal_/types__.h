/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:02:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/24 09:02:20 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES___H
# define TYPES___H
# undef TYPES___H

# pragma once

/* ************************************************************************** */
/*                                 Macros                                     */
/* ************************************************************************** */

# define HD_ALLOC_SIZE	32	/* Size of the buffer for heredoc input */

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_exec_data	t_exec_data;	/* Execution data structure      */
typedef struct s_heredoc	t_heredoc;		/* Heredoc data structure       */
typedef struct s_infile		t_infile;		/* Input file data structure   */
typedef struct s_outfile	t_outfile;		/* Output file data structure */

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_heredoc
{
	char	**storage;	/* Array of strings to store the lines */
	int		fd;			/* File descriptor for the heredoc    */
	int		nb_lines;	/* Number of lines read              */
};

struct s_infile
{
	int		fd;			/* File descriptor for the input file */
	char	*file;		/* Name of the input file            */
};

struct s_outfile
{
	int		fd;			/* File descriptor for the output file */
	char	*file;		/* Name of the output file            */
};

#endif /* !TYPES___H */