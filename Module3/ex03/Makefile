NAME	= diamondtrap
CPP	= c++
CFLAGS	= -std=c++98 -Wshadow -g -Wall -Wextra -Werror

SRCS	= main.cpp \
	  ClapTrap.cpp  \
	  ScavTrap.cpp  \
	  FragTrap.cpp \
	  DiamondTrap.cpp \

OBJS	= $(SRCS:.cpp=.o)

GREEN = \033[0;32m
BOLD = \033[1m
RESET = \033[0m

all: $(NAME)
	@echo ""
	@echo "$(GREEN)$(BOLD) ==== ./diamondtrap to run ===="
	@echo ""

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make clean

re: fclean all

.PHONY: all clean fclean re

