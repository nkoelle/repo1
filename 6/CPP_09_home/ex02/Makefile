
NAME			= ./PmergeMe
CXX				= c++
CXXFLAGS		= -std=c++98 -Wall -Wextra -Werror


SRC				= ./src/main.cpp ./src/PmergeMe.cpp
OBJ				= $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(OBJ) -o $(NAME)

%.o:	%.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

run:	all
	@./$(NAME)

clean:
	@echo "$(RED)rm -f $(OBJ)$(WHITE)"
	@rm -f $(OBJ)

fclean:	clean
	@echo "$(RED)rm -f $(NAME)$(WHITE)"
	@rm -f $(NAME)

re: fclean all