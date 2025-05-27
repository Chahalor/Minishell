/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:51:43 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/27 10:53:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "utils.h"

/* -----| Modules   |----- */
#include "ft_printf.h"

#pragma endregion Header
#pragma region Fonctions

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
	char **tab
)
{
	register int	i;

	if (__builtin_expect(!tab || !*tab, 0))
		return ;
	i = -1;
	while (tab[++i])
		mm_free(tab[i]);
	mm_free(tab[i]);
	mm_free(tab);
}

static inline size_t	get_buffer(
	const char *const s,
	const char c
)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = -1;
	while (s[++i])
		nb += (s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0'));
	return (nb);
}

/** */
__attribute__((always_inline, used)) static inline void	fill_tab(
	char *dest,
	const char *s,
	const char c
)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		++i;
	}
	dest[i] = '\0';
}

static inline void	alloc_tab(
	char **r,
	const char *s,
	const char c
)
{
	size_t	count;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while (s[i + count] && s[i + count] != c)
			++count;
		if (count > 0)
		{
			r[j] = mm_alloc(sizeof(char) * (count + 1));
			if (_UNLIKELY(!r[j]))
				return (free_tab(r));
			fill_tab(r[j], (s + i), c);
			++j;
			i = i + count;
			r[j] = NULL;
		}
		else
			i++;
	}
	r[j] = NULL;
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
char	**ft_split(char const *s, char c)
{
	char	**r;

	r = (char **)mm_alloc(sizeof(char *) * (get_buffer(s, c) + 1));
	if (_UNLIKELY(!r))
		return (NULL);
	else
	{
		alloc_tab(r, s, c);
		if (_UNLIKELY(!r))
			return (NULL);
		else
			return (r);
	}
}

#pragma endregion Fonctions