# LIBFT SETTINGS
include Settings.mk

# Names
NAME = mrtest.out
NAME_BONUS = bonus_mrtest.out
EXECS = $(NAME) $(NAME_BONUS)
LFT = $(LFT_LOCATION)/$(LFT_NAME)

# Source Files
SDIR = src
ODIR = obj
DDIR = dep
IDIR = includes
LDIR = $(LFT_LOCATION)

ifdef BONUS
	ODIR = obj/bonus
	DDIR = dep/bonus
	NAME = $(NAME_BONUS)
else
	SDIR = src/mandatory
endif # Bonus

# Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L$(LFT_LOCATION) -lft
IFLAGS = -I$(IDIR)

# Files
SRC := $(shell find $(SDIR) -name "*.c" -type f)
OBJ := $(patsubst $(SDIR)/%.c,$(ODIR)/%.o,$(SRC))
DEP := $(patsubst $(SDIR)/%.c,$(DDIR)/%.d,$(SRC))

# Compilation
all:
	@$(MAKE) -C $(LFT_LOCATION) -j8
	@$(MAKE) $(NAME) -j8

$(NAME): $(OBJ) $(LFT)
		$(CC) -o $@ $(OBJ) $(LFLAGS)
$(OBJ): $(ODIR)/$(SUBDIR)%.o: $(SDIR)/%.c Makefile
		@mkdir -p $(@D)
		$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)
$(DDIR)/$(SUBDIR)%.d: $(SDIR)/%.c
		@mkdir -p $(@D)
		@$(CC) $< -MM -MF $@ -MT $(ODIR)/$(SUBDIR)$*.o $(CFLAGS) $(IFLAGS)

$(LFT):
	$(MAKE) -C $(LFT_LOCATION)

.PHONY: clean fclean re
clean:
	$(RM) -r $(ODIR) $(DDIR)
fclean: clean
	$(RM) $(EXECS)
re: fclean
	$(MAKE) all

.PHONY: bonus
bonus:
	$(MAKE) all BONUS=1

-include $(DEP)
