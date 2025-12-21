#include "ScavTrap.hpp"

int main( int ac, char **av ) {
	ClapTrap cp("Player0");
	cp.attack("Alien");

	ScavTrap st("Player1");
	st.attack("Earth");
	std::cout << "" << std::endl;

	st.guardGuate();
	std::cout << "" << std::endl;

	std::cout << st << std::endl;
	std::cout << cp << std::endl;

	ScavTrap st_copy(st);
	std::cout << "" << std::endl;

	std::cout << st_copy << std::endl;
	return 0;
}
