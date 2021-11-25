#include "mrtest_libft.h"
#include <stdbool.h>

static void iteratorFunction(void* content) {
	*(int*)content += 1;
}

static bool compareListIter(void* a, void* b) {
	return a != NULL && b != NULL && *(int*)a == *(int*)b;
}


static bool lstIterCompare(size_t size) {
	t_list* ft_list = NULL;
	t_list* reference = NULL;

	if (_MR_createListAllocated(&reference, size, false) == -1) {
		exitPerror("lstIter: malloc");
	}

	if (_MR_createListAllocated(&ft_list, size, false) == -1) {
		_MR_REF_lstclear(&reference, free);
		exitPerror("lstIter: malloc");
	}


	_MR_REF_lstiter(reference, iteratorFunction);
	ft_lstiter(ft_list, iteratorFunction);

	const bool result = _MR_lstequal(reference, ft_list, compareListIter);

	_MR_REF_lstclear(&ft_list, free);
	_MR_REF_lstclear(&reference, free);

	return result;
}

TEST_CASE("ft_lstiter", "ft_lstiter") {
	MRTEST(lstIterCompare(0));
	MRTEST(lstIterCompare(1));
	MRTEST(lstIterCompare(10));
	MRTEST(lstIterCompare(100));
}
