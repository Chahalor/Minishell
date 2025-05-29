/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _signals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:04:36 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/29 14:06:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SIGNALS_H
# define _SIGNALS_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <bits/sigaction.h>

/* -----| Globals   |----- */
# include "config.h"
# include "type.h"

/* -----| Internals |----- */
# include "signal.h"

/* -----| Modules   |----- */
# include "global_manager.h"

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

//...

#endif /* _SIGNALS_H */