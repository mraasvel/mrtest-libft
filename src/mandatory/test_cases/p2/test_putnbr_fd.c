#include "mrtest.h"
#include "mrtest_libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

static void closeFd(int fd) {
	if (close(fd) == -1) {
		perror("close");
	}
}

static bool putnbrCompare(int n) {
	char string[15];
	char expected[15];

	memset(string, 0, sizeof(string));

	int fds[2];
	if (pipe(fds) == -1) {
		exitPerror("pipe");
	}

	ft_putnbr_fd(n, fds[1]);
	if (read(fds[0], string, 15) == -1) {
		exitPerror("read");
	}

	if (sprintf(expected, "%d", n) < 0) {
		perror("sprintf");
	}

	const bool result = strcmp(string, expected) == 0;

	closeFd(fds[0]);
	closeFd(fds[1]);
	return result;
}

TEST_CASE("putnbr", "putnbr") {
	MRTEST(putnbrCompare(1));
	MRTEST(putnbrCompare(-1));
	MRTEST(putnbrCompare(0));
	MRTEST(putnbrCompare(2147483647));
	MRTEST(putnbrCompare(-2147483648));
}
