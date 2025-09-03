/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/03 08:40:19 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_lexer.h"

/* -----| Modules   |----- */
#include "lexer.h"

#pragma endregion Header
#pragma region Fonctions

#if DEBUG == 1

__attribute_maybe_unused__
static inline const char	*show_type(
	const int type
)
{
	static const char	*messages[15] = {\
		[TOKEN_CMD] = BLUE "CMD" RESET, \
		[TOKEN_PIPE] = CYAN "PIPE" RESET, \
		[TOKEN_QUOTE] = YELLOW "QUOTE" RESET, \
		[TOKEN_DQUOTE] = GREEN "DQUOTE" RESET, \
		[TOKEN_GREATER] = RED "GREATER" RESET, \
		[TOKEN_LESS] = MAGENTA "LESS" RESET, \
		[TOKEN_DGREATER] = BLUE "DGREATER" RESET, \
		[TOKEN_DLESS] = BLUE "DLESS" RESET, \
		[TOKEN_WORD] = WHITE "WORD" RESET, \
		[PARSER_ERR_NONE] = GREEN "NO ERROR" RESET, \
		[PARSER_ERR_MISSING_QUOTE] = RED "MISSING QUOTE" RESET, \
		[PARSER_ERR_UNEXPECTED_TOKEN] = RED "UNEXPECTED TOKEN" RESET, \
		[PARSER_ERR_BROKEN_PIPE] = RED "BROKEN PIPE" RESET, \
		[PARSER_ERR_INVALID_REDIRECTION] = RED "INVALID REDIRECTION" RESET, \
		[PARSER_ERR_MEMORY_ALLOCATION] = RED "MEMORY ALLOCATION" RESET \
	};

	return (messages[type % (PARSER_ERR_MEMORY_ALLOCATION + 1)]);
}

#endif

void	print_tokens(
	t_token **tokens,
	const int count
)
#if DEBUG == 1

{
	register int	i;

	if (_UNLIKELY(!tokens || count < 1))
	{
		printf("No tokens to display\n");
		return ;
	}
	i = -1;
	while (++i < count)
		printf("(%d)[%s] type=%s (%d) size=%d\n", i, tokens[i]->value,
			show_type(tokens[i]->type), tokens[i]->type, tokens[i]->size);
}
#else

{
	(void)tokens;
	(void)count;
}

#endif

void	print_exec(
	const t_exec_data *const exec
)
#if DEBUG == 1

{
	t_exec_data		*current;
	register int	j;

	if (_UNLIKELY(!exec))
		return ((void)printf("No execution data to display\n"));
	current = (t_exec_data *)exec;
	while (current)
	{
		printf("Command: '%s' (%p)\n", current->cmd, current);
		printf("Arguments:\n");
		if (current->args)
		{
			j = -1;
			while (current->args[++j])
				printf("  arg[%d]: '%s'\n", j, current->args[j]);
			printf("  arg[%d]: %p\n", j, current->args[j]);
		}
		else
			printf("  No arguments\n");
		printf("Input FD: %d\n", current->fd_in);
		printf("Output FD: %d\n", current->fd_out);
		printf("Status: %d\n", current->status);
		current = current->pipe;
	}
}

#else
{
	(void)exec;
}

#endif

/**
 * @brief	Lexer function that parses a command line and builds an execution
 * 				data structure from it.
 * 
 * @param	line	The command line to parse.
 * 
 * @return	Returns a pointer to the execution data structure.
 * @retval		NULL if the command line is invalid or if an error occurs.
 * @retval		data if the command line is valid and the execution data
 * 					structure is built successfully.
*/
__attribute__((deprecated)) t_exec_data	*lexer(
	const char *const restrict line
)
{
	t_exec_data	*data;
	int			count;
	t_token		**tokens;

	count = 0;
	if (_UNLIKELY(!line || !*line))
		return (NULL);
	tokens = tokenize_line(line, &count);
	print_tokens(tokens, count);
	data = token_to_exec(tokens);
	return (data);
}

#pragma endregion Fonctions
