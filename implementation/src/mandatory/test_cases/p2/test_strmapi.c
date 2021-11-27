#include "mrtest_libft.h"
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

static char evenToUpper(unsigned int i, char c) {
	return i % 2 == 0 ? toupper(c) : c;
}

static char evenToLower(unsigned int i, char c) {
	return i % 2 == 0 ? tolower(c) : c;
}

static bool strmapiCompare(const char* s, char (*f)(unsigned int, char), const char* expected) {
	char* x = ft_strmapi(s, f);
	if (x == NULL) {
		exitPerror("malloc");
	}

	const bool result = strcmp(x, expected) == 0;
	free(x);
	return result;
}

TEST_CASE("strmapi", "strmapi") {
	MRTEST(strmapiCompare("1234567890", &evenToUpper, "1234567890"));
	MRTEST(strmapiCompare("abcdefghijklmnop", &evenToUpper, "AbCdEfGhIjKlMnOp"));
	MRTEST(strmapiCompare("ABCDEFGHIJKLMNOPQRSTUVWXYZ", &evenToLower, "aBcDeFgHiJkLmNoPqRsTuVwXyZ"));
	MRTEST(strmapiCompare("", &evenToLower, ""));
}
