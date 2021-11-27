#include "mrtest_libft.h"
#include <string.h>

TEST_CASE("Memcpy Test", "memcpy") {
	char st_dst[15] = "";
	char ft_dst[15] = "";
	char src[] = "Hello, There";

	MRTEST(memcpy(st_dst, src, sizeof(src)) == &(st_dst[0]));
	MRTEST(ft_memcpy(ft_dst, src, sizeof(src)) == &(ft_dst[0]));
	MRTEST(strcmp(ft_dst, st_dst) == 0);
}

TEST_CASE("Memcpy No Copy", "memcpy") {
	char x[10];

	memset(x, 42, sizeof(x));

	ft_memcpy(x, "", 0);
	for (size_t i = 0; i < sizeof(x); ++i) {
		MRTEST(x[i] == 42);
	}
}
