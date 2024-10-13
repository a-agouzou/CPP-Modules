NAME=recap

FLAGS= -Wall -Wextra -Werror -std=c++98

HEADERS= AMateria.hpp Character.hpp ICharacter.hpp Ice.hpp Cure.hpp IMateriaSource.hpp MateriaSource.hpp

SRC= main.cpp AMateria.cpp Ice.cpp Cure.cpp MateriaSource.cpp Character.cpp

OBJ = $(SRC:.cpp=.o) 

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $@

%.o:%.cpp $(HEADERS)
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean clean re