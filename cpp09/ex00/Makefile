NAME=btc

FLAGS= -Wall -Wextra -Werror -std=c++98

HEADERS= BitcoinExchange.hpp

SRC= main.cpp BitcoinExchange.cpp

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