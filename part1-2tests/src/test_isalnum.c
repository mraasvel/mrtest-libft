#include <ctype.h>
#include <stdio.h>
#include "mrtest.h"

void	isalnum_error(int i, int ft, int st)
{
	fprintf(stderr, "\nISALNUM input error:\n");
	fprintf(stderr, "input: %d\n%d - ft_isalnum return value\n%d - isalnum return value\n\n", i, ft, st);
}

int	isalnum_compare_functions(int c)
{
	int ft;
	int st;

	ft = ft_isalnum(c);
	st = isalnum(c);
	if (ft == st || (ft != 0 && st != 0))
	{
		return (0);
	}
	else
	{
		print_success_message(-1);
		isalnum_error(c, ft, st);
		return (-1);
	}
}

int	test_isalnum(void)
{
	int	fail;

	print_start_msg("ISALNUM");
	fail = 0;
	for (int i = -128; i < 256; i++)
	{
		if (isalnum_compare_functions(i) == -1)
		{
			fail = -1;
			break ;
		}
	}
	if (fail != -1)
		print_success_message(0);
	print_end_msg("\t\t\t\t\t\t\tISALNUM");
	return (0);
}
