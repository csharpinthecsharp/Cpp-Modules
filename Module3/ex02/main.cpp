#include "FragTrap.hpp"

int main( int ac, char **av ) {
	ClapTrap cp("Tortank");
	FragTrap ft("Pikachu");
	std::cout << cp << std::endl;
	std::cout << ft << std::endl;
	cp.attack("Raichu");
	ft.attack("Rayquaza");
	cp.takeDamage(5);
	ft.takeDamage(10);
	std::cout << cp << std::endl;
	std::cout << ft << std::endl;
	ft.highFivesGuys();
	return 0;
}
