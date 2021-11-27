#include "mrtest_libft.h"
#include <string.h>
#include <stdbool.h>

static bool compareStrrchr(const char* x, int c) {
	return strrchr(x, c) == ft_strrchr(x, c);
}

TEST_CASE("strrchr", "strrchr") {
	MRTEST(compareStrrchr("abc", '\0'));
	MRTEST(compareStrrchr("abc", 'a'));
	MRTEST(compareStrrchr("abc", 'b'));
	MRTEST(compareStrrchr("abc", 'c'));
	MRTEST(compareStrrchr("abc", 'd'));
	MRTEST(compareStrrchr("", '\0'));
	MRTEST(compareStrrchr("", 'x'));
	MRTEST(compareStrrchr("xxxxxxxxxx", 'x'));
	MRTEST(compareStrrchr("1234567890x1234567890x", 'x'));
}
