#include "DiamondTrap.hpp"

int main( int ac, char **av ) {
	ClapTrap cp("ClapTrapPayer");
	cp.attack("Alien");

	ScavTrap st("ScavTrapPlayer");
	FragTrap ft("FragTrapPlayer");

	std::cout << "" << std::endl;
	ft.highFivesGuys();
	std::cout << "" << std::endl;
	st.attack("Earth");
	std::cout << "" << std::endl;

	st.guardGuate();
	st.guardGuate();
	std::cout << "" << std::endl;

	std::cout << st << std::endl;
	std::cout << cp << std::endl;
	std::cout << ft << std::endl;

	ScavTrap st_copy(st);
	std::cout << "" << std::endl;

	std::cout << st_copy << std::endl;
	
	DiamondTrap dt("DiamondPlayer");
	dt.attack("Trump");
	std::cout << dt << std::endl;
	dt.whoAmI();
	return 0;
}
