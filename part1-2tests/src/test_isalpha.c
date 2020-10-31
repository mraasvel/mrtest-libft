#include <ctype.h>
#include <stdio.h>
#include "mrtest.h"

void	isalpha_error(int i, int ft, int st)
{
	fprintf(stderr, "\nISALPHA input error:\n");
	fprintf(stderr, "input: %d\n%d - ft_isalpha return value\n%d - isalpha return value\n\n", i, ft, st);
}

int	isalpha_compare_functions(int c)
{
	int ft;
	int st;

	ft = ft_isalpha(c);
	st = isalpha(c);
	if (ft == st || (ft != 0 && st != 0))
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

int	test_isalpha(void)
{
	int	fail;

	print_start_msg("ISALPHA");
	fail = 0;
	for (int i = 0; i <= 256; i++)
	{
		if (isalpha_compare_functions(i) == -1)
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
	print_end_msg("\t\t\t\t\t\t\tISALPHA");
	return (0);
}
