1. Put libft path in "get_lib.sh" and run it or put libft in this directory.
2. ON MAC:
	Comment out (or remove) |#define linux| in part1-2tests/include/mrtest.h
	In part1-2tests/Makefile: replace |LIBFLAGLINUX| with |LIBFLAG|
3. ON linux:
	to test STRLCPY and STRLCAT:
	You need to have libbsd-dev installed (you can specify the include path in part1-2tests/include/mrtest.h)
	You can try removing test_strlcpy and test_strlcat (there's a #define STRLS in mrtest.h, but if you remove it there are probably compilation errors)
4. Go into ./part1-2tests/ and run "run.sh" this will compile the program and send all stderr output into "results.log"
5. "./run.sh ft\_split ft\_atoi" etc to run just these functions.
