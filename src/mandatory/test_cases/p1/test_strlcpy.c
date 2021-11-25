#ifdef __APPLE__

#include "mrtest_libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>

static bool strlcpyCompare(const char* src, size_t n) {
	char* ft = malloc(n + 1);
	char* st = malloc(n + 1);

	if (!ft || !st) {
		fprintf(stderr, "%s:%d [%s]: %s\n", __FILE__, __LINE__, __FUNCTION__, strerror(errno));
		exit(EXIT_FAILURE);
	}
	memset(ft, 0, n + 1);
	memset(st, 0, n + 1);


	if (strlcpy(st, src, n) != ft_strlcpy(ft, src, n)) {
		return false;
	}

	return memcmp(st, ft, n + 1) == 0;
}

TEST_CASE("strlcpy", "strlcpy") {
	MRTEST(strlcpyCompare("1234567890", 5));
	MRTEST(strlcpyCompare("1234567890", 10));
	MRTEST(strlcpyCompare("", 1));
	MRTEST(strlcpyCompare("", 1000));
	MRTEST(strlcpyCompare("1234567890", 0));
	MRTEST(strlcpyCompare("d9sd8fu a9fds8 9d8f9 8sdfa9 8sdf89 fsdas9da8f ", 10000));
	MRTEST(strlcpyCompare("aijfsdoijfdsaaoijsfdajsfdoijafsdoijfsdaafsijdofsdia", 20));
}

#endif /* __APPLE__ */
