NAME = a.out

SRC = main.cpp Span.cpp

OBJ = main.o Span.o

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