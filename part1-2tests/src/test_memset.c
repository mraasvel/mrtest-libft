#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mrtest.h"

static void	free_pointers(char *a, char *b)
{
	if (a != 0)
		free(a);
	if (b != 0)
		free(b);
}

void	memset_print_error(int c, size_t n)
{
	fprintf(stderr, "\nMEMSET: Input that gave error:\n\tint c = '%c' (ASCII: %d)\n\tsize_t n = %ld\n", c, c, n);
}

int	memset_compare_functions(int c, size_t n)
{
	char	*st;
	char	*ft;

	st = (char*)malloc(n * sizeof(char));
	ft = (char*)malloc(n * sizeof(char));
	memset(st, c, n);
	ft_memset(ft, c, n);
	if (!memcmp(st, ft , n))
	{	
		print_success_message(0);
		free_pointers(st, ft);
		return (0);
	}
	else
	{
		print_success_message(-1);
		memset_print_error(c, n);
		free_pointers(st, ft);
		return (-1);
	}
}

int	test_memset(void)
{
	print_start_msg("MEMSET");
	memset_compare_functions(0, 1024);
	memset_compare_functions('A', 1024);
	memset_compare_functions(900, 1024);
	memset_compare_functions(10, 128 * 1024 * 1024);
	memset_compare_functions(100, 0);
	print_end_msg("\t\t\t\t\tMEMSET");
	return (0);
}
