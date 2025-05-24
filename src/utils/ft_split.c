/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:51:43 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/24 13:49:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "utils.h"

/* -----| Modules   |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Count the number of words in a string separated by a character. And
 *  allocate memory for the array of strings.
 * 
 * @param	s The string to split.
 * @param	c The character that separates the words.
 * 
 * @return	The allocated array of strings, or NULL if an error occurred.
 * @retval		NULL if an error occurred.
 * @retval		char ** The allocated array of strings.
*/
static inline char	**_allocing(
	const char *const restrict s,
	const char c
)
{
	register int	i;
	int				nb_words;
	char			**tab;

	nb_words = 0;
	i = -1;
	while (s[++i])
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			++nb_words;
	tab = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!tab)
		return (NULL);
	tab[nb_words] = NULL;
	return (tab);
}

/**
 * @brief copy the string from src to dest until n characters or the end of src.
 * 
 * @param	dest The destination string.
 * @param	src The source string.
 * @param	n The number of characters to copy.
 * 
 * @return	The number of characters copied.
*/
static inline int	_copy(
	char *dest,
	const char *src,
	int n
)
{
	register int	i;

	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (i);
}

/**
 * @brief	split a string into an array of strings based on a character
 * 
 * @param	tab The array of strings to fill.
 * @param	s The string to split.
 * @param	c The character that separates the words.
 * 
 * @return	0 on success, -1 on error.
 * @retval		 0 on success.
 * @retval		-1 on error.
*/
static inline int	_split(
	char **tab,
	const char *const restrict s,
	const char c
)
{
	register int	i;
	register int	j;
	int				k;

	i = -1;
	j = +0;
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			k = i;
			while (s[i] && s[i] != c && s[i + 1] != c)
				++i;
			tab[j] = (char *)malloc(sizeof(char) * (i - k + 2));
			if (__builtin_expect(!tab[j], 0))
				return (-1);
			_copy(tab[j++], &s[k], i - k + 1);
			--i;
		}
	}
	return (0);
}

/**
 * @brief	Free the memory allocated for an array of strings.
 * 
 * @param	tab The array of strings to free.
 * 
 * @return Void.
 * 
 * @note	After calling this function, the pointer to the array of strings
 * 			is set to NULL.
*/
__attribute__((cold)) void	free_tab(
	char ***tab
)
{
	register int	i;

	if (__builtin_expect(!tab || !*tab, 0))
		return ;
	i = -1;
	while ((*tab)[++i])
		free((*tab)[i]);
	free(*tab);
	*tab = NULL;
}

/**
 * @brief	Split a string into an array of strings based on a character.
 * 
 * @param	s The string to split.
 * @param	c The character that separates the words.
 * 
 * @return	The allocated array of strings, or NULL if an error occurred.
 * @retval		NULL if an error occurred.
 * @retval		char ** The allocated array of strings.
 * 
 * @version 2.0
*/
char	**ft_split(
	const char *const restrict s,
	const char c
)
{
	char		**tab;

	tab = _allocing(s, c);
	if (__builtin_expect(!tab, 0))
		return (NULL);
	if (__builtin_expect(_split(tab, s, c) < 0, 0))
		return (free_tab(&tab), NULL);
	return (tab);
}

#pragma endregion Fonctions