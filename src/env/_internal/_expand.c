/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _expand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:36:59 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/03 11:06:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "_env.h"

static inline int	__is_delim(
	const char c
)
{
	if (!((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9')
			|| c == '_' || c == '?'))
		return (0);
	return (1);
}

static inline int	__is_var(
	const char *_str
)
{
	return ((*_str == '$' && _str[1] && _str[1] != ' ') || *_str == '~');
}

static inline char	*__sub_str(
	const char *const restrict _str
)
{
	register int	__i;
	register int	__size;
	char			*_result;

	if (_str[-1] == '~')
		return (memdup("~", 2));
	__i = -1;
	__size = 0;
	while (_str[++__i] && __is_delim(_str[__i]))
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

static inline char	__env_join(
	t_env_str *str1,
	const char *const restrict str2
)
{
	const int		__sum = ft_strlen(str1->value) + ft_strlen(str2) + 1;
	int				__size;
	char			*_new;

	if (__sum >= str1->allocated)
	{
		__size = __sum + ft_strlen(str2) + ENV_ALLOC_SIZE;
		_new = mm_alloc(str1->allocated + __size);
		if (_UNLIKELY(!_new))
			return (0);
		ft_memcpy(_new, str1->value, str1->allocated);
		mm_free(str1->value);
		str1->value = _new;
		str1->allocated += ft_strlen(str2) + ENV_ALLOC_SIZE;
	}
	ft_memcpy(
		&str1->value[__sum - ft_strlen(str2) - 1],
		str2,
		ft_strlen(str2) + 1
		);
	return (1);
}

void	*_env_expand(
	void *data
)
{
	const char *const	restrict	_str = (char *)data;
	t_find_access					access;
	register int					_i;
	char							*tmp;
	t_env_str						result;

	result.value = mm_alloc(ENV_ALLOC_SIZE);
	if (_UNLIKELY(!result.value || !data))
		return (mm_free(result.value), NULL);
	result.allocated = ENV_ALLOC_SIZE;
	_i = -1;
	while (_str[++_i])
	{
		if (__is_var(&_str[_i]))
		{
			tmp = __sub_str(&_str[_i + 1]);
			access = (t_find_access){tmp, 0};
			__env_join(&result, env_manager(e_env_find, (void *)&access));
			_i += ft_strlen(tmp) - (_str[_i] == '~');
			mm_free(tmp);
		}
		else if (_str[_i] != '\'' && _str[_i] != '\"')
			__env_join(&result, (char [2]){_str[_i], '\0'});
	}
	return (result.value);
}
