NAME = violence
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ = ${SRC:.cpp=.o}
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

%.o:%.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $^

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
