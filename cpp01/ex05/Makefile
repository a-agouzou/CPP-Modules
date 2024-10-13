NAME=harl

FLAGS= -Wall -Wextra -Werror -std=c++98

HEADER = Harl.hpp

SRC= main.cpp Harl.cpp

OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJ)
	c++ $(FLAGS) $(OBJ) -o $@

%.o: %.cpp $(HEADER)
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean clean re