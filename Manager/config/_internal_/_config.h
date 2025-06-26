/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _config.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/03 14:46:49 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONFIG_H
# define _CONFIG_H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./_default.h"

/* --------- macros --------- */
// TODO: some macro renaming could be needed here.
// Move the sizes inside a enum of the manager as those length shall not be
// reconfigured for usage.
	// ----- user ------ //
# ifndef M_USER_CONF
#  define M_USER_CONF

#  define MAX_USER_NAME_LEN					256					// count the '\0'.
#  define MAX_PATH_LEN						4096				// count the '\0'.
#  define MAX_HOME_PATH_LEN					300					// count the '\0'.
#  define SHELL_HISTORY_PATH				".ghosts_history"
#  define SHELL_HISTORY_PATH_LEN			16					// count the '\0'.
#  define HISTORY_SIZE						1024				// in cmd(s).
#  define READ_SIZE							1024				// in bytes.
#  define TOKEN_BUFFER_SIZE					256					// in bytes.

# endif

#endif