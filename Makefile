# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 09:18:47 by srioboo-          #+#    #+#              #
#    Updated: 2025/06/21 11:44:24 by srioboo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
		link_lstclear.c \
		log/operation_log.c

# objects
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): build-libft
	$(CC) $(INCLUDE) $(SRCS) $(LIB_FLAG) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

build-libft:
	@make -C ./libft full

clean-libft:
	@make -C ./libft fclean

# TEST Section
test: all
	$(MAKE) -f src-tests/Makefile test

tclean:
	$(MAKE) -f src-tests/Makefile tclean

# Memory leaks detection
sane:
	$(MAKE) -f src-tests/Makefile sane

val: 
	$(MAKE) -f src-tests/Makefile val

.PHONY: all clean fclean re build-libft clean-libft test tclean
