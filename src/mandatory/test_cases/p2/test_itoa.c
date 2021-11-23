#include "libft.h"
#include "mrtest.h"
#include "mrtest_libft.h"
#include <stdbool.h>

static bool AssertItoa(int n, const char* expected) {
	char* x = ft_itoa(n);
	if (x == NULL) {
		exitPerror("malloc");
	}

	if (strcmp(x, expected) != 0) {
		free(x);
		return false;
	}

	free(x);
	return true;
}

TEST_CASE("itoa", "itoa") {
	MRTEST(AssertItoa(0, "0"));
	MRTEST(AssertItoa(1, "1"));
	MRTEST(AssertItoa(-1, "-1"));
	MRTEST(AssertItoa(-724398234, "-724398234"));
	MRTEST(AssertItoa(2147483647, "2147483647"));
	MRTEST(AssertItoa(-2147483648, "-2147483648"));
}
