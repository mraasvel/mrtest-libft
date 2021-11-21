#include "libft.h"
#include "mrtest.h"
#include <string.h>
#include <stdbool.h>

static bool strncmpCompare(const char* a, const char* b, size_t n) {
	int ft = ft_strncmp(a, b, n);
	int st = strncmp(a, b, n);
	// Both 0, or same sign
	return st == 0 ? st == ft : ((st < 0 && ft < 0) || (st > 0 && ft > 0));
}

TEST_CASE("strncmp", "strncmp") {
	strncmpCompare("1234567890", "1234567890", 5);
	strncmpCompare("1234567890", "123456789a", 10);
	strncmpCompare("1234567890", "1234567890", 0);
	strncmpCompare("1234567890", "123456789a", 5);
	strncmpCompare("1234567890", "123456789a", 100);
	strncmpCompare("1234567890a", "1234567890", 100);
	strncmpCompare("123456789a", "1234567890", 100);
	strncmpCompare("1234567890", "1234567890", 100);
	strncmpCompare("1", "", 100);
	strncmpCompare("", "1", 100);
	strncmpCompare("", "", 100);
	strncmpCompare("", "", 0);
	strncmpCompare("a", "", 0);
	strncmpCompare("", "a", 0);
	strncmpCompare("123", "abc", 0);
	strncmpCompare("abcd", "abcd", 4);
	strncmpCompare("abcd", "abce", 3);
	strncmpCompare("abcd", "abd", 3);
}
