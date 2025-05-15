#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	execve("/bin/ls", (char *const []){"/bin/ls", NULL}, (char *const []){"PATH=/bin:/usr/bin", NULL});
}
