#ifdef __APPLE__

#include "mrtest_libft.h"
#include <string.h>
#include <stdbool.h>

static bool strnstrCompare(const char* big, const char* little, size_t n) {
	return strnstr(big, little, n) == ft_strnstr(big, little, n);
}

TEST_CASE("strnstr", "strnstr") {
	strnstrCompare("abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcd", "abcd", 1024);
	strnstrCompare("", "abcd", 1024);
	strnstrCompare("123456789012354671823094-1=3212038471234", "abcd", 1024);
	strnstrCompare("123456789012354671823094-1=3212038471234", "", 1024);
	strnstrCompare("123456789012354671823094-1=3212038471234", "asoidfj", 0);
	strnstrCompare("abc", "abcd", 1024);
	strnstrCompare("abcd", "abcd", 1024);
	strnstrCompare("abcd", "abcd", 3);
	strnstrCompare("ababat", "abat", 1000);
	strnstrCompare("abcde", "1234", 1024);
}

#endif /* __APPLE__ */
