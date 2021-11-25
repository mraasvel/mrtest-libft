#include "mrtest_libft.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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

int _MR_createlist(t_list** a, size_t size, void (*addFunction)(t_list**, t_list*), bool random) {
	assert(a != NULL && *a == NULL);

	while (size-- > 0) {
		unsigned long value;
		if (random) {
			value = rand();
		} else {
			value = size;
		}
		t_list* x = _MR_REF_lstnew((void*)value);

		if (!x) {
			free(x);
			_MR_REF_lstclear(a, NULL);
			return -1;
		}

		addFunction(a, x);
	}

	return 0;
}

int _MR_createListAllocated(t_list** a, size_t size, bool random) {
	assert(a != NULL);
	assert(*a == NULL);

	while (size-- > 0) {
		int* content = malloc(1 * sizeof(int));
		if (content == NULL) {
			_MR_REF_lstclear(a, free);
			return -1;
		}

		if (random) {
			*content = rand();
		} else {
			*content = size;
		}

		t_list* entry = _MR_REF_lstnew(content);
		if (entry == NULL) {
			free(content);
			_MR_REF_lstclear(a, free);
			return -1;
		}

		_MR_REF_lstadd_front(a, entry);
	}

	return 0;
}
