# LIBFT SETTINGS
include Settings.mk

# Names
NAME = mrtest.out
NAME_BONUS = bonus_mrtest.out
EXECS = $(NAME) $(NAME_BONUS)
LFT = $(LFT_LOCATION)/$(LFT_NAME)

# Source Files
IMPDIR = implementation
SDIR = $(IMPDIR)/src
ODIR = $(IMPDIR)/obj
DDIR = $(IMPDIR)/dep
IDIR = $(IMPDIR)/includes
LDIR = $(LFT_LOCATION)

ifdef BONUS
	ODIR = $(IMPDIR)/obj/bonus
	DDIR = $(IMPDIR)/dep/bonus
	NAME = $(NAME_BONUS)
else
	SDIR = $(IMPDIR)/src/mandatory
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
DEPENDENCIES := Makefile

# Compilation
all:
	@$(MAKE) -C $(LFT_LOCATION) -j4
	@$(MAKE) $(NAME) -j4

$(NAME): $(OBJ) $(LFT)
		@echo Compiling $@
		@$(CC) -o $@ $(OBJ) $(LFLAGS)
$(OBJ): $(ODIR)/$(SUBDIR)%.o: $(SDIR)/%.c $(DEPENDENCIES)
		@mkdir -p $(@D)
		@echo "Compling: $@"
		@$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)
$(DDIR)/$(SUBDIR)%.d: $(SDIR)/%.c
		@mkdir -p $(@D)
		@echo "Creating Dependency Rule: $@"
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

# CI Compilation Test
.PHONY: TEST_OBJ
TEST_OBJ:
	@echo Compiling object files only
	@$(MAKE) $(OBJ) -j4
