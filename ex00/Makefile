NAME        = megaphone
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -O2 -g #--MMD

SRC         = megaphone.cpp
OBJ         = $(SRC:.cpp=.o)
DEPS        = $(OBJ:.o=.d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include $(DEPS)

clean:
	rm -f $(OBJ) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all
