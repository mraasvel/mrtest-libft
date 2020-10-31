#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mrtest.h"

void	itoa_error(int n, char *expected, char *ft)
{
	fprintf(stderr, "\nITOA error:\n");
	fprintf(stderr, "\"%d\" - input number\n\"%s\" - expected output string\n\"%s\" - ft_itoa output string\n\n", n, expected, ft);
}

int	itoa_compare_function(int n, char *expected)
{
	char	*ft;

	ft = ft_itoa(n);
	if (ft == 0)
	{
		fprintf(stderr, "\nFT_ITOA returned NULL pointer\n\n");
		return (1);
	}
	if (strcmp(ft, expected) == 0)
	{
		print_success_message(0);
		free(ft);
		return (0);
	}
	else
	{
		print_success_message(-1);
		itoa_error(n, expected, ft);
		free(ft);
		return (-1);
	}
}

int	test_itoa(void)
{
	print_start_msg("ITOA");
	itoa_compare_function(0, "0");
	itoa_compare_function(1, "1");
	itoa_compare_function(-1, "-1");
	itoa_compare_function(-724398234, "-724398234");
	// this gave error on mac
	// itoa_compare_function(4294967295, "-1");
	itoa_compare_function(2147483647, "2147483647");
	itoa_compare_function(-2147483648, "-2147483648");
	print_end_msg("ITOA");
	return (0);
}
