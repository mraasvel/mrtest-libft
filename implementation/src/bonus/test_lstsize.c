#include "mrtest_libft.h"
#include <stdbool.h>

static bool lstSizeCompare(size_t n) {
	t_list* reference = NULL;

	_MR_createlist(&reference, n, _MR_REF_lstadd_back, true);

	const bool result = _MR_REF_lstsize(reference) == ft_lstsize(reference);
	_MR_REF_lstclear(&reference, NULL);
	return result;
}

TEST_CASE("ft_lstsize", "ft_lstsize") {
	MRTEST(lstSizeCompare(0));
	MRTEST(lstSizeCompare(1));
	MRTEST(lstSizeCompare(10));
	MRTEST(lstSizeCompare(100));
}
