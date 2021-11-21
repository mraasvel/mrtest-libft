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

void	strdup_error(const char *src, char *ft_ret, char *st_ret)
{
	fprintf(stderr, "\nSTRDUP error:\n");
	fprintf(stderr, "%s - string to duplicate; len: %ld\n", src, strlen(src));
	fprintf(stderr, "%s - ft_strdup result\n%s - strdup result\n", ft_ret, st_ret);
}

int	strdup_compare_functions(const char *src)
{
	char	*ft_ret;
	char	*st_ret;

	ft_ret = ft_strdup(src);
	st_ret = strdup(src);
	if (ft_ret == 0 && st_ret == 0)
	{
		print_success_message(0);
		fprintf(stderr, "\nboth functions return NULL\n\n");
		return (1);
	}
	if (ft_ret == 0 || st_ret == 0)
	{
		print_success_message(-1);
		fprintf(stderr, "%p - ft_strdup return address\n%p - strdup return address\n\n", ft_ret, st_ret);
		free_ptrs(ft_ret, st_ret);
		return (-1);
	}
	if (strcmp(ft_ret, st_ret) == 0)
	{
		print_success_message(0);
		free_ptrs(ft_ret, st_ret);
		return (0);
	}
	else
	{
		print_success_message(-1);
		strdup_error(src, ft_ret, st_ret);
		free_ptrs(ft_ret, st_ret);
		return (-1);
	}
}

int	test_strdup(void)
{
	print_start_msg("STRDUP");
	strdup_compare_functions("");
	strdup_compare_functions("1234567890");
	strdup_compare_functions("12345\012345");
	strdup_compare_functions("ad9fuanjdsadcaisdcadcscdsaidcasiuhcdsaiuhdsaciuhdsaciuhadsciuhasdiua\t\nsdc");
	print_end_msg("\t\t\t\t\tSTRDUP");
	return (0);
}
