# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 21:55:36 by adjemaa           #+#    #+#              #
#    Updated: 2021/11/01 21:10:33 by adjemaa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	containers

SRCS	=	main.cpp \
			mdebug.cpp \
			debug.cpp \
			sdebug.cpp

OBJS	=	$(SRCS:.cpp=.o)

CC		=	clang++

FLAGS	=	-std=c++98

%.o:		%.cpp
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

std:
			clang++ -Wall -Werror -Wextra -std=c++98 std_main.cpp -o std_containers
clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)
			rm -f std_containers

re:			fclean all
