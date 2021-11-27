#include "mrtest_libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

static bool callocCompare(size_t nmemb, size_t size) {
	char* x = calloc(nmemb, size);
	char* y = ft_calloc(nmemb, size);

	bool result = true;

	if (!x || !y) {
		return x == y;
	}

	for (size_t i = 0; i < nmemb * size; ++i) {
		if (x[i] != y[i]) {
			result = false;
			break;
		}
	}

	free(x);
	free(y);
	return result;
}

TEST_CASE("ft_calloc", "ft_calloc") {
	MRTEST(callocCompare(2349857, 1));
	MRTEST(callocCompare(50, 0));
	MRTEST(callocCompare(0, 50));
	MRTEST(callocCompare(1, 25));
}
