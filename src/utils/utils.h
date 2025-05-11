/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:03:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/11 15:28:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <stdlib.h>
# include <unistd.h>

/* -----| Globals   |----- */
# include "config.h"

/* -----| Internals |----- */
	//...

/* -----| Modules  |----- */
# include "mmanager.h"

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

extern int		ft_strlen(
			const char *restrict str
			);

extern char	*ft_strdup(
			const char *restrict str
			);

extern void	*memdup(
			const void *restrict src,
			size_t size
			);

#endif /* UTILS_H */