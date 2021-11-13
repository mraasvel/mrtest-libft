#include "libft.h"
#include "mrtest.h"
#include <stdlib.h>

TEST_CASE(TestAtoi, atoi) {
	MRTEST(ft_atoi("1") == atoi("1"));
	MRTEST(ft_atoi("-1") == atoi("-1"));
	MRTEST(ft_atoi("  1") == atoi("  1"));
	MRTEST(ft_atoi("   +1") == atoi("   +1"));
	MRTEST(ft_atoi("0") == atoi("0"));
	MRTEST(ft_atoi("+0") == atoi("+0"));
	MRTEST(ft_atoi("-0") == atoi("-0"));
	MRTEST(ft_atoi("100") == atoi("100"));
	MRTEST(ft_atoi("2147483647") == atoi("2147483647"));
	MRTEST(ft_atoi("-2147483648") == atoi("-2147483648"));
	MRTEST(ft_atoi("\r\n\t \v\f    -1234") == atoi("\r\n\t \v\f    -1234"));
}
