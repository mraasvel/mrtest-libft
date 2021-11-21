#include "mrtest.h"
#include "libft.h"
#include <string.h>

TEST_CASE("Memmove Backward Copy", "memmove") {
	char st_dest[15] = "0123456789";
	char ft_dest[15] = "0123456789";

	MRTEST(memmove(&st_dest[1], st_dest, 9) == &st_dest[1]);
	MRTEST(ft_memmove(&ft_dest[1], ft_dest, 9) == &ft_dest[1]);
	MRTEST(strcmp(st_dest, ft_dest) == 0);
}

TEST_CASE("Memmove Forward Copy", "memmove") {
	char st_dest[15] = "0123456789";
	char ft_dest[15] = "0123456789";

	MRTEST(memmove(st_dest, &st_dest[1], 9) == &st_dest[0]);
	MRTEST(ft_memmove(ft_dest, &ft_dest[1], 9) == &ft_dest[0]);
	MRTEST(strcmp(st_dest, ft_dest) == 0);
}
