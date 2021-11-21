#include "libft.h"
#include "mrtest.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

static bool bzeroSizeTest(size_t n) {
	char* x = malloc(n);

	if (x == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	ft_bzero(x, n);
	while (n > 0) {
		--n;
		if (x[n] != 0) {
			free(x);
			return false;
		}
	}

	free(x);
	return true;
}

TEST_CASE("TestBzero", "bzero") {
	MRTEST(bzeroSizeTest(1));
	MRTEST(bzeroSizeTest(1024));
}
