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

char	*memmove_get_src(int c, size_t n)
{
	char	*src;

	src = (char*)malloc(n * sizeof(char));
	if (src == 0)
		return (0);
	memset(src, c, n);
	return (src);
}

void	memmove_error(char *f, char *s, char *src, int c, size_t n)
{
	fprintf(stderr, "\nMEMMOVE input that gave error:\nc = %d\nn = %ld\nsrc = memset(src, %d, %ld)\n", c, n, c, n);
	if (n < 50)
	{
		print_bytes(src, n);
		fprintf(stderr, " - src bytes\n");
		print_bytes(s, n);
		fprintf(stderr, " - memmove bytes\n");
		print_bytes(f, n);
		fprintf(stderr, " - ft_memmove bytes\n");
	}
}

int	memmove_compare_functions(int c, size_t n)
{
	char	*f;
	char	*s;
	char	*src;

	f = (char*)malloc(n * sizeof(char));
	s = (char*)malloc(n * sizeof(char));
	src = memmove_get_src(c, n);
	if (f == 0 || s == 0 || src == 0)
	{
		free_ptrs(f, s, src);
		return (1);
	}
	f = ft_memmove(f, src, n);
	s = memmove(s, src, n);
	if (!memcmp(f, s, n))
	{
		print_success_message(0);
		free_ptrs(f, s, src);
		return (0);
	}
	else
	{
		memmove_error(f, s, src, c, n);
		print_success_message(-1);
		free_ptrs(f, s, src);
		return (-1);
	}
}

int	memmove_test_overlapping_area()
{
	char	string[] = "1234567890";
	char	*one = string;
	char	expected[] = "1212345690";

	ft_memmove(one+2, one, 6);
	if (strcmp(one, expected) == 0)
	{
		print_success_message(0);
		return (0);
	}
	else
	{
		print_success_message(-1);
		fprintf(stderr, "\nMEMMOVE input error:\n");
		fprintf(stderr, "\tchar\tstring[] = \"1234567890\";\n\tchar\t*one = string;\n\tchar\texpected[] = \"1212345690\";\n\tft_memmove(one+2, one, 6);\n");
		fprintf(stderr, "exp: %s\none: %s\n\n", expected, one);
		return (-1);
	}
	return (0);
}

int	test_memmove(void)
{
	print_start_msg("MEMMOVE");
	memmove_compare_functions(0, 1024);
	memmove_compare_functions(50, 20);
	memmove_compare_functions(900, 49);
	memmove_compare_functions(1, 1024 * 1024 * 128);
	memmove_compare_functions('a', 1024);
	memmove_compare_functions('b', 1024);
	memmove_test_overlapping_area();
	print_end_msg("\t\t\t\tMEMMOVE");
	return (0);
}
