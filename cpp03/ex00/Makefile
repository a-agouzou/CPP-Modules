
NAME= claptrap

FLAGS= -Wall -Wextra -Werror -std=c++98

HEADER= ClapTrap.hpp

SRC= main.cpp ClapTrap.cpp

OBJ=$(SRC:.cpp=.o)

all: $(NAME)


$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $@

%.o:%.cpp $(HEADER)
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re