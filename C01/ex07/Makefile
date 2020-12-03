# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/28 10:33:39 by lucaslefran       #+#    #+#              #
#    Updated: 2020/12/03 11:59:30 by lucaslefran      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	newsed
CC			=	clang++
FLAGS		=	-g -fsanitize=address -Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp
OBJS		=	$(SRCS:.cpp=.o)

all		: 	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) -o $(NAME) $(FLAGS) $(OBJS)

$(OBJS)	:	$(HEADER)

clean	:	
				rm -rf $(OBJS)

fclean	:	clean
				rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

%.o		:	%.cpp
			$(CC) $(FLAGS) -o $@ -c $<
# for creating .o with flags