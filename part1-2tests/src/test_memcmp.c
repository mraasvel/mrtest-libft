#include <stdio.h>
#include <string.h>
#include "mrtest.h"

void	memcmp_error(const char *s1, const char *s2, size_t n, int f, int s)
{
	fprintf(stderr, "\nMEMCMP input error:\n");
	fprintf(stderr, "s1: %s\ns2: %s\nn: %ld\nft_memcmp ret: %d\nst_memcmp ret: %d\n\n", s1, s2, n, f, s);
}

int	memcmp_compare_functions(const char *s1, const char *s2, size_t n)
{
	int	f;
	int	s;

	s = memcmp(s1, s2, n);
	f = ft_memcmp(s1, s2, n);
	if (s == f || (s < 0 && f < 0) || (s > 0 && f > 0))
	{
		print_success_message(0);
		return (0);
	}
	else
	{
		print_success_message(-1);
		memcmp_error(s1, s2, n, f, s);
		return (-1);
	}
	
}

int	test_memcmp(void)
{
	print_start_msg("MEMCMP");
	memcmp_compare_functions("1234567890", "1234567890", 10);
	memcmp_compare_functions("1234567890", "123456789", 10);
	memcmp_compare_functions("1234567890", "123456789", 9);
	memcmp_compare_functions("123456789", "1234567890", 9);
	memcmp_compare_functions("1234567890", "123456789a", 10);
	memcmp_compare_functions("1234z67890", "123456789a", 10);
	memcmp_compare_functions("", "", 1);
	print_end_msg("MEMCMP");
	return (0);
}
