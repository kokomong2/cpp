CC = c++
CFLAGE = -Wall -Werror -Wextra -std=c++98
NAME = ex01
SRCS = main.cpp Converter.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGE) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGE) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re