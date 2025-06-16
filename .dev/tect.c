#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[], const char *env[])
{

	execve(NULL, (char *const *){NULL}, env);
	return 0;
}