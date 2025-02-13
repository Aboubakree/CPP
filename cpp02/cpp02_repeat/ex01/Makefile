NAME = a.out

SRC = main.cpp Fixed.cpp

OBJ = ${SRC:.cpp=.o}

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all