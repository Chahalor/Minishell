#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *input;

	// Read a line of input from the user
	input = readline("Enter a command: ");
	if (input == NULL)
	{
		perror("readline");
		return 1;
	}

	// Print the input back to the user
	printf("You entered: %s\n", input);

	// Free the allocated memory for the input
	free(input);
	
	return 0;
}