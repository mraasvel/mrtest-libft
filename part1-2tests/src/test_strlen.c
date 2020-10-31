#include <string.h>
#include <stdio.h>
#include "mrtest.h"

void	strlen_error(char *s, size_t f, size_t n)
{
	fprintf(stderr, "\nSTRLEN input error:\n");
	fprintf(stderr, "input: \"%s\"\nft_strlen ret: %ld\nst_strlen ret: %ld\n\n", s, f, n);
}

int	strlen_compare_functions(char *s)
{
	size_t	f;
	size_t	n;

	n = strlen(s);
	f = ft_strlen(s);
	if (n == f)
	{
		print_success_message(0);
		return (0);
	}
	else
	{
		print_success_message(-1);
		strlen_error(s, f, n);
		return (-1);
	}
	
}

int	test_strlen(void)
{
	print_start_msg("STRLEN");
	strlen_compare_functions("");
	strlen_compare_functions("9fa98sduf98asudnf98aunsd98fvunas98dfunva98sdufn98asudnf9asdfv");
	strlen_compare_functions("1234\n\t1234\n\t\01");
	strlen_compare_functions("12345\067890");
	strlen_compare_functions("1234567890");
	strlen_compare_functions("r\0r");
	print_end_msg("STRLEN");
	return (0);
}