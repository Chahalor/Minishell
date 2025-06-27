#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, const char *argv[], const char *env[])
{

	DIR *dir = opendir("sus");

	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL)
	{
		printf("Found file: %p\n", entry);
		printf("Found file: %s\n", entry->d_name);
	}

	closedir(dir);
	return EXIT_SUCCESS;
}