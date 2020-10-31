#include <ctype.h>
#include <stdio.h>
#include "mrtest.h"

void	isascii_error(int i, int ft, int st)
{
	fprintf(stderr, "\nISASCII input error:\n");
	fprintf(stderr, "input: %d\n%d - ft_isascii return value\n%d - isascii return value\n\n", i, ft, st);
}

int	isascii_compare_functions(int c)
{
	int ft;
	int st;

	ft = ft_isascii(c);
	st = isascii(c);
	if (ft == st || (ft != 0 && st != 0))
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

int	test_isascii(void)
{
	int	fail;

	print_start_msg("ISASCII");
	fail = 0;
	for (int i = 0; i <= 256; i++)
	{
		if (isascii_compare_functions(i) == -1)
		{
			fail = -1;
		}
	}
	if (fail == -1)
	{
		fprintf(stderr, "[KO]");
		print_success_message(-1);
	}
	else
		print_success_message(0);
	print_end_msg("ISASCII");
	return (0);
}
