NAME	= ex10.out

CXX			= g++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++20 -g -fsanitize=address -pthread -I../googletest/googletest/include

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all
all: $(NAME)

$(NAME): test $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ -L../googletest/build/lib -lgtest

test:
	cd .. ; make

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY:re
re: fclean all