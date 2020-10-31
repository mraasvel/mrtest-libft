#include <stdio.h>
#include <string.h>
#include "mrtest.h"

void	memchr_error(const char *src, int c, size_t n, char *f, char *s)
{
	fprintf(stderr, "\nMEMCHR input error:\n");
	fprintf(stderr, "s = ft_memchr(\"%s\", '%c', %ld);\n", src, c, n);
	fprintf(stderr, "ft_memchr return address: %p\nst_memchr return address: %p\n", f, s);
}

int	memchr_compare_functions(const char *src, int c, size_t n)
{
	char	*f;
	char	*s;

	f = memchr(src, c, n);
	s = ft_memchr(src, c, n);
	if (f == s)
	{
		print_success_message(0);
		return (0);
	}
	else
	{
		print_success_message(-1);
		memchr_error(src, c, n, f, s);
		return (-1);
	}
}

int	test_memchr(void)
{
	print_start_msg("MEMCHR");
	memchr_compare_functions("", 'a', 0);
	memchr_compare_functions("1234567890", 'a', 10);
	memchr_compare_functions("1234567890", '0', 10);
	memchr_compare_functions("1234567890", '9', 10);
	memchr_compare_functions("", 'a', 1);
	memchr_compare_functions("", 0, 1);
	print_end_msg("MEMCHR");
	return (0);
}
