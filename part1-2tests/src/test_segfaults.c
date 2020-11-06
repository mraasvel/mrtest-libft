#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "mrtest.h"

void	segfault_substr(void)
{
	ft_substr(0, 0, 0);
	ft_substr(0, 10, 0);
	ft_substr(0, 0, 10);
	ft_substr(0, 10, 10);
}

void	segfault_strjoin(void)
{
	char *ret;

	ret = ft_strjoin(0, "");
	if (ret != 0)
		free(ret);
	ret = ft_strjoin("", 0);
	if (ret != 0)
		free(ret);
	ret = ft_strjoin(0, 0);
}

void	segfault_strtrim(void)
{
	char	*ret;

	ret = ft_strtrim("", 0);
	if (ret != 0)
		free(ret);
	ret = ft_strtrim(0, "");
	if (ret != 0)
		free(ret);
	ret = ft_strtrim(0, 0);
}

void	segfault_split(void)
{
	ft_split(0, 0);
	ft_split(0, 'a');
}

char	lol(unsigned int i, char c)
{
	return (c + i);
}

void	segfault_strmapi(void)
{
	ft_strmapi(0, 0);
	ft_strmapi(0, &lol);
	// ft_strmapi("abc", 0);
}

int	test_segfaults(void)
{
	print_start_msg("\nSEGFAULTS");
	fprintf(stderr, "\nFT_STUBSTR: ");
	segfault_substr();
	print_success_message(0);
	fprintf(stderr, "\nFT_STRJOIN: ");
	print_success_message(0);
	segfault_strjoin();
	fprintf(stderr, "\nFT_STRTRIM: ");
	segfault_strtrim();
	print_success_message(0);
	fprintf(stderr, "\nFT_SPLIT: ");
	segfault_split();
	print_success_message(0);
	/* itoa takes int so no problems probably */
	fprintf(stderr, "\nFT_STRMAPI: ");
	segfault_strmapi();
	print_success_message(0);
	printf("\n");
	return (0);
}
