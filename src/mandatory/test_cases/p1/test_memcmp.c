#include "mrtest_libft.h"
#include <string.h>
#include <stdbool.h>

static bool memcmpCompare(const void* a, const void* b, size_t n) {
	int st = memcmp(a, b, n);
	int ft = ft_memcmp(a, b, n);

	return st == 0 ? st == ft : ((st < 0) && (ft < 0)) || ((st > 0) && (ft > 0));
}

TEST_CASE("memcmp", "memcmp") {
	MRTEST(memcmpCompare("1234567890", "1234567890", 10));
	MRTEST(memcmpCompare("1234567890", "123456789", 10));
	MRTEST(memcmpCompare("1234567890", "123456789", 9));
	MRTEST(memcmpCompare("123456789", "1234567890", 9));
	MRTEST(memcmpCompare("1234567890", "123456789a", 10));
	MRTEST(memcmpCompare("1234z67890", "123456789a", 10));
	MRTEST(memcmpCompare("", "", 1));
	MRTEST(memcmpCompare("", "", 0));
	MRTEST(memcmpCompare("1234567890", "1234567890", 5));
	MRTEST(memcmpCompare("1234567890", "1234567890", 0));
	MRTEST(memcmpCompare("1234567890", "123456789a", 5));
	MRTEST(memcmpCompare("", "", 0));
	MRTEST(memcmpCompare("a", "", 0));
	MRTEST(memcmpCompare("", "a", 0));
	MRTEST(memcmpCompare("123", "abc", 0));
	MRTEST(memcmpCompare("abcd", "abcd", 4));
	MRTEST(memcmpCompare("abcd", "abce", 3));
	MRTEST(memcmpCompare("abcd", "abd", 3));
}
