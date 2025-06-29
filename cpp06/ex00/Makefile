NAME = a.out

SRC = main.cpp ScalarConverter.cpp

OBJ = main.o ScalarConverter.o

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

all : $(NAME)

clean :
	@rm -rf $(OBJ)
	@echo "clean done !"

fclean : clean
	@rm -rf $(NAME)
	@echo "fclean done !"

re : fclean all