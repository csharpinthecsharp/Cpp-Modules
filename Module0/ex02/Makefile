LE ACCOUNT.CPP EST A 42, LE PLUS RECENT AVEC LE DISPLAY TIME.


NAME	= account
CPP		= c++
CFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS	= Account.cpp \
		  tests.cpp \

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
