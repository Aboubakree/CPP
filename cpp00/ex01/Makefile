NAME = phonebook

SRC = PhoneBook.cpp main.cpp Contact.cpp utils.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

%.o : %.cpp
	$(CPP) ${CPPFLAGS} -o $@ -c $^

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) ${CPPFLAGS} -o ${NAME} ${SRC}
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.SECONDARY : $(OBJ)
