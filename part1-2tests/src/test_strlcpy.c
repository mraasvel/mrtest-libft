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

void	strlcpy_error(const char *src, char *ft_dest, char *st_dest, size_t size, size_t ft_ret, size_t st_ret)
{
	fprintf(stderr, "\nSTRLCPY input error:\n");
	fprintf(stderr, "src: %s\nsize: %ld\n", src, size);
	fprintf(stderr, "ft_strlcpy return value: %ld\nexpected return value: %ld\n", ft_ret, st_ret);
	if (ft_dest == 0 || st_dest == 0 || size == 0)
		return ;
	fprintf(stderr, "ft_strlcpy dest string: %s\nstrlcpy dest string: %s\n", ft_dest, st_dest);
	print_bytes(ft_dest, strlen(ft_dest) + 1);
	fprintf(stderr, "- ft_strlcpy string\n");
	print_bytes(st_dest, strlen(st_dest) + 1);
	fprintf(stderr, "- strlcpy string\n");
}

int	strlcpy_compare_functions(const char *src, size_t size)
{
	char	*ft_dest;
	char	*st_dest;
	size_t	ft_ret;
	size_t	st_ret;

	if (strlen(src) < size)
	{
		ft_dest = (char*)malloc((strlen(src) + 1) * sizeof(char));
		st_dest = (char*)malloc((strlen(src) + 1) * sizeof(char));
	}
	else
	{
		ft_dest = (char*)malloc(size * sizeof(char));
		st_dest = (char*)malloc(size * sizeof(char));
	}
	ft_dest[0] = 0;
	st_dest[0] = 0;
	if (ft_dest == 0 || st_dest == 0)
	{
		free_ptrs(ft_dest, st_dest);
		fprintf(stderr, "\n\tSTRLCPY malloc error\n\n");
		return (1);
	}
	st_ret = strlcpy(st_dest, src, size);
	ft_ret = ft_strlcpy(ft_dest, src, size);
	if (ft_ret == st_ret)
	{
		if (size == 0)
		{
			print_success_message(0);
		}
		else if (strcmp(ft_dest, st_dest) == 0)
		{
			print_success_message(0);
		}
		else
		{
			print_success_message(-1);
			strlcpy_error(src, ft_dest, st_dest, size, ft_ret, st_ret);
		}
		free_ptrs(ft_dest, st_dest);
		return (0);
	}
	else
	{
		print_success_message(-1);
		strlcpy_error(src, ft_dest, st_dest, size, ft_ret, st_ret);
		free_ptrs(ft_dest, st_dest);
		return (-1);
	}
	
}

int	test_strlcpy(void)
{
	print_start_msg("STRLCPY");
	strlcpy_compare_functions("1234567890", 5);
	strlcpy_compare_functions("1234567890", 10);
	strlcpy_compare_functions("", 1);
	strlcpy_compare_functions("", 1000);
	strlcpy_compare_functions("1234567890", 0);
	strlcpy_compare_functions("d9sd8fu a9fds8 9d8f9 8sdfa9 8sdf89 fsdas9da8f ", 10000);
	strlcpy_compare_functions("aijfsdoijfdsaaoijsfdajsfdoijafsdoijfsdaafsijdofsdia", 20);
	print_end_msg("\t\t\t\tSTRLCPY");
	return (0);
}