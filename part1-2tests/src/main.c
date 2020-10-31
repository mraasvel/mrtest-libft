#include <stdio.h>
#include <ctype.h>
#include "mrtest.h"

int	print_success_message(int b)
{
	if (b == 0)
	{
		printf("\033[1;32m");
		printf("[OK]");
		fprintf(stderr, "[OK]");
	}
	else
	{
		printf("\033[1;31m");
		printf("[KO]");
		fprintf(stderr, "[KO]");
	}
	printf("\033[0m");
	return (b);
}

void	print_start_msg(char *f_name)
{
	printf("%s START\t", f_name);
	fprintf(stderr, "%s: ", f_name);
}

void	print_end_msg(char *f_name)
{
	printf("\t%s END\n", f_name);
	fprintf(stderr, "\t%s END\n", f_name);
}

void	print_bytes(void *s, size_t n)
{
	unsigned char	*d;

	d = s;
	while (n > 0)
	{
		fprintf(stderr, "%d ", *d);
		d++;
		n--;
	}
}

int	find_function_name(int argc, char **argv, char *name)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (strcmp(argv[i], name) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 1 || find_function_name(argc, argv, "ft_memset") == 0)
		test_memset();
	if (argc == 1 || find_function_name(argc, argv, "ft_bzero") == 0)
		test_bzero();
	if (argc == 1 || find_function_name(argc, argv, "ft_memcpy") == 0)
		test_memcpy();
	if (argc == 1 || find_function_name(argc, argv, "ft_memccpy") == 0)
		test_memccpy();
	if (argc == 1 || find_function_name(argc, argv, "ft_memmove") == 0)
		test_memmove();
	if (argc == 1 || find_function_name(argc, argv, "ft_memchr") == 0)
		test_memchr();
	if (argc == 1 || find_function_name(argc, argv, "ft_memcp") == 0)
		test_memcmp();
	#ifdef STRLS
	if (argc == 1 || find_function_name(argc, argv, "ft_strlcpy") == 0)
		test_strlcpy();
	if (argc == 1 || find_function_name(argc, argv, "ft_strlcat") == 0)
		test_strlcat();
	#endif
	if (argc == 1 || find_function_name(argc, argv, "ft_strchr") == 0)
		test_strchr();
	if (argc == 1 || find_function_name(argc, argv, "ft_strrchr") == 0)
		test_strrchr();
	if (argc == 1 || find_function_name(argc, argv, "ft_strnstr") == 0)
		test_strnstr();
	if (argc == 1 || find_function_name(argc, argv, "ft_atoi") == 0)
		test_atoi();
	if (argc == 1 || find_function_name(argc, argv, "ft_isalpha") == 0)
		test_isalpha();
	if (argc == 1 || find_function_name(argc, argv, "ft_isdigit") == 0)
		test_isdigit();
	if (argc == 1 || find_function_name(argc, argv, "ft_isalnum") == 0)
		test_isalnum();
	if (argc == 1 || find_function_name(argc, argv, "ft_isascii") == 0)
		test_isascii();
	if (argc == 1 || find_function_name(argc, argv, "ft_isprint") == 0)
		test_isprint();
	if (argc == 1 || find_function_name(argc, argv, "ft_toupper") == 0)
		test_toupper();
	if (argc == 1 || find_function_name(argc, argv, "ft_tolower") == 0)
		test_tolower();
	if (argc == 1 || find_function_name(argc, argv, "ft_calloc") == 0)
		test_calloc();
	if (argc == 1 || find_function_name(argc, argv, "ft_strdup") == 0)
		test_strdup();

	/* part 2 */
	if (argc == 1 || find_function_name(argc, argv, "ft_substr") == 0)
		test_substr();
	if (argc == 1 || find_function_name(argc, argv, "ft_strjoin") == 0)
		test_strjoin();
	if (argc == 1 || find_function_name(argc, argv, "ft_strtrim") == 0)
		test_strtrim();
	if (argc == 1 || find_function_name(argc, argv, "ft_split") == 0)
		test_split();
	if (argc == 1 || find_function_name(argc, argv, "ft_itoa") == 0)
		test_itoa();
	if (argc == 1 || find_function_name(argc, argv, "ft_strmapi") == 0)
		test_strmapi();

	return (0);
}
