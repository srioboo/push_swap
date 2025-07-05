# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 09:18:47 by srioboo-          #+#    #+#              #
#    Updated: 2025/07/05 16:44:01 by srioboo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW= \033[33m
COLOUR_MAGENTA=\033[35m
COLOUR_TURQUOISE=\033[36m	
COLOUR_END=\033[0m

# library name
NAME = push_swap

# compliler and compiler flags
CC = @cc
CFLAGS = -Wall -Wextra -Werror

# auxiliary commands
RM = @rm -f

# directories
INCLUDE = -Ilibft/src -Ilibft/ft_printf
LIB_FLAG = -Llibft -l:libft.a

# source files
SRCS = push_swap.c \
		push_swap_utils.c \
		push_swap_utils_msg.c \
		push_swap_validate.c \
		push_swap_normalize.c \
		operation_rev_rotate.c \
		operation_main.c \
		operation_push.c \
		operation_rotate.c \
		operation_swap.c \
		link_lstnew.c \
		link_lstlast.c \
		link_lstadd_back.c \
		link_lstadd_front.c \
		link_lstsize.c \
		link_lstclear.c

# objects
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): build-libft $(OBJECTS)
	@$(CC) $(OBJECTS) $(INCLUDE) $(LIB_FLAG) -o $(NAME)
	@echo "$(COLOUR_GREEN)\npush_swap compiled!\n$(COLOUR_END)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(COLOUR_BLUE)Compiling: $(COLOUR_END)$<"

clean:
	$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

build-libft:
	@$(MAKE) -C ./libft full
	@echo "$(COLOUR_YELLOW)Compiling Libft $(COLOUR_END)"
	@echo "$(COLOUR_GREEN)\nlibft compiled!\n$(COLOUR_END)"

clean-libft:
	@$(MAKE) -C ./libft fclean

# TEST Section
test: all
	@$(MAKE) -f src-tests/Makefile test

tclean:
	@$(MAKE) -f src-tests/Makefile tclean

# Memory leaks detection
sane:
	@$(MAKE) -f src-tests/Makefile sane

val: 
	@$(MAKE) -f src-tests/Makefile val

.PHONY: all clean fclean re build-libft clean-libft test tclean
