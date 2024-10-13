NAME=dynamic

FLAGS= -Wall -Wextra -Werror -std=c++98

HEADERS= Base.hpp C.hpp A.hpp B.hpp

SRC= main.cpp Base.cpp A.cpp B.cpp C.cpp

OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $@

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all re fclean clean