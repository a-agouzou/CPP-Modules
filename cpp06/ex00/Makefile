NAME= convert

FLAGS = -Wall -Werror -Wextra -std=c++98

HEADERS= ScalarConverter.hpp

SRC = ScalarConverter.cpp main.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $@

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY:  all clean fclean