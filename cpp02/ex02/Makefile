NAME = fixed
CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address

SRC  = main.cpp Fixed.cpp

OBJ = $(SRC:.cpp=.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@rm -rf $(OBJ)
	@echo "\033[0;32mDone    \033[0m"
							
clean:
	@rm -f $(OBJ)
	@echo "\033[0;33mCleaned \033[0m"

fclean:
	@rm -f $(NAME) $(OBJ)
	@echo "\033[0;31mFcleaned \033[0m"

re: fclean all clean