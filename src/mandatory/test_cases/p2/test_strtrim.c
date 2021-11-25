#include "mrtest_libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static bool strtrimCompare(const char* s, const char* set, const char* expected) {
	char* x = ft_strtrim(s, set);
	if (x == 0) {
		fprintf(stderr, "%s:%d [ft_strtrim(\"%s\", \"%s\");]: returned NULL\n",
			__FILE__, __LINE__,
			s, set);
		exit(EXIT_FAILURE);
	}

	bool result = strcmp(x, expected) == 0;
	free(x);
	return result;
}

TEST_CASE("strtrim", "strtrim") {
	MRTEST(strtrimCompare("\t\tn1234567890\t\t\n", "\n\t", "n1234567890"));
	MRTEST(strtrimCompare("\t\tn12345\t\t67890\t\t\n", "\n\t", "n12345\t\t67890"));
	MRTEST(strtrimCompare("", "123567890", ""));
	MRTEST(strtrimCompare("", "", ""));
	MRTEST(strtrimCompare("abc", "", "abc"));
	MRTEST(strtrimCompare("abcd123457890efgh", "123567890", "abcd123457890efgh"));
	MRTEST(strtrimCompare("baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac", "a", "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac"));
	MRTEST(strtrimCompare("abaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaca", "a", "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac"));
	MRTEST(strtrimCompare("aabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacaa", "a", "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac"));
	MRTEST(strtrimCompare("aabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacaa", "ab", "c"));
	MRTEST(strtrimCompare("aabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacaa", "abc", ""));
}
