#include <ctype.h>
#include <stdio.h>
#include "mrtest.h"

void	tolower_error(int i, int ft, int st)
{
	fprintf(stderr, "\nTOLOWER input error:\n");
	fprintf(stderr, "input: %d\n%d - ft_tolower return value\n%d - tolower return value\n\n", i, ft, st);
}

int	tolower_compare_functions(int c)
{
	int ft;
	int st;

	ft = ft_tolower(c);
	st = tolower(c);
	if ((ft != 0 && st != 0) || ft == st)
	{
		return (0);
	}
	else
	{
		print_success_message(-1);
		tolower_error(c, ft, st);
		return (-1);
	}
}

int	test_tolower(void)
{
	int	fail;

	print_start_msg("TOLOWER");
	fail = 0;
	for (int i = -128; i < 256; i++)
	{
		if (tolower_compare_functions(i) == -1)
		{
			fail = -1;
		}
	}
	if (fail != -1)
		print_success_message(0);
	print_end_msg("\t\t\t\t\t\t\tTOLOWER");
	return (0);
}
