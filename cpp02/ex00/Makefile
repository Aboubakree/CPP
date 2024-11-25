NAME = fixed

SRC = main.cpp Fixed.cpp

OBJ = ${SRC:.cpp=.o}

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $^

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
