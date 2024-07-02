NAME	= matrix

CXX			= g++
CXXFLAGS	= -Wall -Werror -Wextra

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm $(OBJS)
.PHONY: fclean
fclean: clean
	rm $(NAME)

.PHONY:re
re: fclean all