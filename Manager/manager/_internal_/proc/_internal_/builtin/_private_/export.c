/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/28 16:47:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "builtin_.h"
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

/* -----| Modules   |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

static void	_help(void)
{
	_manager()->interface.printf(
		"Usage: export [options] [name=value]\n"
		"Options:\n"
		"  -h, --help                display this help and exit\n"
	);
}

static inline char	*_get_var(
	const char *restrict const str,
)
{
	const t_mem *const	mem = (const t_mem *const)&_manager()->mem;
	register int		i;
	char				*var;

	i = -1;
	while (str[++i] && str[i] != ' ')
		;
	mem->alloc((unsigned char [1]{mem_alloc}), (void **)&var, i + 1);
	if (unexpect(!var))
		return (NULL);
	mem->copy((unsigned char [1]{mem_copy}), var, str, i);
	var[i] = '\0';
	return (var);
}

static inline char	**_split(
	char *restrict const str,
	const char delim,
	register int i
)
{
	const t_mem *const	_mem = (const t_mem *const)&_manager()->mem;
	int					len;
	char				*splited[2];

	len = 0;
	while (str[++i] && str[i] != delim)
		++len;
	if (unexpect(i++ == 0))
		return (NULL);
	_mem->alloc((unsigned char [1]{mem_alloc}), (void **)&splited[0], len + 1);
	if (unexpect(!splited[0]))
		return (NULL);
	_mem->copy((unsigned char [1]{mem_copy}), splited[0], str, len);
	len = 0;
	while (str[i] && str[i] != ' ')
		++len;
	if (unexpect(len == 0))
		return (_mem->free((unsigned char [1]{mem_free}), splited[0]), NULL);
	_mem->alloc((unsigned char [1]{mem_alloc}), (void **)&splited[1], len + 1);
	if (unexpect(!splited[1]))
		return (_mem->free((unsigned char [1]{mem_free}), splited[0]), NULL);
	_mem->copy((unsigned char [1]{mem_copy}), splited[1], str + i, len);
	splited[1][len] = '\0';
	return (splited);
}

static inline struct s_args_export _parse(
	const char **args
)
{
	register int	i;
	char			**splited;

	i = 0;
	while (args[++i])
	{
		if (unexpect(_manager()->mem.compare("--help", args[i],
			(unsigned int [1]){7}) || _manager()->mem.compare("-h", args[i],
			(unsigned int [1]){3})))
			return ((struct s_args_export){.help = 1});
		splited = _split((char *)args[i], '=', -1);
		if (unexpect(!splited))
			return ((struct s_args_export){0, .error = EINVAL});
		else
		{
			_manager()->env.set(splited[0], splited[1]);
			_manager()->mem.free((unsigned char [1]{mem_free}), splited[0]);
			_manager()->mem.free((unsigned char [1]{mem_free}), splited[1]);
		}
	}
	return ((struct s_args_export){0});
}

/** */
__attribute__((used)) char	bltin_export(
	const char **args,
	const int fd_in,
	const int fd_out
)
{
	const struct s_args_export	args_env = _parse(args);

	if (unexpect(args.help))
	{
		_help();
		return (EXIT_FAILURE);
	}
	else if (args.error)
	{
		_manager()->interface.fprintf(2, "env: %s\n", strerror(args.error));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

#pragma endregion Fonctions