#include <stdlib.h>
#include <stdio.h>
#include "mrtest.h"

void	atoi_error(char const *nptr, int ft_ret, int st_ret)
{
	fprintf(stderr, "\nATOI input error:\n");
	fprintf(stderr, "input str: \"%s\"\n", nptr);
	fprintf(stderr, "%d - ft_atoi return value\n%d - atoi return value\n\n", ft_ret, st_ret);
}

int	atoi_compare_functions(char const *nptr)
{
	int	ft_ret;
	int	st_ret;

	ft_ret = ft_atoi(nptr);
	st_ret = atoi(nptr);
	if (ft_ret == st_ret)
	{
		print_success_message(0);
		return (0);
	}
	else
	{
		print_success_message(-1);
		atoi_error(nptr, ft_ret, st_ret);
		return (-1);
	}
	
}

int	test_atoi(void)
{
	print_start_msg("ATOI");
	atoi_compare_functions("0");
	atoi_compare_functions("");
	atoi_compare_functions("asiduc1234");
	atoi_compare_functions("\t\r\t\n \v\f1234");
	atoi_compare_functions("\t\r\t\n \v\f+1234");
	atoi_compare_functions("+++++1234");
	atoi_compare_functions("+-1234");
	atoi_compare_functions("-1234");
	atoi_compare_functions("1234");
	atoi_compare_functions("4294967295");
	atoi_compare_functions("-2147483648");
	atoi_compare_functions("2147483647");
	atoi_compare_functions("-9223372036854775808");
	atoi_compare_functions("18446744073709551615");
	// Over max long value (undefined behavior: moulinette doesn't check this)
	// atoi_compare_functions("-9223372036854775809");
	// atoi_compare_functions("9223372036854779999");
	// atoi_compare_functions("1844674407370955199999");
	// atoi_compare_functions("-1844674407370955199999");
	print_end_msg("ATOI");
	return (0);
}
