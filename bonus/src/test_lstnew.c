#include <stdlib.h>
#include "mrbonustest.h"

void	lstnew_error(void *content, t_list *start)
{
	fprintf(stderr, "\nFT_LSTNEW error:\n");
	fprintf(stderr, "%p - content pointer\n%p - start->content ptr\n\n", content, start->content);
}

int	lstnew_compare(void *content, void (*del)(void*))
{
	t_list	*start;

	start = ft_lstnew(content);
	if (start == 0)
	{
		print_success_message(-1);
		fprintf(stderr, "\nFT_LSTNEW returned \"NULL\" pointer.");
		fprintf(stderr, "Content: %p\n", content);
		return (1);
	}
	if (start->content == content)
	{
		print_success_message(0);
		test_lstclear(&start, del);
		return (0);
	}
	else
	{
		test_lstclear(&start, del);
		lstnew_error(content, start);
		return (-1);
	}
	
}

int	test_lstnew(void)
{
	int arr[5] = {1, 2, 3, 4, 5};
	char	*a;

	a = calloc(5, 1);
	if (a == 0)
		return (0);
	print_start_msg("FT_LSTNEW");
	lstnew_compare(0, (void*)0);
	lstnew_compare("1234567890", (void*)0);
	lstnew_compare(arr, (void*)0);
	lstnew_compare(a, &free);
	print_end_msg("FT_LSTNEW");
	return (0);
}
