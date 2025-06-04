#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum e_token_type {
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_REDIR_IN,
    TOKEN_REDIR_HEREDOC,
    TOKEN_REDIR_OUT,
    TOKEN_REDIR_APPEND
} t_token_type;

typedef struct s_token {
    t_token_type type;
    char *value;
    struct s_token *next;
} t_token;

t_token *new_token(t_token_type type, const char *start, size_t len) {
    t_token *token = malloc(sizeof(t_token));
    token->type = type;
    token->value = strndup(start, len);
    token->next = NULL;
    return token;
}

void add_token(t_token **head, t_token *new) {
    if (!*head)
        *head = new;
    else {
        t_token *tmp = *head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

int is_operator(char c) {
    return (c == '<' || c == '>' || c == '|');
}

t_token *lex(const char *input)
{
	t_token *tokens = NULL;
	size_t i = 0;

	while (input[i])
	{
		if (isspace(input[i]))
		{
			i++;
			continue;
		}
		if (input[i] == '|')
		{
			add_token(&tokens, new_token(TOKEN_PIPE, input + i, 1));
			i++;
		}
		else if (input[i] == '<')
		{
			if (input[i + 1] == '<')
			{
				add_token(&tokens , new_token(TOKEN_REDIR_HEREDOC, input + i, 2));
				i += 2;
			}
			else
			{
				add_token(&tokens, new_token(TOKEN_REDIR_IN, input + i, 1));
				i++;
			}
		}
		else if (input[i] == '>')
		{
			if (input[i + 1] == '>')
			{
				add_token(&tokens, new_token(TOKEN_REDIR_APPEND, input + i, 2));
				i += 2;
			}
			else
			{
				add_token(&tokens, new_token(TOKEN_REDIR_OUT, input + i, 1));
				i++;
			}
		}
		else
		{
			size_t start = i;
			while (input[i] && !isspace(input[i]) && !is_operator(input[i]))
				i++;
			add_token(&tokens, new_token(TOKEN_WORD, input + start, i - start));
		}
	}
	return tokens;
}

void print_tokens(t_token *tok) {
    while (tok) {
        printf("TOKEN_%d: \"%s\"\n", tok->type, tok->value);
        tok = tok->next;
    }
}

int main(int argc, char *argv[])
{
    char *line = NULL;

	if (argc > 1) 
		line = argv[1];
	else
		line = "echo hello | grep h > output.txt";

    t_token *tokens = lex(line);
    print_tokens(tokens);
    return 0;
}
