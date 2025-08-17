NAME = a.out

SRC = main.cpp BitcoinExchange.cpp

OBJ = main.o BitcoinExchange.cpp

CXX = c++

CXXFLAGS = -Wextra -Werror -Wall -std=c++98

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all