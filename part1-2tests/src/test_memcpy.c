#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mrtest.h"

static void	free_ptrs(char *f, char *s, char *src)
{
	if (f != 0)
		free(f);
	if (s != 0)
		free(s);
	if (src != 0)
		free(src);
}

char	*memcpy_get_src(int c, size_t n)
{
	char	*src;

	src = (char*)malloc(n * sizeof(char));
	if (src == 0)
		return (0);
	memset(src, c, n);
	return (src);
}

void	memcpy_error(char *f, char *s, char *src, int c, size_t n)
{
	fprintf(stderr, "\nMEMCPY input that gave error:\nc = %d\nn = %ld\nsrc = memset(src, %d, %ld)\n", c, n, c, n);
	if (n < 50)
	{
		print_bytes(src, n);
		fprintf(stderr, " - src bytes\n");
		print_bytes(s, n);
		fprintf(stderr, " - memset bytes\n");
		print_bytes(f, n);
		fprintf(stderr, " - ft_memset bytes\n");
	}

}

int	memcpy_compare_functions(int c, size_t n)
{
	char	*f;
	char	*s;
	char	*src;

	f = (char*)malloc(n * sizeof(char));
	s = (char*)malloc(n * sizeof(char));
	src = memcpy_get_src(c, n);
	if (f == 0 || s == 0 || src == 0)
	{
		free_ptrs(f, s, src);
		return (1);
	}
	f = ft_memcpy(f, src, n);
	s = memcpy(s, src, n);
	if (!memcmp(f, s, n))
	{
		print_success_message(0);
		free_ptrs(f, s, src);
		return (0);
	}
	else
	{
		memcpy_error(f, s, src, c, n);
		print_success_message(-1);
		free_ptrs(f, s, src);
		return (-1);
	}
}

int	memcpy_compare_returns()
{
	char	*dest;
	char	*ft_ret;

	dest = (char*)malloc(1000);
	if (dest == 0)
	{
		fprintf(stderr, "\nMalloc returned NULL in test_memcpy\n\n");
		print_success_message(-1);
		return (1);
	}
	ft_ret = ft_memcpy(dest, 0, 0);
	if (dest == ft_ret)
	{
		print_success_message(0);
		free(dest);
		return (0);
	}
	else
	{
		print_success_message(-1);
		free(dest);
		return (-1);
	}
}

int	test_memcpy(void)
{
	print_start_msg("MEMCPY");
	memcpy_compare_functions(0, 1024);
	memcpy_compare_functions(50, 20);
	memcpy_compare_functions(900, 49);
	memcpy_compare_functions(1, 1024 * 1024 * 128);
	memcpy_compare_functions('a', 1024);
	memcpy_compare_functions('b', 1024);
	memcpy_compare_returns();
	print_end_msg("\t\t\t\tMEMCPY");
	return (0);
}