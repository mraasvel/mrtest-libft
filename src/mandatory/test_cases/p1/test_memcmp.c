#include "mrtest.h"
#include "libft.h"
#include <string.h>
#include <stdbool.h>

static bool memcmpCompare(const void* a, const void* b, size_t n) {
	int st = memcmp(a, b, n);
	int ft = ft_memcmp(a, b, n);

	return st == 0 ? st == ft : ((st < 0) && (ft < 0)) || ((st > 0) && (ft > 0));
}

TEST_CASE("memcmp", "memcmp") {
	memcmpCompare("1234567890", "1234567890", 10);
	memcmpCompare("1234567890", "123456789", 10);
	memcmpCompare("1234567890", "123456789", 9);
	memcmpCompare("123456789", "1234567890", 9);
	memcmpCompare("1234567890", "123456789a", 10);
	memcmpCompare("1234z67890", "123456789a", 10);
	memcmpCompare("", "", 1);
	memcmpCompare("", "", 0);
	memcmpCompare("1234567890", "1234567890", 5);
	memcmpCompare("1234567890", "1234567890", 0);
	memcmpCompare("1234567890", "123456789a", 5);
	memcmpCompare("", "", 0);
	memcmpCompare("a", "", 0);
	memcmpCompare("", "a", 0);
	memcmpCompare("123", "abc", 0);
	memcmpCompare("abcd", "abcd", 4);
	memcmpCompare("abcd", "abce", 3);
	memcmpCompare("abcd", "abd", 3);
}
