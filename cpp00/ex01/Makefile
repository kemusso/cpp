NAME     = phonebook
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98
SRCS     = main.cpp Contact.cpp PhoneBook.cpp
OBJS     = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS): Contact.hpp PhoneBook.hpp

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
