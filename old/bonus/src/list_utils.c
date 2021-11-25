#include <stdlib.h>
#include "mrbonustest.h"

void	test_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == 0)
		return ;
	if (lst->content == 0)
	{
		free(lst);
		return ;
	}
	if (del != 0)
		(*del)(lst->content);
	free(lst);
}

void	test_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst == 0)
		return ;
	if (*lst == 0)
		return ;
	while ((*lst)->next != 0)
	{
		temp = (*lst)->next;
		test_lstdelone(*lst, del);
		*lst = temp;
	}
	test_lstdelone(*lst, del);
	*lst = 0;
}
