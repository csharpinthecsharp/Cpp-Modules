NAME	= fixed
CPP		= c++
CFLAGS	= -std=c++98 -g -Wall -Wextra -Werror

SRCS	= main.cpp \
		  Fixed.cpp  \
		  Point.cpp \
		  bsp.cpp \

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

