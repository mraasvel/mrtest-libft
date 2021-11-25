#include "mrtest_libft.h"
#include <stdbool.h>

static bool AssertStrlen(const char* x) {
	return strlen(x) == ft_strlen(x);
}

TEST_CASE("TestStrlen", "strlen") {
	MRTEST(AssertStrlen(""));
	MRTEST(AssertStrlen("9fa98sduf98asudnf98aunsd98fvunas98dfunva98sdufn98asudnf9asdfv"));
	MRTEST(AssertStrlen("1234\n\t1234\n\t\01"));
	MRTEST(AssertStrlen("12345\067890"));
	MRTEST(AssertStrlen("1234567890"));
	MRTEST(AssertStrlen("r\0r"));
}
