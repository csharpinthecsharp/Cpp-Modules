#include "ScavTrap.hpp"

int main( int ac, char **av ) {
	ClapTrap cp("Diego");
	ScavTrap st("José");
	std::cout << cp << std::endl;
	std::cout << st << std::endl;
	st.attack("Earth");
	cp.attack("Mars");
	std::cout << cp << std::endl;
	std::cout << st << std::endl;
	st.guardGuate();
	st.guardGuate();
	return 0;
}
