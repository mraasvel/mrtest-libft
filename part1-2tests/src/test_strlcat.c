#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mrtest.h"

static void	free_ptrs(char *a, char *b)
{
	if (a != 0)
		free(a);
	if (b != 0)
		free(b);
}

void	strlcat_error(const char *src, size_t size, char *ft_d, char *st_d, size_t ft_ret, size_t st_ret)
{
	fprintf(stderr, "\nSTRLCAT input error:\n");
	fprintf(stderr, "size: %ld\nsrc: %s\n", size, src);
	if (size == 0)
	{
		fprintf(stderr, "expected return value: %ld\nft_strlcpy return value: %ld\n\n", st_ret, ft_ret);
		return ;
	}
	fprintf(stderr, "expected return value : %ld\nexpected string: %s\n", st_ret, st_d);
	fprintf(stderr, "ft_strlcpy return value: %ld\nft_strlcpy string: %s\n\n", ft_ret, ft_d);
}

int	strlcat_compare_functions(char *dest, const char *src, size_t size)
{
	char 	*ft_d;
	char	*st_d;
	size_t	st_ret;
	size_t	ft_ret;

	ft_d = (char*)malloc(size * sizeof(char));
	st_d = (char*)malloc(size * sizeof(char));
	if (ft_d == 0 || st_d == 0)
	{
		free_ptrs(ft_d, st_d);
		return (1);
	}
	bzero(ft_d, size);
	bzero(ft_d, size);
	strlcpy(ft_d, dest, size);
	strlcpy(st_d, dest, size);
	ft_ret = ft_strlcat(ft_d, src, size);
	st_ret = strlcat(st_d, src, size);
	if (size == 0 && ft_ret == st_ret)
	{
		print_success_message(0);
		free_ptrs(ft_d, st_d);
		return (0);
	}
	if (ft_ret == st_ret && strcmp(ft_d, st_d) == 0)
	{
		print_success_message(0);
		free_ptrs(ft_d, st_d);
		return (0);
	}
	else
	{
		print_success_message(-1);
		strlcat_error(src, size, ft_d, st_d, ft_ret, st_ret);
		free_ptrs(ft_d, st_d);
		return (-1);
	}
}

int	test_strlcat(void)
{
	print_start_msg("STRLCAT");
	strlcat_compare_functions("1234567890", "1234567890", 20);
	strlcat_compare_functions("1234567890", "1234567890", 10);
	strlcat_compare_functions("1234567890", "1234567890", 5);
	strlcat_compare_functions("", "1234567890", 100);
	strlcat_compare_functions("", "1234567890", 4);
	strlcat_compare_functions("1234567890", "", 100);
	strlcat_compare_functions("1234567890", "1", 0);
	strlcat_compare_functions("12345pifdhsiuhafdsadiuhsaiuhadfiuhiaufds67890", "1usfdsfdihaiuhfdsaiuhfdsaifsuhdaiuhsfdaiuhfdsaiuhafdsaiuhfdasfiuhafdiuhaiuhs", 128 * 1024 * 1024);
	print_end_msg("\t\t\tSTRLCAT");
	return (0);
}
