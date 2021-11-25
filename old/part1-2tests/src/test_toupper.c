#include <ctype.h>
#include <stdio.h>
#include "mrtest.h"

void	toupper_error(int i, int ft, int st)
{
	fprintf(stderr, "\nTOUPPER input error:\n");
	fprintf(stderr, "input: %d\n%d - ft_toupper return value\n%d - toupper return value\n\n", i, ft, st);
}

int	toupper_compare_functions(int c)
{
	int ft;
	int st;

	ft = ft_toupper(c);
	st = toupper(c);
	if ((ft != 0 && st != 0) || ft == st)
	{
		return (0);
	}
	else
	{
		print_success_message(-1);
		toupper_error(c, ft, st);
		return (-1);
	}
}

int	test_toupper(void)
{
	int	fail;

	print_start_msg("TOUPPER");
	fail = 0;
	for (int i = -128; i < 256; i++)
	{
		if (toupper_compare_functions(i) == -1)
		{
			fail = -1;
			break ;
		}
	}
	if (fail != -1)
		print_success_message(0);
	print_end_msg("\t\t\t\t\t\t\tTOUPPER");
	return (0);
}
