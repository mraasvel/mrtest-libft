#include <stdlib.h>
#include <stdio.h>
#include "mrtest.h"

static void	free_ptrs(char *a, char *b)
{
	if (a != 0)
		free(a);
	if (b != 0)
		free(b);
}

void	calloc_error(char *f, char *s, size_t nmemb, size_t size)
{
	fprintf(stderr, "\nCALLOC error:\n");
	fprintf(stderr, "%ld * %ld space was allocated\n", nmemb, size);
	fprintf(stderr, "%p - ft_calloc pointer\n%p - calloc pointer\nmemcmp return: non-zero\n\n", f, s);
	if (nmemb * size <= 50)
	{
		print_bytes(f, nmemb * size);
		fprintf(stderr, "- ft_calloc bytes\n");
		print_bytes(s, nmemb * size);
		fprintf(stderr, "- calloc bytes\n\n");
	}
}

int	calloc_compare_functions(size_t nmemb, size_t size)
{
	char	*f;
	char	*s;

	f = ft_calloc(nmemb, size);
	s = calloc(nmemb, size);
	if (f == 0 && s == 0)
	{
		print_success_message(0);
		free_ptrs(f, s);
		return (0);
	}
	if (f == 0 || s == 0)
	{
		print_success_message(-1);
		fprintf(stderr, "\nCalloc:\n%p - ft_calloc pointer\n%p - calloc pointer\n", f, s);
		free_ptrs(f, s);
		return (-1);
	}
	if (memcmp(f, s, size * nmemb) == 0)
	{
		print_success_message(0);
		free_ptrs(f, s);
		return (0);
	}
	else
	{
		free_ptrs(f, s);
		print_success_message(-1);
		calloc_error(f, s, nmemb, size);
		return (-1);
	}
	
}

int	test_calloc(void)
{
	print_start_msg("CALLOC");
	calloc_compare_functions(2349857, 1);
	calloc_compare_functions(50, 0);
	calloc_compare_functions(0, 50);
	calloc_compare_functions(1, 25);
	calloc_compare_functions(1, 128 * 1024 * 1024);
	print_end_msg("CALLOC");
	return (0);
}
