#include <stdio.h>
#include <stdlib.h>
#include "mrtest.h"

void	strtrim_error(char const *s1, char const *set, char const *expected, char *ft)
{
	fprintf(stderr, "\nSTRTRIM error:\n");
	fprintf(stderr, "\"%s\" - s1 input string\n\"%s\" - set input string\n", s1, set);
	print_bytes((char*)set, strlen(set));
	fprintf(stderr, " - set input string ASCII value\n");
	fprintf(stderr, "\"%s\" - expected output string\n\"%s\" - ft_strtrim return string\n\n", expected, ft);
}

int	strtrim_compare_functions(char const *s1, char const *set, char const *expected)
{
	char	*ft;

	ft = ft_strtrim(s1, set);
	if (ft == 0)
	{
		fprintf(stderr, "\nFT_STRTRIM returned a NULL pointer\n\n");
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
		strtrim_error(s1, set, expected, ft);
		free(ft);
		return (-1);
	}
	
}

int	test_strtrim(void)
{
	print_start_msg("STRTRIM");
	strtrim_compare_functions("\t\tn1234567890\t\t\n", "\n\t", "n1234567890");
	strtrim_compare_functions("\t\tn12345\t\t67890\t\t\n", "\n\t", "n12345\t\t67890");
	strtrim_compare_functions("", "123567890", "");
	strtrim_compare_functions("", "", "");
	strtrim_compare_functions("abc", "", "abc");
	strtrim_compare_functions("abcd123457890efgh", "123567890", "abcd123457890efgh");
	strtrim_compare_functions("baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac", "a", "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac");
	strtrim_compare_functions("abaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaca", "a", "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac");
	strtrim_compare_functions("aabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacaa", "a", "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac");
	strtrim_compare_functions("aabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacaa", "ab", "c");
	strtrim_compare_functions("aabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacaa", "abc", "");
	print_end_msg("STRTRIM");
	return (0);
}
