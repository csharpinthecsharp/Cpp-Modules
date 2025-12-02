NAME	= phonebook
CPP		= c++
CFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS	= phonebook.cpp \
		  phonebook.class.cpp \
		  phonebook.getter.cpp \
		  phonebook.utils.cpp \


OBJS	= $(SRCS:.cpp=.o)
all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make clean

re: fclean all

.PHONY: all clean fclean re
