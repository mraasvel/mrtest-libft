#include "mrtest_libft.h"
#include <string.h>
#include <stdbool.h>

static bool compareStrchr(const char* x, int c) {
	return strchr(x, c) == ft_strchr(x, c);
}

TEST_CASE("strchr", "strchr") {
	MRTEST(compareStrchr("abc", '\0'));
	MRTEST(compareStrchr("abc", 'a'));
	MRTEST(compareStrchr("abc", 'b'));
	MRTEST(compareStrchr("abc", 'c'));
	MRTEST(compareStrchr("abc", 'd'));
	MRTEST(compareStrchr("", '\0'));
	MRTEST(compareStrchr("", 'x'));
	MRTEST(compareStrchr("xxxxxxxxxx", 'x'));
	MRTEST(compareStrchr("1234567890x1234567890x", 'x'));
}
