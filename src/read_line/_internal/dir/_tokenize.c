/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tokenize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/02 17:36:58 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline int _has_path_chars(
	const char *const restrict word
)
{
	register int	i;

	i = 0;
	if (word[0] == '~')
		++i;
	while (word[i] && (word[i] == '/' || word[i] == '.'))
		++i;
	return (i > 0);
}


/**
 * @brief	Check if the word is a file.
 *
 * @param	char	*word The word to check.
 * 
 * @return	if the word is a file
 * @retval		1 if the word is a file
 * @retval		0 if the word is not a file
 * 
 * @version 1.0
*/
__attribute__((always_inline, used)) static inline int	_is_file(
	const char *const restrict word
)
{
	
	if (!word || !*word || word[ft_strlen(word) - 1] == '/')
		return (0);
	else
		return( _has_path_chars(word));
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