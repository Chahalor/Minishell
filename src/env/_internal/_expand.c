/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _expand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:36:59 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/22 16:08:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "_env.h"

static inline int	is_whitespace(
	const char c
)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static inline char	*__sub_str(
	const char *const restrict _str
)
{
	register int	__i;
	register int	__size;
	char			*_result;

	__i = -1;
	__size = 0;
	while (_str[++__i] && !is_whitespace(_str[__i]))
		++__size;
	_result = mm_alloc(__size + 1);
	if (_UNLIKELY(!_result))
		return (NULL);
	__i = -1;
	while (++__i < __size)
		_result[__i] = _str[__i];
	_result[__i] = '\0';
	return (_result);
}

static inline char	*__env_join(
	char *str1,
	const char *const restrict str2
)
{
	const int	__sum = ft_strlen(str1) + ft_strlen(str2) + 1;
	char		*_result;

	_result = mm_alloc(__sum);
	if (_UNLIKELY(!_result))
		return (str1);
	ft_memcpy(_result, str1, ft_strlen(str1));
	ft_memcpy(_result + ft_strlen(str1), str2, ft_strlen(str2));
	_result[__sum - 1] = '\0';
	mm_free(str1);
	return (_result);
}

void	*_env_expand(
	t_env *env,
	void **data
)
{
	const char *const	restrict	_str = *(char **)data;
	register int					_i;
	char							*tmp;
	char							*result;

	(void)env;
	result = mm_alloc(ENV_ALLOC_SIZE);
	if (_UNLIKELY(!result))
		return (NULL);
	_i = -1;
	while (_str[++_i])
	{
		if (_str[_i] == '$' && _str[_i + 1] && _str[_i + 1] != ' ')
		{
			tmp = __sub_str(&_str[_i + 1]);
			result = __env_join(result, env_manager(e_env_find, tmp));
			mm_free(tmp);
		}
		else
			result = __env_join(result, (char[]){_str[_i], '\0'});
	}
	return (result);
}
