#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mrtest.h"

static void	free_ptrs(char *a, char *b, char *c)
{
	if (a != 0)
		free(a);
	if (b != 0)
		free(b);
	if (c != 0)
		free(c);
}

void	memccpy_error(char *f, char *s, int c, size_t  n)
{
	fprintf(stderr, "\nMEMCCPY input that gave error:\n");
	fprintf(stderr, "int c = %d\nsize_t n = %ld\n", c, n);
	if (n < 50)
		print_bytes(f, n);
	fprintf(stderr, " - f: %p\n", f);
	if (n < 50)
		print_bytes(s, n);
	fprintf(stderr, " - s: %p\n", s);
}

int	memccpy_compare_functions(int c, size_t n)
{
	char	*f;
	char	*s;
	char	*src;

	s = (char*)malloc(n * sizeof(char));
	f = (char*)malloc(n * sizeof(char));
	src = (char*)malloc(n * sizeof(char));
	if (f == 0 || s == 0 || src == 0)
	{
		free_ptrs(f, s, src);
		return (1);
	}
	src = memset(src, c - 1, n);
	src[n - 1] = c;
	memccpy(s, src, c, n);
	ft_memccpy(f, src, c, n);
	if (memcmp(f, s, n) == 0)
	{
		print_success_message(0);
		free_ptrs(f, s, src);
		return (0);
	}
	else
	{
		print_success_message(-1);
		memccpy_error(f, s, c, n);
		free_ptrs(f, s, src);
		return (0);
	}
	
}

int	test_memccpy(void)
{
	print_start_msg("MEMCCPY");
	memccpy_compare_functions(0, 0);
	memccpy_compare_functions('1', 0);
	memccpy_compare_functions('1', 1);
	memccpy_compare_functions('1', 1024 * 1024 * 128);
	print_end_msg("MEMCCPY");
	return (0);
}