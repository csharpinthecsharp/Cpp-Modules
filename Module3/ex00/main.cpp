#include "ClapTrap.hpp"

int main( int ac, char **av ) {
	ClapTrap cp("Kevin");
	std::cout << cp << std::endl;
	cp.attack("Eeath");
	std::cout << cp << std::endl;
	cp.takeDamage(9);
	cp.beRepaired(1);
	std::cout << cp << std::endl;
	cp.takeDamage(2);

	ClapTrap cp_copy(cp);
	std::cout << cp_copy << std::endl;
	cp_copy.attack("Mars");
	cp_copy.takeDamage(5);

	cp_copy.beRepaired(1);
	std::cout << cp_copy << std::endl;
	return 0;
}
