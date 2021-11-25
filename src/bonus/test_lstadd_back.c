#include "mrtest_libft.h"
#include <stdbool.h>

static bool _MR_compare(void* a, void* b) {
	return a == b;
}

static bool lstAddBackCompare(size_t size) {

	t_list* ft_list = NULL;
	t_list* reference = NULL;

	while (size-- > 0) {
		unsigned long value = rand();
		t_list* x = _MR_REF_lstnew((void*)value);
		t_list* y = _MR_REF_lstnew((void*)value);
		if (!x || !y) {
			exitPerror("lstadd_back: malloc");
		}
		ft_lstadd_back(&ft_list, x);
		_MR_REF_lstadd_back(&reference, y);
	}

	const bool result = _MR_lstequal(ft_list, reference, _MR_compare);

	_MR_REF_lstclear(&ft_list, NULL);
	_MR_REF_lstclear(&reference, NULL);
	return result;
}

TEST_CASE("ft_lstadd_back", "ft_lstadd_back") {
	MRTEST(lstAddBackCompare(0));
	MRTEST(lstAddBackCompare(1));
	MRTEST(lstAddBackCompare(2));
	MRTEST(lstAddBackCompare(50));
	MRTEST(lstAddBackCompare(100));
}
