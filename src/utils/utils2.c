/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:04:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/02 11:31:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header
/* -----| Internals |----- */
#include "utils.h"

/* -----| Modules  |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((used)) int	ft_atoi(
	const char *restrict str
)
{
	register int	result;
	register int	sign;

	if (__builtin_expect(!str, unexpected))
		return (0);
	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		++str;
	}
	return (result * sign);
}

/**
 * @brief	Concatenates two path with a '/' in between.
 * 
 * @param	char	*path1 The first string.
 * @param	char	*path2 The second string.
 * @param	int		size The size of the second string to concatenate.
 * 
 * @return	return the concatenated string.
 * @retval		NULL if the memory allocation fails.
 * @retval		result if the concatenation is successful.
 * 
 * @version 1.2
 */
__attribute__((cold)) char	*path_join(
	const char *const restrict path1,
	const char *const restrict path2,
	const int size
)
{
	const int		len_result = ft_strlen(path1) + ft_strlen(path2) + 1;
	char			*result;
	register int	i;
	register int	j;

	result = mm_alloc((len_result + 1) * sizeof(char));
	if (_UNLIKELY(!result))
		return (perror("path_join(): mm_alloc() failed\n"), NULL);
	i = -1;
	while (path1[++i])
		result[i] = path1[i];
	result[i++] = '/';
	j = 0;
	while (path2[j] && j < size)
	{
		result[i + j] = path2[j];
		++j;
	}
	result[i + j] = '\0';
	return (result);
}

/** */
char *ft_strchr(
	const char *const restrict str,
	const char *const restrict target
)
{
	register int	i;
	register int	j;

	if (_UNLIKELY(!str || !target))
		return (NULL);
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (target[++j])
		{
			if (str[i + j] != target[j])
				break ;
		}
		if (!target[j])
			return ((char *)(str + i));
	}
	return (NULL);
}

#pragma endregion Fonctions