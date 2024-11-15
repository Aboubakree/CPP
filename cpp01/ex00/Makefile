NAME = zombie
SRC = main.cpp Zombie.cpp randomChump.cpp newZombie.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

%.o : %.cpp
	$(CPP) ${CPPFLAGS} -o $@ -c $^

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) ${CPPFLAGS} -o ${NAME} ${OBJ}
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.SECONDARY : $(OBJ)
