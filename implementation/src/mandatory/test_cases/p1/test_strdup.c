#include "mrtest_libft.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>

static bool strdupCompare(const char* x) {
	char* st = strdup(x);
	char* ft = ft_strdup(x);

	if (!ft || !st) {
		fprintf(stderr, "%s:%d [%s]: %s\n", __FILE__, __LINE__, __FUNCTION__, strerror(errno));
		exit(EXIT_FAILURE);
	}
	int result = strcmp(st, ft);

	free(st);
	free(ft);
	return result == 0;
}

TEST_CASE("strdup", "strdup") {
	MRTEST(strdupCompare("1"));
	MRTEST(strdupCompare(""));
	MRTEST(strdupCompare("1234567890"));
	MRTEST(strdupCompare("12345\012345"));
	MRTEST(strdupCompare("ad9fuanjdsadcaisdcadcscdsaidcasiuhcdsaiuhdsaciuhdsaciuhadsciuhasdiua\t\nsdc"));
}
