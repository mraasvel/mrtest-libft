#include "mrtest.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static bool substrCompare(const char* s, unsigned int start, size_t len, const char* expected) {
	char* x = ft_substr(s, start, len);
	if (x == NULL) {
		fprintf(stderr, "%s:%d [ft_substr(\"%s\", %u, %lu);]: returned NULL\n",
			__FILE__, __LINE__,
			s, start, len);
		exit(EXIT_FAILURE);
	}

	bool result = strcmp(x, expected) == 0;
	free(x);
	return result;
}

TEST_CASE("substr", "substr") {
	MRTEST(substrCompare("1234567890", 5, 10, "67890"));
	MRTEST(substrCompare("1234567890", 5, 0, ""));
	MRTEST(substrCompare("1234567890", 5, 5, "67890"));
	MRTEST(substrCompare("1234567890", 12, 10, ""));
	MRTEST(substrCompare("1234567890", 5000, 10, ""));
	MRTEST(substrCompare("1234567890", 0, 10, "1234567890"));
	MRTEST(substrCompare("1234567890ofdsiaoijafsd", 0, 500, "1234567890ofdsiaoijafsd"));
	MRTEST(substrCompare("", 0, 500, ""));
	MRTEST(substrCompare("", 50, 500, ""));
}
