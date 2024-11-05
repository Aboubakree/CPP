NAME = phonebook

SRC = PhoneBook.cpp main.cpp Contact.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

%.o : %.cpp
	$(CC) ${CPPFLAGS} -o $@ -c $^

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) ${CPPFLAGS} -o ${NAME} ${SRC}
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.SECONDARY : $(OBJ)
