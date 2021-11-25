#ifndef MRTEST_LIBFT_H
# define MRTEST_LIBFT_H

# include "libft.h"
# include "mrtest.h"
# include <stdbool.h>

void exitPerror(const char* x);

/* Bonus Reference */

t_list	*_MR_REF_lstnew(void *content);
void	_MR_REF_lstadd_front(t_list **lst, t_list *new);
int		_MR_REF_lstsize(t_list *lst);
t_list	*_MR_REF_lstlast(t_list *lst);
void	_MR_REF_lstadd_back(t_list **lst, t_list *new);
void	_MR_REF_lstdelone(t_list *lst, void (*del)(void *));
void	_MR_REF_lstclear(t_list **lst, void (*del)(void *));
void	_MR_REF_lstiter(t_list *lst, void (*f)(void *));
t_list	*_MR_REF_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

bool	_MR_lstequal(t_list* a, t_list* b, bool comp(void*, void*));
int		_MR_createlist(t_list** a, size_t size, void (*addFunction)(t_list**, t_list*), bool random);
int		_MR_createListAllocated(t_list** a, size_t size, bool random);

#endif /* MRTEST_LIBFT_H */
