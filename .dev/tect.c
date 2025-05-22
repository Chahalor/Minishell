#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char *line = readline("Mini> ");
	while (line)
	{
		add_history(line);
		printf("You entered: %s\n", line);
		free(line);
		line = readline("Mini> ");
	}
	return 0;
}
