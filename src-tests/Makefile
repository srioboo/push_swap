# Library name
LIB_TEST_NAME = libfuntest.a

# Library to test, add here your libs to test
LIB_TESTED = libft/libft.a

# Compiler and flags for compilation
CC = cc
CFLAGS = -Wall -Werror -Wextra

## Name of the test main executable
TEST_DIR = src-tests
TEST_BIN = test.out
# Directories
INCLUDE = -I$(TEST_DIR)/include -Iinclude -Ilibft/src
LIB_FLAG = -L$(TEST_DIR)/lib -l:$(LIB_TEST_NAME)

## Library Test source and objects
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS = $(TEST_SRCS:.c=.o)

# source files
SRCS = push_swap_utils.c \
		push_swap_validate.c \
		operation_rev_rotate.c \
		operation_main.c \
		operation_push.c \
		operation_rotate.c \
		operation_swap.c \
		link_lstnew.c \
		link_lstlast.c \
		link_lstadd_back.c \
		link_lstsize.c

# Test: generate test binary
test:
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCS) $(TEST_SRCS) $(LIB_TESTED) $(LIB_FLAG) -o $(TEST_BIN)
	./$(TEST_BIN)

# clean test directories
tclean:
	$(RM) $(TEST_DIR)/$(TEST_OBJS) $(TEST_BIN)

# Memory leaks detection
sane:
	$(CC) $(CFLAGS) -Iinclude $(TEST_SRCS) $(LIB_TESTED) -L$(LIB) -l:$(LIB_TEST_NAME) -o $(TEST_BIN) -fsanitize=address -g
	./$(TEST_BIN)

val:
	$(CC) $(CFLAGS) -I$(INCLUDE) $(TEST_SRCS) $(LIB_TESTED) -L$(LIB) -l:$(LIB_TEST_NAME) -o $(TEST_BIN)
	valgrind --leak-check=full ./$(TEST_BIN)

.PHONY: test tclean sane val