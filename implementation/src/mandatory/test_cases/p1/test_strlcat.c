#ifdef __APPLE__

#include "mrtest_libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

static bool strlcatCompare(const char* dst, const char* src, size_t n) {
	char* ft = malloc(n + 1);
	char* st = malloc(n + 1);

	if (!ft || !st) {
		fprintf(stderr, "%s:%d [%s]: %s\n", __FILE__, __LINE__, __FUNCTION__, strerror(errno));
		exit(EXIT_FAILURE);
	}
	memset(ft, 0, n + 1);
	memset(st, 0, n + 1);
	strlcpy(ft, dst, n);
	strlcpy(st, dst, n);

	if (strlcat(st, src, n) != ft_strlcat(ft, src, n)) {
		return false;
	}

	return memcmp(st, ft, n + 1) == 0;
}

TEST_CASE("ft_strlcat", "ft_strlcat") {
	MRTEST(strlcatCompare("1234567890", "1234567890", 20));
	MRTEST(strlcatCompare("1234567890", "1234567890", 10));
	MRTEST(strlcatCompare("1234567890", "1234567890", 5));
	MRTEST(strlcatCompare("", "1234567890", 100));
	MRTEST(strlcatCompare("", "1234567890", 4));
	MRTEST(strlcatCompare("1234567890", "", 100));
	MRTEST(strlcatCompare("1234567890", "1", 0));

}

#endif /* __APPLE__ */
