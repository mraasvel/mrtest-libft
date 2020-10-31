#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mrtest.h"

static void	free_ptrs(char *a, char *b)
{
	if (a != 0)
		free(a);
	if (b != 0)
		free(b);
}

void	bzero_print_error(size_t n)
{
	fprintf(stderr, "\nBZER: Input that gave error:\nsize_t n = %ld\n", n);
}

int	bzero_compare_functions(size_t n)
{
	char	*f;
	char	*s;

	f = (char*)malloc(n * sizeof(char));
	s = (char*)malloc(n * sizeof(char));
	if (s == 0|| f == 0)
	{
		free_ptrs(f, s);
		return (1);
	}
	ft_bzero(f, n);
	bzero(s, n);
	if (!memcmp(f, s, n))
	{
		free_ptrs(f, s);
		print_success_message(0);
		return (0);
	}
	else
	{
		bzero_print_error(n);
		free_ptrs(f, s);
		print_success_message(-1);
		return (-1);
	}
}

int		test_bzero(void)
{
	print_start_msg("BZERO");
	bzero_compare_functions(1);
	bzero_compare_functions(16711568);
	bzero_compare_functions(128 * 1024 * 1024);
	bzero_compare_functions(0);
	print_end_msg("BZERO");
	return (0);
}
