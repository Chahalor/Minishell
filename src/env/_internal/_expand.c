/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _expand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:36:59 by nduvoid           #+#    #+#             */
/*   Updated: 2025/08/25 09:34:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "_env.h"
 #include "ft_printf.h"

static inline int	__is_delim(
	const char c
)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r'
		|| c == '$' || c == '=' || c == '+' || c == '-'
		|| c == '/' || c == '\\' || c == '.' || c == ','
		|| c == ';' || c == ':' || c == '!' || c == '?'
		|| c == '\"' || c == '\'' || c == '`'
		|| c == '(' || c == ')' || c == '[' || c == ']'
		|| c == '{' || c == '}' || c == '|'
	);
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
	while (_str[++__i] && !__is_delim(_str[__i]))
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
	char			*_new;

	ft_fprintf(2, "str1: '%s', str2: '%s'\n", str1->value, str2);
	if (__sum > str1->allocated)
	{
		_new = mm_alloc(str1->allocated + ENV_ALLOC_SIZE);
		if (_UNLIKELY(!_new))
			return (0);
		ft_memcpy(_new, str1->value, str1->allocated);
		mm_free(str1->value);
		str1->value = _new;
		str1->allocated += ENV_ALLOC_SIZE;
	}
	ft_memcpy(
		&str1->value[__sum - ft_strlen(str2) - 1],
		str2,
		ft_strlen(str2) + 1
	);
	return (1);
}

void	*_env_expand(
	t_env *env,
	void **data
)
{
	const char *const	restrict	_str = *(char **)data;
	register int					_i;
	char							*tmp;
	t_env_str						result;

	(void)env;
	result.value = mm_alloc(ENV_ALLOC_SIZE);
	if (_UNLIKELY(!result.value))
		return (NULL);
	result.allocated = ENV_ALLOC_SIZE;
	_i = -1;
	while (_str[++_i])
	{
		if (_str[_i] == '$' && _str[_i + 1] && _str[_i + 1] != ' ')
		{
			tmp = __sub_str(&_str[_i + 1]);
			ft_fprintf(2, "_sub: '%s'\n", tmp);
			__env_join(&result, env_manager(e_env_find, tmp));
			ft_fprintf(2, "_join: '%s'\n", result.value);
			mm_free(tmp);
			_i += ft_strlen(tmp);
		}
		else
			__env_join(&result, (char[]){_str[_i], '\0'});
	}
	return (result.value);
}
