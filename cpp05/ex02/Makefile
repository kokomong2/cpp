CC = c++
CFLAGE = -Wall -Werror -Wextra -std=c++98
NAME = ex02
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
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