#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mrtest.h"

void	substr_error(char const *s, char const *expected, char *ft)
{
	fprintf(stderr, "\nSUBSTR error:\n");
	fprintf(stderr, "%s - input string\n%s - expected string\n%s - ft_substr return\n\n", s, expected, ft);
}

int	substr_compare_function(char const *s, unsigned int start, size_t len, char const *expected)
{
	char	*ft;

	ft = ft_substr(s, start, len);
	if (ft == 0)
	{
		fprintf(stderr, "\nft_substr returned \"NULL\"");
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
		substr_error(s, expected, ft);
		free(ft);
		return (-1);
	}
	
}

int	test_substr(void)
{
	print_start_msg("SUBSTR");
	substr_compare_function("1234567890", 5, 10, "67890");
	substr_compare_function("1234567890", 5, 5, "67890");
	substr_compare_function("1234567890", 12, 10, "");
	substr_compare_function("1234567890", 5000, 10, "");
	substr_compare_function("1234567890", 0, 10, "1234567890");
	substr_compare_function("1234567890ofdsiaoijafsd", 0, 500, "1234567890ofdsiaoijafsd");
	substr_compare_function("", 0, 500, "");
	substr_compare_function("", 50, 500, "");
	print_end_msg("\t\t\tSUBSTR");
	return (0);
}
