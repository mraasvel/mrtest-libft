#include <stdio.h>
#include <string.h>
#include "mrtest.h"

void	strnstr_error(const char *big, const char *little, size_t len, char *ft_ret, char *st_ret)
{
	fprintf(stderr, "\nSTRNSTR input error:\n");
	fprintf(stderr, "big string: \"%s\"\nlittle string: \"%s\"\nlen: %ld\n", big, little, len);
	fprintf(stderr, "%p - ft_strncmp return value\n%p - strncmp return value\n\n", ft_ret, st_ret);
}

int	strnstr_compare_functions(const char *big, const char *little, size_t len)
{
	char	*ft_ret;
	char	*st_ret;

	ft_ret = ft_strnstr(big, little, len);
	st_ret = strnstr(big, little, len);
	if (ft_ret == st_ret)
	{
		print_success_message(0);
		return (0);
	}
	else
	{
		print_success_message(-1);
		strnstr_error(big, little, len, ft_ret, st_ret);
		return (-1);
	}
	
}

int	test_strnstr(void)
{
	print_start_msg("STRNSTR");
	strnstr_compare_functions("abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcd", "abcd", 1024);
	strnstr_compare_functions("", "abcd", 1024);
	strnstr_compare_functions("123456789012354671823094-1=3212038471234", "abcd", 1024);
	strnstr_compare_functions("123456789012354671823094-1=3212038471234", "", 1024);
	strnstr_compare_functions("123456789012354671823094-1=3212038471234", "asoidfj", 0);
	strnstr_compare_functions("abc", "abcd", 1024);
	strnstr_compare_functions("abcd", "abcd", 1024);
	strnstr_compare_functions("abcd", "abcd", 3);
	strnstr_compare_functions("ababat", "abat", 1000);
	print_end_msg("\t\t\tSTRNSTR");
	return (0);
}
