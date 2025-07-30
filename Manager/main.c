/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 10:57:49 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/30 11:09:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manager.h"

static void	_free(
	char **str
)
{
	_manager()->mem.clean((unsigned char [1]{mem_free}), 0, *str, 0);
}

static inline int	_run(
	const int argc,
	const char *const argv[],
	const char *const envp[]
)
{
	char	*prompt;
	char	*line;

	while (true)
	{
		__attribute__((cleanup(_free))) prompt = _manager()->env.expand(_manager()->env.find("PS1"));
		if (unexpect(!prompt))
			prompt = _manager()->env.find(DEFAULT_PROMPT);
		__attribute__((cleanup(_free))) line = _manager()->interface.interaction.read_line(prompt);
		if (unexpect(!line))
			return (EXIT_FAILURE);
		else if (line[0] == '\04')
			return (EXIT_SUCCESS);
		else
			run = _manager()->exec(line, argc, argv, envp);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, const char *argv[], const char *envp[])
{
	if (unexpect(_manager()->init(argc, argv, envp) < 0))
		return (EXIT_FAILURE);
	_run(argc, argv, envp);
	return (_manager()->exit(EXIT_SUCCESS));
}