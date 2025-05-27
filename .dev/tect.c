#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	const char *path = "../.dev";
	struct stat sb;

	if (access(path, F_OK) == 0)
	{
		printf("Path exists: %s\n", path);
		if (stat(path, &sb) == 0)
		{
			printf("File type: ");
			if (S_ISREG(sb.st_mode))
				printf("regular file\n");
			else if (S_ISDIR(sb.st_mode))
				printf("directory\n");
			else if (S_ISLNK(sb.st_mode))
				printf("symbolic link\n");
			else
				printf("other\n");
		}
		else
		{
			perror("Error getting file status");
			return 1;
		}
	}
	else
	{
		perror("Error accessing path");
		return 1;
	}
	return 0;
}