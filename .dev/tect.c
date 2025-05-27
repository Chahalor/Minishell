#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

char	*file_generator(const char *text, int state)
{
	static DIR *dir;
	static struct dirent *entry;

	if (!state)
	{
		if (dir)
			closedir(dir);
		dir = opendir(".");
	}
	if (!dir)
		return NULL;

	while ((entry = readdir(dir)))
	{
		if (strncmp(entry->d_name, text, strlen(text)) == 0)
			return strdup(entry->d_name);
	}
	return NULL;
}

char	**my_completion(const char *text, int start, int end)
{
	(void)start;
	(void)end;
	return rl_completion_matches(text, file_generator);
}

int	main(void)
{
	// rl_attempted_completion_function = my_completion;

	while (1)
	{
		char *line = readline("mysh$ ");
		if (!line)
			break;
		add_history(line);
		free(line);
	}
	return 0;
}
