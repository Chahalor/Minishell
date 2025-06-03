#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
# include <stdio.h>

typedef enum e_token_type {
	TOKEN_CMD,
	TOKEN_PATH_FILE,
	TOKEN_PATH_DIR,
	TOKEN_PATH,
	TOKEN_UNKNOWN
}	t_token_type;

static inline int	_is_dir(const char *path)
{
	struct stat st;

	if (stat(path, &st) == 0 && S_ISDIR(st.st_mode))
		return (1);
	return (0);
}

static inline int	_is_file(const char *path)
{
	struct stat st;

	if (stat(path, &st) == 0 && S_ISREG(st.st_mode))
		return (1);
	return (0);
}

static inline char	*_get_full_path(const char *name)
{
	char	*path_env = getenv("PATH");
	char	*path = strtok(path_env ? strdup(path_env) : NULL, ":");

	while (path)
	{
		char	*full_path = malloc(strlen(path) + strlen(name) + 2);
		if (!full_path)
			return (NULL);
		sprintf(full_path, "%s/%s", path, name);
		if (access(full_path, X_OK) == 0)
			return (full_path); // appelant doit free()
		free(full_path);
		path = strtok(NULL, ":");
	}
	return (NULL);
}

__attribute__((always_inline)) inline t_token_type	classify_token(const char *token)
{
	if (!token || !*token)
		return (TOKEN_UNKNOWN);
	if (token[0] == '/' || strncmp(token, "./", 2) == 0 || strncmp(token, "../", 3) == 0)
	{
		if (_is_dir(token))
			return (TOKEN_PATH_DIR);
		else if (_is_file(token))
			return (TOKEN_PATH_FILE);
		else
			return (TOKEN_PATH);
	}
	else
	{
		char *cmd_path = _get_full_path(token);
		if (cmd_path)
		{
			free(cmd_path);
			return (TOKEN_CMD);
		}
	}
	return (TOKEN_UNKNOWN);
}
int main(int argc, char const *argv[])

{
	char	*str;

	if (argc <= 1)
		str = "/home/nduvoid/Desktop/Minishell/./";
	else
		str = (char *)argv[1];

	t_token_type type = classify_token(str);
	if (type == TOKEN_CMD)
		printf("C’est une commande\n");
	else if (type == TOKEN_PATH_FILE)
		printf("C’est un fichier\n");
	else if (type == TOKEN_PATH_DIR)
		printf("C’est un dossier\n");
	else
		printf("Inconnu\n");
	return 0;
}