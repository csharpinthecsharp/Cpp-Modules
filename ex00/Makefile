NAME	= megaphone
CPP		= clang++
CFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS	= megaphone.cpp \

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
