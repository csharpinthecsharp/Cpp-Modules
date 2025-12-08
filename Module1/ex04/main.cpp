#include "Sed.hpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "sed: 3 params required (<filename> <s1> <s2>)!"
			<< std::endl;
		return 1;
	}
	Sed sed = Sed(av[1], av[2], av[3]);
	if (!sed.isExist())
		return 1;
	sed.findAndReplace();
	return 0;
}
