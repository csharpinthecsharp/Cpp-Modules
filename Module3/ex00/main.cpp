#include "ClapTrap.hpp"

int main( int ac, char **av ) {
	ClapTrap cp("Player1");
	ClapTrap cp_copy("Player3");
	std::cout << "" << std::endl;

	cp.attack("Player2");
	cp.beRepaired(21);
	cp.takeDamage(20);
	cp.takeDamage(11);
	cp.attack("Player2");
	cp.takeDamage(100);
	std::cout << "" << std::endl;

	std::cout << cp << std::endl;

	cp_copy = cp;
	std::cout << "" << std::endl;

	std::cout << cp_copy << std::endl;
	return 0;
}
