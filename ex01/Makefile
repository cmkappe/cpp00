NAME        = phonebook
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -O2 -g -std=c++17 #--MMD -fsanitize=address -fno-omit-frame-pointer

SRC_DIR	 	= .
OBJ_DIR	 	= src_o
SRC         = main.cpp Contact.cpp Phonebook.cpp
OBJ         = $(SRC:.cpp=.o)
DEPS        = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.d, $(SRC))
DEPS		= $(OBJ:.o=.d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -MMD -c $< -o $@
-include $(DEPS)

$(OBJ_DIR):
	@mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR) $(DEPS)

fclean: clean
	rm -f $(NAME) $(OBJ)

re: fclean all
