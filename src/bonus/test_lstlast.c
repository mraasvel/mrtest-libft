#include "mrtest_libft.h"
#include <stdbool.h>

static bool lstLastCompare(size_t size) {
	t_list* reference = NULL;

	if (_MR_createlist(&reference, size, &_MR_REF_lstadd_back, true) == -1) {
		exitPerror("lstLastCompare: malloc");
	}

	const bool result = _MR_REF_lstlast(reference) == ft_lstlast(reference);
	_MR_REF_lstclear(&reference, NULL);
	return result;
}

TEST_CASE("ft_lstlast", "ft_lstlast") {
	MRTEST(lstLastCompare(0));
	MRTEST(lstLastCompare(1));
	MRTEST(lstLastCompare(10));
	MRTEST(lstLastCompare(100));
}
