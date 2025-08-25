#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#pragma region HEADER

typedef enum e_token_type t_token_type;
typedef struct s_token t_token;

enum e_token_type
{
	TOKEN_PIPE,
	TOKEN_QUOTE,
	TOKEN_DQUOTE,
	TOKEN_GREATER,
	TOKEN_LESS,
	TOKEN_DGREATER,
	TOKEN_DLESS,
	TOKEN_WORD
};

struct s_token
{
	char	*value;
	int		type;
	int		size;
};


#pragma endregion HEADER
#pragma region PARSER

static inline char *strjoin(char *s1, const char *s2)
{
	if (!s1 && !s2) return NULL;
	if (!s1) return strdup(s2);
	if (!s2) return s1;
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	char *result = malloc(len1 + len2 + 1);
	if (!result) { free(s1); return NULL; }
	memcpy(result, s1, len1);
	memcpy(result + len1, s2, len2);
	result[len1 + len2] = '\0';
	free(s1);
	return result;
}

static inline int	is_delim(
	const char c
)
{
	return (c == ' ' || c == '\'' || c == '"' || c == '|' || c == '>' || c == '<');
}

char	**spliter(
	char *line
)
{
	t_token			**result = NULL;
	int				count = 0;
	char			delim;
	register int	i;
	register int	j;
	register int	start;

	delim = 0;
	i = -1;
	while (line[++i])
	{
		if (delim)
		{
			while (line[i] && line[i] != delim)
				++i;
			delim = 0;
			++count;
		}
		else if (line[i] == '\'' || line[i] == '"')
			delim = line[i];
		else
			delim = ' ';
	}
	printf("Counted %d tokens\n", count);
	result = malloc((count + 1) * sizeof(t_token *));
	if (!result)
		return (NULL);
	j = 0;
	result[j] = malloc(1 * sizeof(t_token));
	i = -1;
	start = 0;
	while (line[++i])
	{
		if (delim)
		{
			while (line[i] && line[i] != delim)
				++i;
			delim = 0;
			++count;
			result[j]->size = i; 
		}
		else if (line[i] == '\'' || line[i] == '"')
			delim = line[i];
		else
			delim = ' ';
	}
	return result;
}


#pragma endregion PARSER
#pragma region MANUAL_TEST

// /* ===== Manual test ===== */
// int main(int argc, char **argv)
// {
// 	char *cmd = NULL;

// 	for (int i = 1; i < argc; i++)
// 	{
// 		char *tmp = strdup(argv[i]);
// 		if (!tmp)
// 			return 1;
// 		cmd = strjoin(cmd, tmp);
// 		free(tmp);
// 	}
// 	if (!cmd)
// 		return 1;
// 	spliter(cmd);


// 	return 0;
// }

#pragma endregion MANUAL_TEST
#pragma region GPT

/* Create a new token */
t_token *token_new(const char *str, int type, int size)
{
    t_token *tok = malloc(sizeof(t_token));
    if (!tok) return NULL;
    tok->value = strndup(str, size);
    tok->type = type;
    tok->size = size;
    return tok;
}

/* Simple tokenizer: splits line into tokens */
t_token **tokenize_line(const char *line, int *count)
{
	size_t len = strlen(line);
	size_t cap = 8;
	t_token **tokens = malloc(cap * sizeof(t_token*));
	size_t idx = 0;

	for (size_t i = 0; i < len; ) {
		if (isspace(line[i])) { i++; continue; }

		if (line[i] == '|') {
			tokens[idx++] = token_new("|", TOKEN_PIPE, 1); i++;
		}
		else if (line[i] == '\'') {
			size_t start = i+1;
			i++;
			while (i < len && line[i] != '\'') i++;
			tokens[idx++] = token_new(line+start, TOKEN_QUOTE, i-start);
			i++; // skip closing quote
		}
		else if (line[i] == '"') {
			size_t start = i+1;
			i++;
			while (i < len && line[i] != '"') i++;
			tokens[idx++] = token_new(line+start, TOKEN_DQUOTE, i-start);
			i++; // skip closing quote
		}
		else if (line[i] == '>' && line[i+1] == '>') {
			tokens[idx++] = token_new(">>", TOKEN_DGREATER, 2); i+=2;
		}
		else if (line[i] == '<' && line[i+1] == '<') {
			tokens[idx++] = token_new("<<", TOKEN_DLESS, 2); i+=2;
		}
		else if (line[i] == '>') {
			tokens[idx++] = token_new(">", TOKEN_GREATER, 1); i++;
		}
		else if (line[i] == '<') {
			tokens[idx++] = token_new("<", TOKEN_LESS, 1); i++;
		}
		else {
			size_t start = i;
			while (i < len && !isspace(line[i]) &&
				line[i] != '|' && line[i] != '<' && line[i] != '>')
				i++;
			tokens[idx++] = token_new(line+start, TOKEN_WORD, i-start);
		}

		// Resize array if needed
		if (idx >= cap) {
			cap *= 2;
			tokens = realloc(tokens, cap * sizeof(t_token*));
		}
	}

	*count = idx;
	return tokens;
}

char *show_type(int type)
{
	switch(type)
	{
		case TOKEN_PIPE: return "\033[1;36mPIPE\033[0m";
		case TOKEN_QUOTE: return "\033[1;33mQUOTE\033[0m";
		case TOKEN_DQUOTE: return "\033[1;32mDQUOTE\033[0m";
		case TOKEN_GREATER: return "\033[1;31mGREATER\033[0m";
		case TOKEN_LESS: return "\033[1;35mLESS\033[0m";
		case TOKEN_DGREATER: return "\033[1;34mDGREATER\033[0m";
		case TOKEN_DLESS: return "\033[1;34mDLESS\033[0m";
		case TOKEN_WORD: return "\033[1;37mWORD\033[0m";
		default: return "\033[1;30mUNKNOWN\033[0m";
	}
}

/* ===== Debug print ===== */
void print_tokens(t_token **tokens, int count)
{
    for (int i = 0; i < count; i++)
        printf("[%s] type=%s size=%d\n", tokens[i]->value, show_type(tokens[i]->type), tokens[i]->size);
}

/* ===== Test ===== */
int main(int argc, char **argv)
{
	int i = 0;
	char *line = NULL;
	while (argv[++i])
		line = strjoin(line, argv[i]);
    int count;
    t_token **tokens = tokenize_line(line, &count);
    print_tokens(tokens, count);

    // Free tokens
    for (int i=0;i<count;i++) {
        free(tokens[i]->value);
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}


#pragma endregion GPT