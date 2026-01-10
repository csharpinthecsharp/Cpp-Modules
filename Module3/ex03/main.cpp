#include "DiamondTrap.hpp"

int main( int ac, char **av ) {
	DiamondTrap dt("DiamondPlayer");
	std::cout << dt << std::endl;
	dt.attack("Pikachu");
	dt.highFivesGuys();
	dt.guardGuate();
	dt.whoAmI();
	return 0;
}
