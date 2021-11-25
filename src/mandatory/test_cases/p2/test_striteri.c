#include "mrtest_libft.h"
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

static void evenToUpper(unsigned int index, char* c) {
	assert(c);
	*c = index % 2 == 0 ? toupper(*c) : *c;
}

static void evenToLower(unsigned int index, char* c) {
	assert(c);
	*c = index % 2 == 0 ? tolower(*c) : *c;
}

static bool striteriCompare(const char* s, void (*f)(unsigned int, char*), const char* exp) {
	char* copy = strdup(s);
	if (copy == NULL) {
		exitPerror("strdup");
	}

	ft_striteri(copy, f);

	const bool result = strcmp(copy, exp) == 0;
	free(copy);
	return result;
}

TEST_CASE("striteri", "striteri") {
	MRTEST(striteriCompare("1234", &evenToLower, "1234"));
	MRTEST(striteriCompare("abcd", &evenToUpper, "AbCd"));
	MRTEST(striteriCompare("ABCD", &evenToLower, "aBcD"));
}
