#include "mrtest_libft.h"
#include <stdlib.h>
#include <stdbool.h>

t_list	*_MR_REF_lstnew(void *content) {
	t_list* x = malloc(sizeof(t_list));
	if (x == NULL) {
		return NULL;
	}

	x->content = content;
	x->next = NULL;
	return x;
}

void	_MR_REF_lstadd_front(t_list **lst, t_list *new) {
	if (*lst == NULL) {
		*lst = new;
	} else {
		new->next = *lst;
		*lst = new;
	}
}

int		_MR_REF_lstsize(t_list *lst) {
	int size = 0;
	while (lst) {
		++size;
		lst = lst->next;
	}
	return size;
}

t_list	*_MR_REF_lstlast(t_list *lst) {
	if (lst == NULL) {
		return lst;
	}

	while (lst->next) {
		lst = lst->next;
	}
	return lst;
}

void	_MR_REF_lstadd_back(t_list **lst, t_list *new) {
	t_list* last = _MR_REF_lstlast(*lst);

	if (last == NULL) {
		*lst = new;
	} else {
		last->next = new;
	}
}

void	_MR_REF_lstdelone(t_list *lst, void (*del)(void *)) {
	if (lst) {
		if (del) {
			del(lst->content);
		}
		free(lst);
	}
}

void	_MR_REF_lstclear(t_list **lst, void (*del)(void *)) {
	while (*lst) {
		t_list* temp = *lst;
		*lst = (*lst)->next;
		_MR_REF_lstdelone(temp, del);
	}
}

void	_MR_REF_lstiter(t_list *lst, void (*f)(void *)) {
	while (lst) {
		f(lst->content);
		lst = lst->next;
	}
}

static t_list* _MR_generateNewElement(void* content, void *(*f)(void *), void (*del)(void *)) {
	void* new_content = f(content);
	if (new_content == NULL) {
		return NULL;
	}

	t_list* element = _MR_REF_lstnew(new_content);
	if (element == NULL) {
		if (del) {
			del(new_content);
		}
	}
	return element;
}

t_list	*_MR_REF_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) {
	t_list* new_list = NULL;
	t_list* last = NULL;

	while (lst) {
		t_list* element = _MR_generateNewElement(lst->content, f, del);
		if (element == NULL) {
			_MR_REF_lstclear(&new_list, del);
			return NULL;
		}

		// for linear complexity
		if (last) {
			last->next = element;
		} else {
			new_list = element;
		}
		last = element;
		lst = lst->next;
	}
	return new_list;
}

bool _MR_lstequal(t_list* a, t_list* b, bool comp(void*, void*)) {
	while (a && b) {
		if (!comp(a->content, b->content)) {
			return false;
		}
		a = a->next;
		b = b->next;
	}

	return a == b;
}
