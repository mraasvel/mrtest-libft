#include <stdio.h>
#include "mrtest.h"

void	strrchr_error(const char *s, int c, char *ft, char *st)
{
	fprintf(stderr, "\nSTRRCHR input error:\n");
	fprintf(stderr, "string searched: %s\nchar to find: '%c'(ASCII %d)\n", s, c, c);
	fprintf(stderr, "%p - ft_strrchr address\n%p - strrchr address\n", ft, st);
}

int	strrchr_compare_functions(const char *s, int c)
{
	char	*ft;
	char	*st;

	ft = ft_strrchr(s, c);
	st = strrchr(s, c);
	if (ft == st)
	{
		print_success_message(0);
		return (0);
	}
	else
	{
		strrchr_error(s, c, ft, st);
		print_success_message(-1);
		return (-1);
	}
	
}

int	test_strrchr(void)
{
	print_start_msg("STRRCHR");
	strrchr_compare_functions("1234567890", '\0');
	strrchr_compare_functions("1234567890", 'a');
	strrchr_compare_functions("1234567890", '0');
	strrchr_compare_functions("123456ads9hf9asdfasdfuhasdfiuasd\tiufaisdciasdciasdincainsdcniasd\tciunasiducnasiudcnaiusdncasdc78\t90", '\t');
	strrchr_compare_functions("1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1", 'a');
	strrchr_compare_functions("1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1", '1');
	strrchr_compare_functions("1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1", 0);
	strrchr_compare_functions("1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", '1');
	strrchr_compare_functions("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1", '1');
	strrchr_compare_functions("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1", 'a');
	strrchr_compare_functions("aaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaa1", 'b');
	strrchr_compare_functions("", '\0');
	strrchr_compare_functions("", '1');
	print_end_msg("\t\t\tSTRRCHR");
	return (0);
}
