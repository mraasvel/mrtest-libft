#include <stdio.h>
#include "mrtest.h"

void	strchr_error(const char *s, int c, char *ft, char *st)
{
	fprintf(stderr, "\nSTRCHR input error:\n");
	fprintf(stderr, "string searched: %s\nchar to find: '%c'(ASCII %d)\n", s, c, c);
	fprintf(stderr, "%p - ft_strchr address\n%p - strchr address\n", ft, st);
}

int	strchr_compare_functions(const char *s, int c)
{
	char	*ft;
	char	*st;

	ft = ft_strchr(s, c);
	st = strchr(s, c);
	if (ft == st)
	{
		print_success_message(0);
		return (0);
	}
	else
	{
		print_success_message(-1);
		strchr_error(s, c, ft, st);
		return (-1);
	}
	
}

int	test_strchr(void)
{
	print_start_msg("STRCHR");
	strchr_compare_functions("1234567890", '\0');
	strchr_compare_functions("1234567890", 'a');
	strchr_compare_functions("1234567890", '0');
	strchr_compare_functions("123456ads9hf9asdfasdfuhasdfiuasd\tiufaisdciasdciasdincainsdcniasd\tciunasiducnasiudcnaiusdncasdc78\t90", '\t');
	strchr_compare_functions("1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1", 'a');
	strchr_compare_functions("1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1", '1');
	strchr_compare_functions("", '\0');
	strchr_compare_functions("", '1');
	print_end_msg("\t\t\tSTRCHR");
	return (0);
}
