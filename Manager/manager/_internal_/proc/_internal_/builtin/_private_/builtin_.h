/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:03:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/24 10:13:27 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN__H
# define BUILTIN__H

# pragma once

#include "../_internal_/types__.h"
#include "formating.h"
#include <stdlib.h>


// different builtin functions

char		bltin_cd(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_echo(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_env(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_export(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_pwd(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_unset(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_exit(
				const char **args,
				const int fd_in,
				const int fd_out
				);

char		bltin_history(
				const char **args,
				const int fd_in,
				const int fd_out
				);

#endif /* !BUILTIN__H */