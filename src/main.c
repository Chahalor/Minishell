/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:44:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 10:41:13 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Systems   |----- */
#include "allowed.h"

/* -----| Internals |----- */
	//...

/* -----| Modules   |----- */
#include "args.h"
#include "signals.h"
#include "mmanager.h"
#include "read_line.h"
#include "parser.h"
#include "exec.h"
#include "builtin.h"
#include "env.h"
#include "utils.h"

volatile sig_atomic_t	g_last_signal = 0;	/* Global signal variable */

static inline int	_single_command(
	const t_args *const args
)
{
	t_exec_data	*data;
	int			i;
	int			exit_code;

	i = 0;
	while (i < args->nb_cmds)
	{
		data = parser(args->command[i]);
		if (_UNLIKELY(!data))
			return (EXIT_FAILURE);
		exit_code = full_exec(data, env_getall(1));
		i++;
	}
	return (exit_code);
}

/** */
__attribute__((cold, unused))
static inline int	init_all(
	int argc,
	const char **argv,
	const char **envp
)
{
	int				__error;
	const t_args	_args = args_parser(argc, argv);

	if (_UNLIKELY(_args.error))
		return (_args.error);
	__error = 0;
	__error += init_signal();
	__error += env_init(envp);
	if (_UNLIKELY(_args.cmd))
		exit_program(_single_command(&_args), NULL);
	__error += rl_load_history(env_find("HISTORY_PATH"));
	return (__error);
}

__attribute__((always_inline, used))
static inline int	_prompt(
	char *prompt
)
{
	const char	*_prompt = env_expand(prompt);
	char		*line;
	t_exec_data	*data;

	line = read_line(_prompt);
	mm_free((void *)_prompt);
	if (__builtin_expect(!line, unexpected))
		return (1);
	else if (line[0] == '\04')
		return (mm_free(line), 0);
	else if (_LIKELY(line != NULL))
	{
		data = parser(line);
		rl_add_history(line);
		if (_LIKELY(data != NULL))
			full_exec(data, env_getall(1));
	}
	return (mm_free(line), 1);
}

/**
 * @authors nduvoid rcreuzea
 */
int	main(int argc, const char **argv, const char **envp)
{
	int	running;

	if (_UNLIKELY(init_all(argc, argv, envp)))
		exit_program(1, NULL);
	running = 1;
	while (running)
	{
		running = _prompt(env_find("PS1"));
	}
	exit_program(0, DEFAULT_EXIT_MESSAGE);
}
