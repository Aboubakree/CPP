NAME = a.out

SRC = main.cpp Serializer.cpp

OBJ = main.o Serializer.o

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

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
