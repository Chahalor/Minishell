/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:51:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/29 15:00:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_ft_printf.h"

/* -----| Modules   |----- */
#include "ft_printf.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Count the number of characters in a NULL terminated string
 * 
 * @param	s	Pointer to the string
 * 
 * @return	Number of characters in the string
 * 
 * @note	returns 0 if s is NULL
*/
__attribute__((always_inline, used)) inline int	printf_strlen(
	const char *const restrict s
)
{
	register int	i;

	if (__builtin_expect(!s, unexpected))
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * @brief	Fills the first n bytes of the memory area pointed to by s with
 * zeros
 * 
 * @param	s	Pointer to the memory area
 * @param	n	Number of bytes to fill
 * 
 * @return	Void
*/
__attribute__((always_inline, used)) inline void	ft_bzero(
	const void *const restrict s,
	register const int n
)
{
	register int	i;

	if (__builtin_expect(!s, unexpected))
		return ;
	i = -1;
	while (++i < n)
		((char *)s)[i] = 0;
}

/**
 * @brief	Initializes the t_print structure
 * 
 * @param	buffer	Pointer to the buffer
 * @param	fd		File descriptor to write to
 * @param	buffer_len	Length of the buffer
 * 
 * @return	Initialized t_print structure
*/
__attribute__((always_inline, used)) inline t_print	_init_print(
	void *buffer,
	int fd,
	int buffer_len
)
{
	return ((t_print){
		.buffer = buffer,
		.buffer_len = buffer_len,
		.buff_pos = 0,
		.nb_char = 0,
		.fd = fd,
		.add = _add
	});
}

__attribute__((always_inline, used)) inline t_print	_init_raw_print(
	void *buffer,
	int fd,
	int buffer_len
)
{
	return ((t_print){
		.buffer = buffer,
		.buffer_len = buffer_len,
		.buff_pos = 0,
		.nb_char = 0,
		.fd = fd,
		.add = _raw_add
	});
}

#pragma endregion Fonctions