#include <stdlib.h>
#include <stdio.h>

static void cleanup_int(int *p) {
	fprintf(stderr, "Cleaning up: %d\n", *p);
}

static void cleanup_ptr(void *p)
{
	char *ptr = *(char **)p;
	if (p) {
		fprintf(stderr, "Cleaning up pointer: %p\n", p);
		free(p);
	} else {
		fprintf(stderr, "Pointer is NULL, nothing to clean up.\n");
	}
}

int main(void) {
	__attribute__((cleanup(cleanup_int))) int x = 42;

	__attribute__((cleanup(cleanup_ptr))) char *str = malloc(100);
	if (!str) {
		perror("Failed to allocate memory");
		return 1;
	}
	printf("Allocated memory at: %p\n", (void *)str);
	sprintf(str, "Hello, World!");
	fprintf(stderr, "String: %s\n", str);
	return 0;
}
