#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mrtest.h"

char	odd_toupper_else(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (tolower(c));
	return (toupper(c));
}

char	even_toupper_else(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (toupper(c));
	return (tolower(c));
}

void	strmapi_error(char const *s, char const *expected, char *ft)
{
	fprintf(stderr, "\nFT_STRMAPI error:\n");
	fprintf(stderr, "\"%s\" - input string\n\"%s\" - expected output\n\"%s\" - ft_strmapi return\n\n", s, expected, ft);
}

int	strmapi_compare_function(char const *s, char const *expected, char (*f)(unsigned int, char))
{
	char	*ft;

	ft = ft_strmapi(s, f);
	if (ft == 0)
	{
		fprintf(stderr, "\nFT_STRMAPI returned NULL pointer\n\n");
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
		strmapi_error(s, expected, ft);
		free(ft);
		return (-1);
	}
}

int	test_strmapi(void)
{
	print_start_msg("STRMAPI");
	strmapi_compare_function("1234567890", "1234567890", &odd_toupper_else);
	strmapi_compare_function("aaaaaaaaaaaaaaaaaaaaaa", "aAaAaAaAaAaAaAaAaAaAaA", &odd_toupper_else);
	strmapi_compare_function("aaaaaaaaaaaaaaaaaaaaaa", "AaAaAaAaAaAaAaAaAaAaAa", &even_toupper_else);
	strmapi_compare_function("", "", &even_toupper_else);
	strmapi_compare_function("Z", "Z", &even_toupper_else);
	strmapi_compare_function("ZZ", "Zz", &even_toupper_else);
	strmapi_compare_function("ZZ", "zZ", &odd_toupper_else);
	print_end_msg("STRMAPI");
	return (0);
}
