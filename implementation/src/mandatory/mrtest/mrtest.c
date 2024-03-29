#include "mrtest.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

_MR_FunctionVectorType* _MR_FunctionVectorConstructor(size_t initial_capacity) {

	assert(initial_capacity > 0);

	_MR_FunctionVectorType* v = (_MR_FunctionVectorType*)malloc(1 * sizeof(_MR_FunctionVectorType));
	if (v == NULL) {
		return NULL;
	}

	v->capacity = initial_capacity;
	v->size = 0;
	v->table = (_MR_FunctionType*)malloc(initial_capacity * sizeof(_MR_FunctionType));
	if (v->table == NULL) {
		free(v);
		return NULL;
	}
	return v;
}

void _MR_FunctionVectorDestructor(_MR_FunctionVectorType* v) {
	_MR_FunctionVectorIteratorType it = _MR_FunctionVectorGetIterator(v);
	while (it.begin != it.end) {
		free(it.begin->tag);
		free(it.begin->name);
		++it.begin;
	}
	free(v->table);
	free(v);
}

/*
Resize the table if there's no more room for new elements
*/
static int _MR_FunctionVectorEnsureCapacity(_MR_FunctionVectorType* v) {
	if (v->size == v->capacity) {
		_MR_FunctionType* new_table = (_MR_FunctionType*)malloc(v->capacity * 2 * sizeof(_MR_FunctionType));
		if (new_table == NULL) {
			return -1;
		}
		memcpy(new_table, v->table, v->size * sizeof(_MR_FunctionType));
		v->capacity *= 2;
		free(v->table);
		v->table = new_table;
	}
	return 0;
}

/*
Return: -1 on malloc failure, 0 on success
*/
int _MR_FunctionVectorPushback(_MR_FunctionVectorType** v_ptr, _MR_FunctionType x) {
	if (*v_ptr == NULL) {
		*v_ptr = _MR_FunctionVectorConstructor(1);
		if (*v_ptr == NULL) {
			perror("malloc");
			exit(EXIT_FAILURE);
		}
	}
	_MR_FunctionVectorType* v = *v_ptr;
	if (_MR_FunctionVectorEnsureCapacity(v) == -1) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	assert(v->size < v->capacity);
	v->table[v->size++] = x;
	return 0;
}

/*
WARNING: DO NOT dereference the it.end pointer.

-- USAGE --
	it = _MR_FunctionVectorGetIterator(v);
	while (it.begin != it.end) {
		++it.begin;
	}
*/
_MR_FunctionVectorIteratorType _MR_FunctionVectorGetIterator(_MR_FunctionVectorType* v) {
	return (_MR_FunctionVectorIteratorType) {
		.begin = v->table,
		.end = v->table + v->size
	};
}

_MR_FunctionVectorType* _MR_global_function_vector = NULL;

static int _MR_numLen(size_t n) {
	int i = 1;
	while (n >= 10) {
		++i;
		n /= 10;
	}
	return i;
}

static void _MR_printSign(int num_digits, const char* color) {
	printf("%s", color);
	for (int i = 0; i < num_digits; ++i) {
		printf("=");
	}
	printf(_MR_RESET_COLOR "\n");
}

static void _MR_printSuccessMessage(size_t num_testcases) {
	int num_digits = _MR_numLen(num_testcases);

	printf(_MR_GREEN_BOLD "=========================================");
	_MR_printSign(num_digits, _MR_GREEN_BOLD);
	printf(_MR_GREEN_BOLD "=======" _MR_RESET_COLOR
	" Passed [%lu] total TestCases " 
	_MR_GREEN_BOLD "=======" _MR_RESET_COLOR "\n", num_testcases);
	printf(_MR_GREEN_BOLD "=========================================");
	_MR_printSign(num_digits, _MR_GREEN_BOLD);
}

static void _MR_printFailMessage(size_t num_testcases, size_t num_failed) {
	size_t num_signs = _MR_numLen(num_testcases) + _MR_numLen(num_failed);

	printf(_MR_RED_BOLD "===============================================");
	_MR_printSign(num_signs, _MR_RED_BOLD);

	printf(_MR_RED_BOLD "=======" _MR_RESET_COLOR
		" Failed [%lu] of [%lu] total TestCases "
		_MR_RED_BOLD "=======" _MR_RESET_COLOR "\n", num_failed, num_testcases);

	printf(_MR_RED_BOLD "===============================================");
	_MR_printSign(num_signs, _MR_RED_BOLD);
}

void _MR_printEndMessage(size_t num_testcases, size_t num_failed) {
	printf("\n");
	if (num_failed == 0) {
		_MR_printSuccessMessage(num_testcases);
	} else {
		_MR_printFailMessage(num_testcases, num_failed);
	}
	printf("\n");
}

/* Return true if tag should be executed */
int _MR_shouldExecuteTag(int argc, char *argv[], char *tag)
{
	if (argc == 0) {
		return 1;
	}

	for (int i = 0; i < argc; ++i) {
		if (strcmp(tag, argv[i]) == 0) {
			return 1;
		}
	}

	return 0;
}

static const char* _MR_SIGNAL_NAME(int signal) {
	static const char* signals[] = {
		[SIGABRT] = "SIGABRT",
		[SIGALRM] = "SIGALRM",
		[SIGBUS] = "SIGBUS",
		[SIGCHLD] = "SIGCHLD",
		[SIGCONT] = "SIGCONT",
		[SIGFPE] = "SIGFPE",
		[SIGHUP] = "SIGHUP",
		[SIGILL] = "SIGILL",
		[SIGINT] = "SIGINT",
		[SIGIO] = "SIGIO",
		[SIGKILL] = "SIGKILL",
		[SIGPIPE] = "SIGPIPE",
		[SIGPROF] = "SIGPROF",
		[SIGQUIT] = "SIGQUIT",
		[SIGSEGV] = "SIGSEGV",
		[SIGSTOP] = "SIGSTOP",
		[SIGTSTP] = "SIGTSTP",
		[SIGSYS] = "SIGSYS",
		[SIGTERM] = "SIGTERM",
		[SIGTRAP] = "SIGTRAP",
		[SIGTTIN] = "SIGTTIN",
		[SIGTTOU] = "SIGTTOU",
		[SIGURG] = "SIGURG",
		[SIGUSR1] = "SIGUSR1",
		[SIGUSR2] = "SIGUSR2",
		[SIGVTALRM] = "SIGVTALRM",
		[SIGXCPU] = "SIGXCPU",
		[SIGXFSZ] = "SIGXFSZ",
		[SIGWINCH] = "SIGWINCH"
	};

	return signals[signal];
}

int _MR_executeTestCase(_MR_FunctionType* it) {
	pid_t pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		it->function();
		exit(EXIT_SUCCESS);
	}

	int status;
	if (waitpid(pid, &status, 0) == -1) {
		perror("waitpid");
		exit(EXIT_FAILURE);
	}

	// Check exit status
	if (WIFEXITED(status)) {
		if (WEXITSTATUS(status) != 0) {
			return -1;
		}
	} else if (WIFSIGNALED(status)) {
		fprintf(stderr, "%s: CRASH: [" _MR_RED_BOLD "%s" _MR_RESET_COLOR "]\r\n",
			it->name, _MR_SIGNAL_NAME(WTERMSIG(status)));
		return -1;
	}

	return 0;
}
