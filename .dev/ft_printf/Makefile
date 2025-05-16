# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 09:06:20 by nduvoid           #+#    #+#              #
#    Updated: 2024/11/21 09:32:50 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCDIR =	srcs
LIBFTDIR =	../src
OBJDIR =	./.obj
LIBFT =		$(LIBFTDIR)/libft.a

SRCS =		ft_printf.c \
			put_func.c \
			put_func2.c \
			put_func3.c \
			utils.c
SRC =		$(addprefix $(SRCDIR)/, $(SRCS))
SRCOBJ =	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

AR =		ar
FLAGS =		rcs
RM =		rm -f
CC =		cc
CFLAGS =	-Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(SRCOBJ)
	$(AR) $(FLAGS) $(NAME) $(SRCOBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
