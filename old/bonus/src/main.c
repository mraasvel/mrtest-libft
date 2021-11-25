/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 17:17:53 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/02 17:34:17 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "mrbonustest.h"

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
	fprintf(stderr, "%s:\t", f_name);
	if (strlen(f_name) < 7)
		fprintf(stderr, "\t");
}

void	print_end_msg(char *f_name)
{
	printf("\t%s END\n", f_name);
	fprintf(stderr, "\n");
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
	if (argc == 1 || find_function_name(argc, argv, "ft_lstnew") == 0)
		test_lstnew();
	return (0);
}
