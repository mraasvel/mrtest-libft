#include <ctype.h>
#include <stdio.h>
#include "mrtest.h"

void	isprint_error(int i, int ft, int st)
{
	fprintf(stderr, "\nISPRINT input error:\n");
	fprintf(stderr, "input: %d\n%d - ft_isprint return value\n%d - isprint return value\n\n", i, ft, st);
}

int	isprint_compare_functions(int c)
{
	int ft;
	int st;

	ft = ft_isprint(c);
	st = isprint(c);
	if (ft == st || (ft != 0 && st != 0))
	{
		return (0);
	}
	else
	{
		print_success_message(-1);
		isprint_error(c, ft, st);
		return (-1);
	}
}

int	test_isprint(void)
{
	int	fail;

	print_start_msg("ISPRINT");
	fail = 0;
	for (int i = -128; i < 256; i++)
	{
		if (isprint_compare_functions(i) == -1)
		{
			fail = -1;
			break ;
		}
	}
	if (fail != -1)
		print_success_message(0);
	print_end_msg("\t\t\t\t\t\t\tISPRINT");
	return (0);
}
