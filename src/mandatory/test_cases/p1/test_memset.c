#include "mrtest.h"
#include "libft.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

static bool compareMemset(int c, size_t n) {

	char* x = malloc(n);
	char* y = malloc(n);
	bool result = false;

	if (!x || !y) {
		fprintf(stderr, "%s:%d [%s]: %s\n", __FILE__, __LINE__, __FUNCTION__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	if (memset(x, c, n) != x) {
		goto _MR_MEMSET_ERROR;
	}
	if (ft_memset(y, c, n) != y) {
		goto _MR_MEMSET_ERROR;
	}

	while (n-- > 0) {
		if (x[n] != y[n]) {
			goto _MR_MEMSET_ERROR;
		}
	}

	result = true;
_MR_MEMSET_ERROR:
	free(x);
	free(y);
	return result;
}

TEST_CASE("Memset Tests", "memset") {
	MRTEST(compareMemset('a', 1024));
	MRTEST(compareMemset(0, 1024));
	MRTEST(compareMemset(0, 0));
}

TEST_CASE("Memset Partial Copy", "memset") {

	const int size = 1024;
	const int set = 512;
	const int default_value = 0;
	const int ft_memset_value = 42;

	char* x = malloc(size);

	memset(x, default_value, size);
	ft_memset(x, ft_memset_value, set);
	for (int i = 0; i < size; ++i) {
		if (i < set) {
			MRTEST(x[i] == ft_memset_value);
		} else {
			MRTEST(x[i] == default_value);
		}
	}
}
