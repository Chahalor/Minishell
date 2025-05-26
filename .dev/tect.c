#include <stdio.h>
#include <sys/stat.h>

int main(int argc, const char *argv[])
{
	char *path = "/bin/ls";
	struct stat tkt = {0};

	if (argc > 1)
		path = (char *)argv[1];
	
	printf("%d\n", stat(path, &tkt));
	printf("st_mode: %o\n", tkt.st_mode);
	printf("st_size: %ld\n", tkt.st_size);
	if (S_ISREG(tkt.st_mode))
		printf("It's a regular file.\n");
	else if (S_ISDIR(tkt.st_mode))
		printf("It's a directory.\n");
	else if (S_ISLNK(tkt.st_mode))
		printf("It's a symbolic link.\n");
	else
		printf("It's something else.\n");
	return 0;
}