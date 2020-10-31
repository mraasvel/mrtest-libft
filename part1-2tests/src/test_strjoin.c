#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mrtest.h"

void	strjoin_error(char *s1, char *s2, const char *expected, char *ft)
{
	fprintf(stderr, "\nSTRJOIN input error:\n");
	fprintf(stderr, "\"%s\" - s1 input\n\"%s\" - s2 input\n", s1, s2);
	fprintf(stderr, "\"%s\" - expected return\n\"%s\" - ft_strjoin return\n\n", expected, ft);
}

int	strjoin_compare_functions(char *s1, char *s2, const char *expected)
{
	char	*ft;

	ft = ft_strjoin(s1, s2);
	if (ft == 0)
	{
		fprintf(stderr, "\nSTRJOIN returned NULL POINTER\n\n");
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
		strjoin_error(s1, s2, expected, ft);
		free(ft);
		return (-1);
	}
	
}

int	test_strjoin(void)
{
	print_start_msg("STRJOIN");
	strjoin_compare_functions("", "1234567890", "1234567890");
	strjoin_compare_functions("1234567890", "1234567890", "12345678901234567890");
	strjoin_compare_functions("1234567890", "", "1234567890");
	strjoin_compare_functions("12345\0 67890", "\t\0", "12345\t");
	strjoin_compare_functions("", "", "");
	print_end_msg("STRJOIN");
	return (0);
}
