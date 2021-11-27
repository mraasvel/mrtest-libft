#ifdef __APPLE__

#include "mrtest_libft.h"
#include <string.h>
#include <stdbool.h>

static bool strnstrCompare(const char* big, const char* little, size_t n) {
	return strnstr(big, little, n) == ft_strnstr(big, little, n);
}

TEST_CASE("ft_strnstr", "ft_strnstr") {
	MRTEST(strnstrCompare("abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcd", "abcd", 1024));
	MRTEST(strnstrCompare("", "abcd", 1024));
	MRTEST(strnstrCompare("123456789012354671823094-1=3212038471234", "abcd", 1024));
	MRTEST(strnstrCompare("123456789012354671823094-1=3212038471234", "", 1024));
	MRTEST(strnstrCompare("123456789012354671823094-1=3212038471234", "asoidfj", 0));
	MRTEST(strnstrCompare("abc", "abcd", 1024));
	MRTEST(strnstrCompare("abcd", "abcd", 1024));
	MRTEST(strnstrCompare("abcd", "abcd", 3));
	MRTEST(strnstrCompare("ababat", "abat", 1000));
	MRTEST(strnstrCompare("abcde", "1234", 1024));
}

#endif /* __APPLE__ */
