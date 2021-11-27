#include "mrtest_libft.h"
#include <string.h>
#include <stdbool.h>

static bool strncmpCompare(const char* a, const char* b, size_t n) {
	int ft = ft_strncmp(a, b, n);
	int st = strncmp(a, b, n);
	// Both 0, or same sign
	return st == 0 ? st == ft : ((st < 0 && ft < 0) || (st > 0 && ft > 0));
}

TEST_CASE("strncmp", "strncmp") {
	MRTEST(strncmpCompare("1234567890", "1234567890", 5));
	MRTEST(strncmpCompare("1234567890", "123456789a", 10));
	MRTEST(strncmpCompare("1234567890", "1234567890", 0));
	MRTEST(strncmpCompare("1234567890", "123456789a", 5));
	MRTEST(strncmpCompare("1234567890", "123456789a", 100));
	MRTEST(strncmpCompare("1234567890a", "1234567890", 100));
	MRTEST(strncmpCompare("123456789a", "1234567890", 100));
	MRTEST(strncmpCompare("1234567890", "1234567890", 100));
	MRTEST(strncmpCompare("1", "", 100));
	MRTEST(strncmpCompare("", "1", 100));
	MRTEST(strncmpCompare("", "", 100));
	MRTEST(strncmpCompare("", "", 0));
	MRTEST(strncmpCompare("a", "", 0));
	MRTEST(strncmpCompare("", "a", 0));
	MRTEST(strncmpCompare("123", "abc", 0));
	MRTEST(strncmpCompare("abcd", "abcd", 4));
	MRTEST(strncmpCompare("abcd", "abce", 3));
	MRTEST(strncmpCompare("abcd", "abd", 3));
}
