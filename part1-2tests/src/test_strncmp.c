#include <stdio.h>
#include <string.h>
#include "mrtest.h"

void	strncmp_error(char *s1, char *s2, size_t n, int ret, int ft_ret)
{
	fprintf(stderr, "\nFT_STRNCMP input error:\n");
	fprintf(stderr, "input:\n|%s| - s1\n|%s| - s2\n|%ld| - n\n", s1, s2, n);
	fprintf(stderr, "strncmp: |%d| ft_strncmp: |%d|\n\n", ret, ft_ret);
}

int	strncmp_compare_function(char *s1, char *s2, size_t n)
{
	int ret;
	int ft_ret;

	ret = strncmp(s1, s2, n);
	ft_ret = ft_strncmp(s1, s2, n);
	if (ret == ft_ret || (ret < 0 && ft_ret < 0) || (ret > 0 && ft_ret > 0))
	{
		print_success_message(0);
		return (0);
	}
	else
	{
		print_success_message(-1);
		strncmp_error(s1, s2, n, ret, ft_ret);
		return (-1);
	}
}

int	test_strncmp(void)
{
	print_start_msg("STRNCMP");
	strncmp_compare_function("1234567890", "1234567890", 5);
	strncmp_compare_function("1234567890", "123456789a", 10);
	strncmp_compare_function("1234567890", "1234567890", 0);
	strncmp_compare_function("1234567890", "123456789a", 5);
	strncmp_compare_function("1234567890", "123456789a", 100);
	strncmp_compare_function("1234567890a", "1234567890", 100);
	strncmp_compare_function("123456789a", "1234567890", 100);
	strncmp_compare_function("1234567890", "1234567890", 100);
	strncmp_compare_function("1", "", 100);
	strncmp_compare_function("", "1", 100);
	strncmp_compare_function("", "", 100);
	strncmp_compare_function("", "", 0);
	strncmp_compare_function("a", "", 0);
	strncmp_compare_function("", "a", 0);
	strncmp_compare_function("123", "abc", 0);
	print_end_msg("STRNCMP");
	return (0);
}
