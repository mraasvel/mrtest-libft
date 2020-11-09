# FILES
NAME = a.out
SRC = $(shell find ./src/ -name "*.c" -exec basename {} \;)
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

# Compilation
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
# CFLAGS = -c
DEBUG = -O0 -g -fsanitize=address
# DEBUG =
IFLAGS = -I include
LIBFLAGLINUX = -L.. -lft -lbsd
LIBFLAG = -L.. -lft

#DIRS
OBJDIR = ./obj
SRCDIR = ./src
# PATHS
vpath %.c src
vpath %.h include

all: $(NAME)
.PHONY: all clean fclean re

$(NAME): $(OBJS)
	$(CC) -o $@ $(DEBUG) $(OBJS) $(LIBFLAGLINUX)
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) -o $@ $(CFLAGS) $(IFLAGS) $<

$(OBJDIR):
	mkdir -p $@

main.o: mrtest.h
$(NAME): ../libft.a

# cleaning crew
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
