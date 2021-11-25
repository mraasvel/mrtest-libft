#include <ctype.h>
#include <stdio.h>
#include "mrtest.h"

void	isdigit_error(int i, int ft, int st)
{
	fprintf(stderr, "\nISDIGIT input error:\n");
	fprintf(stderr, "input: %d\n%d - ft_isdigit return value\n%d - isdigit return value\n\n", i, ft, st);
}

int	isdigit_compare_functions(int c)
{
	int ft;
	int st;

	ft = ft_isdigit(c);
	st = isdigit(c);
	if (ft == st || (ft != 0 && st != 0))
	{
		return (0);
	}
	else
	{
		print_success_message(-1);
		isdigit_error(c, ft, st);
		return (-1);
	}
}

int	test_isdigit(void)
{
	int	fail;

	print_start_msg("ISDIGIT");
	fail = 0;
	for (int i = -128; i < 256; i++)
	{
		if (isdigit_compare_functions(i) == -1)
		{
			fail = -1;
			break ;
		}
	}
	if (fail != -1)
		print_success_message(0);
	print_end_msg("\t\t\t\t\t\t\tISDIGIT");
	return (0);
}
