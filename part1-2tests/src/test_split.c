#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mrtest.h"

void	free_strings(char **results)
{
	size_t	i;

	i = 0;
	while (results[i] != 0)
	{
		free(results[i]);
		i++;
	}
	free(results);
}

void	split_error(const char **expected, char **result, char *s, char c)
{
	size_t	i;

	fprintf(stderr, "\nFT_SPLIT error input:\n");
	fprintf(stderr, "input string: '%s'\nseperator: '%c' (ASCII %d)\n", s, c, c);
	fprintf(stderr, "expected: ");
	i = 0;
	while (expected[i] != 0)
	{
		
		fprintf(stderr, "'%s' ", expected[i]);
		i++;
	}
	fprintf(stderr, "\nsplit: ");
	i = 0;
	while (result[i] != 0)
	{
		fprintf(stderr, "'%s' ", result[i]);
		i++;
	}
	fprintf(stderr, "\n\n");
}

int	split_compare_functions(const char **expected, char *s, char c)
{
	char	**results;
	size_t	i;

	results = ft_split(s, c);
	if (results == 0)
	{
		if (expected == 0)
			print_success_message(0);
		else
		{
			print_success_message(-1);
			fprintf(stderr, "\nFT_SPLIT Returned unexpected NULL pointer.\n\n");
		}
		
		return (1);
	}
	i = 0;
	if (expected[0] == 0 && results[0] != 0)
	{
		print_success_message(-1);
		split_error(expected, result, s, c);
		fprintf(stderr, "FT_SPLIT returned NONNULL when it should have returned a pointer to NULL pointer\n\n");
		return (-1);
	}
	while (expected[i] != 0)
	{
		if (strcmp(expected[i], results[i]) == 1)
		{
			print_success_message(-1);
			split_error(expected, results, s, c);
			free_strings(results);
			return (-1);
		}
		i++;
	}
	if (results != 0)
		free_strings(results);
	print_success_message(0);
	return (0);
}

int	test_split(void)
{
	const char *e0[] = {NULL};
	const char *e1[] = {"a", "b", "c", "d", "e", "f", "g", NULL};
	const char *e2[] = {"a", "b1234", "c", "dasdfij\t", "aosdfjas\ndfe", "fasdoifj", "gaosdifjaoisdjf", NULL};
	const char *e3[] = {"132sdfasdjfjasdoicjaosidjcoaisdjf02u13  0asdf09asd f0 f09 iasd09fi asd0f", NULL};
	const char *e4[] = {"b", "b", NULL};
	const char *e5[] = {"b", NULL};
	const char *e6[] = {"1234", NULL};

	print_start_msg("FT_SPLIT");
	split_compare_functions(e0, "aaaaaaaaaaaaaaaaa", 'a');
	split_compare_functions(e1, "a b c d e f g", ' ');
	split_compare_functions(e2, "a b1234 c dasdfij\t    aosdfjas\ndfe       fasdoifj gaosdifjaoisdjf", ' ');
	split_compare_functions(e3, "132sdfasdjfjasdoicjaosidjcoaisdjf02u13  0asdf09asd f0 f09 iasd09fi asd0f", '\t');
	split_compare_functions(e0, "", ' ');
	split_compare_functions(e5, "aaaaaaaaaaaaaaaaab", 'a');
	split_compare_functions(e5, "baaaaaaaaaaaaaaaaa", 'a');
	split_compare_functions(e5, "aaaaaaaaabaaaaaaaa", 'a');
	split_compare_functions(e6, "1234", '\0');
	split_compare_functions(e0, "a", 'a');
	split_compare_functions(e5, "b", 'a');
	split_compare_functions(e5, "ba", 'a');
	split_compare_functions(e5, "ab", 'a');
	split_compare_functions(e4, "bab", 'a');
	split_compare_functions(e4, "bab", 'a');
	print_end_msg("FT_SPLIT");
	return (0);
}
