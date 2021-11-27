#include "mrtest_libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

static bool stringsEqual(const char* const* x, const char* const* y) {
	size_t i = 0;
	while (x[i] != NULL && y[i] != NULL) {
		if (strcmp(x[i], y[i]) != 0) {
			return false;
		}
		++i;
	}

	return x[i] == y[i];
}

static void freeStrings(char** x) {
	for (size_t i = 0; x[i] != NULL; ++i) {
		free(x[i]);
	}
	free(x);
}

static bool splitCompare(const char* s, char delim, char** expected) {
	char** x = ft_split(s, delim);

	if (x == NULL) {
		fprintf(stderr, "%s:%d [ft_split(\"%s\", %c);]: returned NULL\n",
			__FILE__, __LINE__,
			s, delim);
		exit(EXIT_FAILURE);
	}

	const bool result = stringsEqual((const char* const*) x, (const char* const*)expected);
	freeStrings(x);
	freeStrings((char**)expected);
	return result;
}

static char** createStrings(size_t n, ...) {
	char** x = calloc(n + 1, sizeof(char*));
	if (x == NULL) {
		exitPerror("malloc");
	}

	va_list ap;

	va_start(ap, n);
	for (size_t i = 0; i < n; ++i) {
		char* y = va_arg(ap, char*);
		x[i] = strdup(y);
		if (x[i] == NULL) {
			exitPerror("strdup");
		}
	}
	va_end(ap);
	return x;
}

TEST_CASE("split", "split") {
	MRTEST(splitCompare("aaaaaaaaaaaaaaaaa", 'a', createStrings(0)));
	MRTEST(splitCompare("a b c d e f g", ' ', createStrings(7, "a", "b", "c", "d", "e", "f", "g")));
	MRTEST(splitCompare("a b1234 c dasdfij\t    aosdfjas\ndfe       fasdoifj gaosdifjaoisdjf", ' ',
		createStrings(7, "a", "b1234", "c", "dasdfij\t", "aosdfjas\ndfe", "fasdoifj", "gaosdifjaoisdjf")));
	MRTEST(splitCompare("132sdfasdjfjasdoicjaosidjcoaisdjf02u13  0asdf09asd f0 f09 iasd09fi asd0f", '\t',
		createStrings(1, "132sdfasdjfjasdoicjaosidjcoaisdjf02u13  0asdf09asd f0 f09 iasd09fi asd0f")));
	MRTEST(splitCompare("", ' ', createStrings(0)));
	MRTEST(splitCompare("aaaaaaaaaaaaaaaaab", 'a', createStrings(1, "b")));
	MRTEST(splitCompare("baaaaaaaaaaaaaaaaa", 'a', createStrings(1, "b")));
	MRTEST(splitCompare("aaaaaaaaabaaaaaaaa", 'a', createStrings(1, "b")));
	MRTEST(splitCompare("1234", '\0', createStrings(1, "1234")));
	MRTEST(splitCompare("a", 'a', createStrings(0)));
	MRTEST(splitCompare("b", 'a', createStrings(1, "b")));
	MRTEST(splitCompare("ba", 'a', createStrings(1, "b")));
	MRTEST(splitCompare("ab", 'a', createStrings(1, "b")));
	MRTEST(splitCompare("bab", 'a', createStrings(2, "b", "b")));
	MRTEST(splitCompare("bab", 'a', createStrings(2, "b", "b")));
}
