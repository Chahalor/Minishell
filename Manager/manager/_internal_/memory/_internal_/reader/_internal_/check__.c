/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:48:58 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK___C
# define CHECK___C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char __reader_check(\
	const char *restrict const path__,
	const int mode__
)	// v.1. >>> tag: def->_reader_check
{
	struct stat	stat__;

	if (unexpect(!path__))
		return (reader_invalid_target_);
	else if (unexpect(access(path__, mode__) != no_error))
		return (reader_failed_access_);
	else if (unexpect(stat(path__, &stat__) < 0))
		return (reader_invalid_permissions_);
	else if (S_ISREG(stat__.st_mode))
		return (reader_file_ + !access(path__, X_OK));
	else if (S_ISLNK(stat__.st_mode))
		return (reader_link_);
	else if (S_ISDIR(stat__.st_mode))
		return (reader_directory_);
	return (reader_invalid_target_);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char __reader_check_presence(\
	t_mem *restrict const mem__,
	const char *restrict const path__,
	const char *restrict const name__,
	char **buffer__
)	// v.1. >>> tag: def->_reader_check_presence
{
	char			*full_path__;
	unsigned int	size__;

	size__ = mem__->size((unsigned char [1]){mem_len}, name__, 0);
	if (unexpect(\
			(mem__->write((unsigned char [1]){mem_link}, path__, \
						name__, size__) \
			!= no_error)
			|| (mem__->copy((unsigned char [1]){mem_replace}, path__, \
							&full_path__, 0) \
			!= no_error)))
		return (error);
	if (unexpect(_reader_check(full_path__, F_OK | X_OK) == reader_bin_))
		return ((void)(*buffer__ = full_path__), TRUE);
	return (mem__->clean((unsigned char [1]){mem_ptr}, FALSE, full_path, 0));
}

#endif