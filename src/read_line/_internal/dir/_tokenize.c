/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tokenize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/03 10:34:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"
#include <dirent.h>
#include <sys/stat.h>

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((always_inline, used)) static inline char	_is_file(
	const char *const restrict path
)
{
	const char		*p = path;
	char			has_slash;
	char			has_valid_char;
	char			c;

	if (_UNLIKELY(!path || !*path))
		return (0);
	has_slash = false;
	has_valid_char = false;
	while (*p)
	{
		c = *p;
		if (c == '/' || c == '\\')
			has_slash = true;
		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9') || c == '.' || c == '-'
			|| c == '_' || c == '~')
			has_valid_char = true;
		else
			return (false);
		++p;
	}
	return (has_valid_char && (has_slash || path[0] == '.'));
}

/**
 * @brief	Check if the word is a directory.
 *
 * @param	char	*word The word to check.
 * 
 * @return	if the word is a directory
 * @retval		1 if the word is a directory
 * @retval		0 if the word is not a directory
 * 
 * @version 2.0
*/
int	is_dir(
	const char *const restrict path
)
{
	struct stat	s;

	if (_UNLIKELY(!path || !*path))
		return (0);
	else if (stat(path, &s) == 0)
		return (S_ISDIR(s.st_mode));
	else
		return (0);
}

/**
 * @brief	Check if the word is a directory.
 *
 * @param	char	*word The word to check.
 * 
 * @return	if the word is a directory
 * @retval		1 if the word is a directory
 * @retval		0 if the word is not a directory
 * 
 * @version 2.0
*/
int	is_file(
	const char *const restrict path
)
{
	struct stat	s;

	if (_UNLIKELY(!path || !*path))
		return (0);
	else if (stat(path, &s) == 0)
		return (S_ISREG(s.st_mode));
	else
		return (0);
}

/** */
int	tokenize(
	const char *const restrict word
)
{
	if (_UNLIKELY(!word || !*word))
		return (unknown);
	else if (_is_file(word))
	{
		if (is_dir(word))
			return (token_path_dir);
		else if (is_file(word))
			return (token_path_file);
		else
			return (token_path);
	}
	else
		return (token_cmd);
}

#pragma endregion Fonctions