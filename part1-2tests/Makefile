# FILES
NAME = a.out
SRC = $(shell find ./src/ -name "*.c" -exec basename {} \;)
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

# Compilation
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
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
	$(CC) -o $@ $(DEBUG) $^ $(LIBFLAGLINUX)
$(OBJDIR)/%.o: %.c
	$(CC) -o $@ $(CFLAGS) $(IFLAGS) $<

main.o: mrtest.h
$(NAME): ../libft.a

# cleaning crew
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
