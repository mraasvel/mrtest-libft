#include "libft.h"
#include "mrtest.h"
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

TEST_CASE("IsAlnum", "isalnum") {
	CompareIsFunctions(isalnum, ft_isalnum);
}

TEST_CASE("IsAlpha", "isalpha") {
	CompareIsFunctions(isalpha, isalpha);
}

TEST_CASE("IsAscii", "isascii") {
	CompareIsFunctions(isascii, isascii);
}

TEST_CASE("IsDigit", "isdigit") {
	CompareIsFunctions(isdigit, isdigit);
}

TEST_CASE("IsPrint", "isprint") {
	CompareIsFunctions(isprint, isprint);
}

TEST_CASE("ToUpper", "toupper") {
	CompareIsFunctions(toupper, toupper);
}

TEST_CASE("ToLower", "tolower") {
	CompareIsFunctions(tolower, tolower);
}
