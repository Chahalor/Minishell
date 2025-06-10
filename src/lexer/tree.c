/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:10:07 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/10 10:45:14 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_internal/_lexer.h"

/* -----| Modules   |----- */
#include "lexer.h"

#pragma endregion Header
#pragma region Fonctions

// /* prototypes unchanged … */
// t_ast	*ast_cmd_new(char **argv);
// t_ast	*ast_pipe_new(t_ast *lhs, t_ast *rhs);
// int		ast_add_redir(t_ast *cmd, t_redir_type t, char *file);
// void	ast_destroy(t_ast *n);
// void	ast_print(const t_ast *n, int depth);
// t_ast	*parse_pipeline(t_lexer *lxr);
// void	token_free_all(t_token *toks);
// t_token	*tokenize_line(const char *line);

/* --------------------------- implémentation --------------------------- */

static void	*xfree(\
	void *p
)
{
	return (free(p), NULL);
}

t_ast	*ast_cmd_new(\
	char **argv
)
{
	t_ast	*n;

	n = malloc(sizeof(*n));
	if (!n)
		return (NULL);
	n->type = NODE_CMD;
	n->data.cmd.argv = argv;
	n->data.cmd.redirs = NULL;
	return (n);
}

t_ast	*ast_pipe_new(\
	t_ast *l,
	t_ast *r
)
{
	t_ast	*n;

	if (!l || !r)
		return (NULL);
	n = malloc(sizeof(*n));
	if (!n)
		return (NULL);
	n->type = NODE_PIPE;
	n->data.pipe.lhs = l;
	n->data.pipe.rhs = r;
	return (n);
}

static t_redir	*redir_new(\
	t_redir_type t,
	char *f
)
{
	t_redir	*r;

	r = malloc(sizeof(*r));
	if (!r)
		return (NULL);
	r->type = t;
	r->file = f;
	r->next = NULL;
	return (r);
}

int	ast_add_redir(\
	t_ast *cmd,
	t_redir_type t,
	char *f
)
{
	t_redir	**cur;

	if (!cmd || cmd->type != NODE_CMD)
		return (-1);
	cur = &cmd->data.cmd.redirs;
	while (*cur)
		cur = &(*cur)->next;
	*cur = redir_new(t, f);
	return (*cur ? 0 : -1);
}

static void	redir_clear(\
	t_redir *r
)
{
	t_redir	*n;

	while (r)
	{
		n = r->next;
		xfree(r->file);
		free(r);
		r = n;
	}
}

void	ast_destroy(\
	t_ast *n
)
{
	register size_t	i = 0;

	if (!n)
		return ;
	if (n->type == NODE_PIPE)
	{
		ast_destroy(n->data.pipe.lhs);
		ast_destroy(n->data.pipe.rhs);
	}
	else
	{
		if (n->data.cmd.argv)
		{
			while (n->data.cmd.argv[i])
				free(n->data.cmd.argv[i++]);
			free(n->data.cmd.argv);
		}
		redir_clear(n->data.cmd.redirs);
	}
	free(n);
}

void	ast_print(\
	const t_ast *n,
	int d
)
{
	t_redir			*r;
	size_t			i;

	if (!n)
		return ;
	i = 0;
	while (i < (size_t)d)
	{
		printf("  ");
		++i;
	}
	if (n->type == NODE_PIPE)
	{
		puts(BLUE "PIPE" RESET);
		ast_print(n->data.pipe.lhs, d + 1);
		ast_print(n->data.pipe.rhs, d + 1);
	}
	else
	{
		printf(YELLOW "CMD:" RESET);
		i = 0;
		while (n->data.cmd.argv && n->data.cmd.argv[i])
		{
			printf(" %s", n->data.cmd.argv[i]);
			++i;
		}
		puts("");
		r = n->data.cmd.redirs;
		while (r)
		{
			i = 0;
			while (i < (size_t)(d + 1))
			{
				printf("  ");
				++i;
			}
			printf(RED "redir" RESET " %d -> %s\n", r->type, r->file);
			r = r->next;
		}
	}
}

static t_token	*next_tok(\
	t_lexer *l
)
{
	return (&l->tokens[l->pos++]);
}

static t_token	*peek_tok(\
	t_lexer *l
)
{
	return (&l->tokens[l->pos]);
}

void	token_free_all(\
	t_token *t
)
{
	register size_t	i = (size_t)-1;

	if (!t)
		return ;
	while (t[++i].type != TOK_EOF)
		if (t[i].type == TOK_WORD)
			free(t[i].value);
	free(t);
}

static int	read_redir(\
	t_lexer *lxr,
	t_ast *cmd
)
{
	t_token			*tok;
	t_redir_type	tp;
	char			*file;

	tok = next_tok(lxr);
	tp = (tok->type == TOK_LESS) ? REDIR_IN :
		(tok->type == TOK_GREAT) ? REDIR_OUT :
		(tok->type == TOK_DGREAT) ? REDIR_APPEND : REDIR_HEREDOC;
	tok = next_tok(lxr);
	if (tok->type != TOK_WORD)
		return (-1);
	file = strdup(tok->value);
	return (file && !ast_add_redir(cmd, tp, file) ? 0 : -1);
}

static int	consume_redirs(\
	t_lexer *lxr,
	t_ast *cmd
)
{
	while (peek_tok(lxr)->type == TOK_LESS || peek_tok(lxr)->type == TOK_GREAT \
		|| peek_tok(lxr)->type == TOK_DGREAT || peek_tok(lxr)->type == TOK_DLESS)
		if (read_redir(lxr, cmd) == -1)
			return (-1);
	return (0);
}

static t_ast	*parse_simple_command(\
	t_lexer *lxr
)
{
	t_ast			*cmd;
	t_token			*tok;
	t_token			*scan;
	char			**argv;
	size_t			ac = 0;
	register size_t	i = 0;

	tok = peek_tok(lxr);
	if (tok->type != TOK_WORD && tok->type != TOK_LESS \
		&& tok->type != TOK_GREAT && tok->type != TOK_DGREAT \
		&& tok->type != TOK_DLESS)
		return (NULL);
	scan = tok;
	while (scan->type == TOK_WORD || scan->type == TOK_LESS \
		|| scan->type == TOK_GREAT || scan->type == TOK_DGREAT \
		|| scan->type == TOK_DLESS)
	{
		if (scan->type == TOK_WORD)
		{
			++ac;
			++scan;
		}
		else
			scan += 2;
	}
	argv = calloc(ac + 1, sizeof(char *));
	if (!argv)
		return (NULL);
	cmd = ast_cmd_new(argv);
	if (!cmd)
		return (free(argv), NULL);
	if (consume_redirs(lxr, cmd) == -1)
		return (ast_destroy(cmd), NULL);
	while (peek_tok(lxr)->type == TOK_WORD)
	{
		argv[i] = strdup(next_tok(lxr)->value);
		if (!argv[i++])
			return (ast_destroy(cmd), NULL);
		if (consume_redirs(lxr, cmd) == -1)
			return (ast_destroy(cmd), NULL);
	}
	return (cmd);
}

t_ast	*parse_pipeline(\
	t_lexer *lxr
)
{
	t_ast	*lhs;
	t_ast	*rhs;

	lhs = parse_simple_command(lxr);
	if (!lhs)
		return (NULL);
	if (peek_tok(lxr)->type == TOK_PIPE)
	{
		++lxr->pos;
		rhs = parse_pipeline(lxr);
		if (!rhs)
			return (ast_destroy(lhs), NULL);
		return (ast_pipe_new(lhs, rhs));
	}
	return (lhs);
}

static int	push_token(\
	t_token **toks,
	size_t *n,
	size_t *cap,
	t_tok_type tp,
	char *val
)
{
	if (*n + 2 > *cap)
	{
		*cap *= 2;
		*toks = (t_token *)realloc(*toks, *cap * sizeof(**toks));
		if (!*toks)
			return (-1);
	}
	(*toks)[*n].type = tp;
	(*toks)[*n].value = val;
	(*n)++;
	return (0);
}

t_token	*tokenize_line(\
	const char *line
)
{
	t_token		*toks;
	char		*word;
	size_t		cap = 16;
	size_t		len;
	size_t		n = 0;

	toks = malloc(cap * sizeof(*toks));
	if (!toks)
		return (NULL);
	while (*line)
	{
		while (isspace((unsigned char)*line))
			++line;
		if (!*line)
			break ;
		if (*line == '|')
		{
			push_token(&toks, &n, &cap, TOK_PIPE, NULL);
			++line;
		}
		else if (*line == '<' && line[1] == '<')
		{
			push_token(&toks, &n, &cap, TOK_DLESS, NULL);
			line += 2;
		}
		else if (*line == '>' && line[1] == '>')
		{
			push_token(&toks, &n, &cap, TOK_DGREAT, NULL);
			line += 2;
		}
		else if (*line == '<')
		{
			push_token(&toks, &n, &cap, TOK_LESS, NULL);
			++line;
		}
		else if (*line == '>')
		{
			push_token(&toks, &n, &cap, TOK_GREAT, NULL);
			++line;
		}
		else
		{
			const char	*start = line;

			while (*line && !isspace((unsigned char)*line) \
				&& *line != '|' && *line != '<' && *line != '>')
				++line;
			len = (size_t)(line - start);
			word = strndup(start, len);
			if (!word || push_token(&toks, &n, &cap, TOK_WORD, word))
				return (token_free_all(toks), NULL);
		}
	}
	push_token(&toks, &n, &cap, TOK_EOF, NULL);
	return (toks);
}

__attribute__((unused))
static inline char	*_pre_proc(
	const int argc,
	char **argv
)

{
	register unsigned int	i;
	size_t					len;
	char					*line;

	len = 1;
	i = 1;
	while (i < (unsigned)argc)
		len += strlen(argv[i++]) + 1;
	line = malloc(len);
	if (!line)
		return (NULL);
	*line = '\0';
	i = 1;
	while (i < (unsigned)argc)
	{
		strcat(line, argv[i]);
		if (++i < (unsigned)argc)
			strcat(line, " ");
	}
	return (line);
}

t_ast	*full_ast(
	char **input
)
{
	t_ast					*root;
	t_lexer					lxr;
	t_token					*toks;
	char					*line;

	line = memdup(*input, ft_strlen(*input) + 1);// _pre_proc(1, input);
	if (_UNLIKELY(!line))
		return (ft_perror("full_ast(): pre_proc failed"), NULL);
	toks = tokenize_line(line);
	mm_free(line);
	if (_UNLIKELY(!toks))
		return (ft_perror("full_ast(): tokenize_line failed"), NULL);
	lxr = (t_lexer){
		.tokens = toks,
		.pos = 0
	};
	root = parse_pipeline(&lxr);
	if (_UNLIKELY(!root))
		return (ft_perror(""), token_free_all(toks), NULL);
	ast_print(root, 0);
	// ast_destroy(root);
	return (token_free_all(toks), root);
}

#pragma endregion Fonctions
#pragma region Main

/*int	main(int argc, char **argv)
{
	t_ast					*root;
	t_lexer					lxr;
	t_token					*toks;
	char					*line;
	size_t					len = 1;
	unsigned int			i;

	if (argc < 2)
		return (-1);
	i = 1;
	line = _pre_proc(argc, argv);
	if (!line)
		return (-1);
	toks = tokenize_line(line);
	free(line);
	if (!toks)
		return (-1);
	lxr = (t_lexer){\
		.tokens = toks,\
		.pos = 0\
	};
	root = parse_pipeline(&lxr);
	if (!root)
		return (token_free_all(toks), -1);
	ast_print(root, 0);
	ast_destroy(root);
	return (token_free_all(toks), 0);
}*/

#pragma endregion Main