#include "mrtest_libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static bool strjoinCompare(const char* s1, const char* s2, const char* exp) {
	char* x = ft_strjoin(s1, s2);

	if (x == NULL) {
		fprintf(stderr, "%s:%d [ft_strjoin(\"%s\", \"%s\");]: returned NULL\n",
			__FILE__, __LINE__,
			s1, s2);
		exit(EXIT_FAILURE);
	}

	bool result = strcmp(x, exp) == 0;
	free(x);
	return result;
}

TEST_CASE("ft_strjoin", "ft_strjoin") {
	MRTEST(strjoinCompare("", "1234567890", "1234567890"));
	MRTEST(strjoinCompare("1234567890", "1234567890", "12345678901234567890"));
	MRTEST(strjoinCompare("1234567890", "", "1234567890"));
	MRTEST(strjoinCompare("12345\0 67890", "\t\0", "12345\t"));
	MRTEST(strjoinCompare("", "", ""));
}
