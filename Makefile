# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palvare2 <palvare2@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/20 19:32:49 by palvare2          #+#    #+#              #
#    Updated: 2026/05/20 19:46:19 by palvare2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	get_next_line.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	get_next_line.c \
				get_next_line_utils.c

OBJS		=	$(SRCS:.c=.o)

RM			=	rm -f

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
