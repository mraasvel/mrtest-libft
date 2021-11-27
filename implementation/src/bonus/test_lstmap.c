#include "mrtest_libft.h"
#include <stdbool.h>

static void* incrementFunction(void* content) {
	return (void*)((unsigned long)(content + 1));
}

static void fakeDelete(void* x) {
	(void)x;
}

static bool compareLstMap(void* a, void* b) {
	return a == b;
}

static bool lstMapCompare(size_t size) {
	t_list* original = NULL;

	if (_MR_createlist(&original, size, _MR_REF_lstadd_front, true) == -1) {
		exitPerror("malloc");
	}

	t_list* ft_list = ft_lstmap(original, incrementFunction, fakeDelete);
	if (!ft_list) {
		_MR_REF_lstclear(&original, NULL);
		perror("ft_lstmap: malloc");
		return false;
	}
	t_list* reference = _MR_REF_lstmap(original, incrementFunction, fakeDelete);
	if (!reference) {
		_MR_REF_lstclear(&original, NULL);
		_MR_REF_lstclear(&ft_list, NULL);
		exitPerror("_MR_REF_lstmap: malloc");
	}

	const bool result = _MR_lstequal(ft_list, reference, compareLstMap);

	_MR_REF_lstclear(&original, NULL);
	_MR_REF_lstclear(&ft_list, NULL);
	_MR_REF_lstclear(&reference, NULL);
	return result;

}

TEST_CASE("ft_lstmap", "ft_lstmap") {
	MRTEST(lstMapCompare(1));
	MRTEST(lstMapCompare(10));
	MRTEST(lstMapCompare(100));
}
