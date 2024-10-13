NAME=animal

FLAGS= -Wall -Wextra -Werror -std=c++98

HEADERS= Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

SRC= Animal.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp

OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $@

%.o: %.cpp $(HEADERS)
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all re fclean clean