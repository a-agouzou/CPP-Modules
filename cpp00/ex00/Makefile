# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 19:06:42 by aagouzou          #+#    #+#              #
#    Updated: 2023/10/09 22:32:07 by aagouzou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= megaphone

FLAGS = -Wall -Werror -Wextra -std=c++98

FILES = megaphone.cpp
OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $@

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

.PHONY:  all clean fclean
	