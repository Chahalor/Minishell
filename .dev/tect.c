#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	char *line;

	line = readline("prompt> ");
	while (line)
	{
		printf("line ? <%s>\n", line);
		free(line);
		line = readline("prompt> ");
	}
	return (0);
}
