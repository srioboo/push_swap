# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 09:18:47 by srioboo-          #+#    #+#              #
#    Updated: 2025/02/25 18:38:42 by srioboo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# library name
NAME = push_swap

# compliler and compiler flags
CC = @cc
CFLAGS = -Wall -Wextra -Werror

# auxiliary commands
RM = @rm -f

# source files
SRCS = push_swap.c \
		push_swap_utils.c
# objects
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) -Llib -l:libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

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

.PHONY: all clean fclean re test tclean
