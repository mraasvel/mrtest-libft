#include <stdlib.h>
#include <stdio.h>

void exitPerror(const char* x) {
	perror(x);
	exit(EXIT_FAILURE);
}
