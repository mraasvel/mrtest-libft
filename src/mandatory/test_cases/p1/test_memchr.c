#include "mrtest_libft.h"
#include <string.h>
#include <stdbool.h>

static bool memchrCompare(const char* x, int c, size_t n) {
	return memchr(x, c, n) == ft_memchr(x, c, n);
}

TEST_CASE("memchr", "memchr") {
	MRTEST(memchrCompare("", 'a', 0));
	MRTEST(memchrCompare("1234567890", 'a', 10));
	MRTEST(memchrCompare("1234567890", '0', 10));
	MRTEST(memchrCompare("1234567890", '9', 10));
	MRTEST(memchrCompare("1234567890", '9', 5));
	MRTEST(memchrCompare("1234567890", '9', 8));
	MRTEST(memchrCompare("1234567890", '9', 9));
	MRTEST(memchrCompare("", 'a', 1));
	MRTEST(memchrCompare("", 0, 1));
}
