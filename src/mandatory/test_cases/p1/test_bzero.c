#include "mrtest_libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

static bool bzeroSizeTest(size_t n) {
	char* x = malloc(n);

	if (x == NULL) {
		exitPerror("malloc");
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
