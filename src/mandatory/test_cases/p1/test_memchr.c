#include "mrtest.h"
#include "libft.h"
#include <string.h>
#include <stdbool.h>

static bool memchrCompare(const char* x, int c, size_t n) {
	return memchr(x, c, n) == ft_memchr(x, c, n);
}

TEST_CASE("memchr", "memchr") {
	memchrCompare("", 'a', 0);
	memchrCompare("1234567890", 'a', 10);
	memchrCompare("1234567890", '0', 10);
	memchrCompare("1234567890", '9', 10);
	memchrCompare("1234567890", '9', 5);
	memchrCompare("1234567890", '9', 8);
	memchrCompare("1234567890", '9', 9);
	memchrCompare("", 'a', 1);
	memchrCompare("", 0, 1);
}
