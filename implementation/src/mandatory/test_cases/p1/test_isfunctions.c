#include "mrtest_libft.h"
#include <ctype.h>
#include <stdbool.h>

typedef int (*IsFunctionType)(int);

static bool CompareIsFunctions(IsFunctionType original, IsFunctionType ft_version) {
	for (int i = -127; i < 255; ++i) {
		// as long as both return non-zero or zero it's considered correct
		if (!original(i) != !ft_version(i)) {
			return false;
		}
	}

	return true;
}

TEST_CASE("ft_isfunctions", "ft_isfunctions") {
	MRTEST(CompareIsFunctions(isalnum, ft_isalnum));
}

TEST_CASE("ft_isfunctions", "ft_isfunctions") {
	MRTEST(CompareIsFunctions(isalpha, isalpha));
}

TEST_CASE("ft_isfunctions", "ft_isfunctions") {
	MRTEST(CompareIsFunctions(isascii, isascii));
}

TEST_CASE("ft_isfunctions", "ft_isfunctions") {
	MRTEST(CompareIsFunctions(isdigit, isdigit));
}

TEST_CASE("ft_isfunctions", "ft_isfunctions") {
	MRTEST(CompareIsFunctions(isprint, isprint));
}

TEST_CASE("ft_isfunctions", "ft_isfunctions") {
	MRTEST(CompareIsFunctions(toupper, toupper));
}

TEST_CASE("ft_isfunctions", "ft_isfunctions") {
	MRTEST(CompareIsFunctions(tolower, tolower));
}
