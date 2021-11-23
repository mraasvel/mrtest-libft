#include "mrtest_libft.h"
#include <stdbool.h>

static bool lstnewCompare(void* content, void (*del)(void*)) {
	t_list* a = ft_lstnew(content);
	t_list* b = _MR_REF_lstnew(content);

	if (!a || !b) {
		exitPerror("lstnew");
	}

	const bool result = a->content == b->content;

	_MR_REF_lstdelone(a, NULL);
	_MR_REF_lstdelone(b, NULL);
	if (del) {
		del(content);
	}
	return result;
}

TEST_CASE("lstnew", "lstnew") {
	MRTEST(lstnewCompare((void*)1, NULL));
	MRTEST(lstnewCompare((void*)2, NULL));
	MRTEST(lstnewCompare((void*)0, NULL));
	MRTEST(lstnewCompare((void*)3, NULL));
	MRTEST(lstnewCompare(malloc(1), free));
}
