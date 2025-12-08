#include "Sed.hpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "better_sed: 3 params required (<filename> <s1> <s2>)!"
			<< std::endl;
		return 0;
	}
	Sed sed = Sed(av[1], av[2], av[3]);
	if (!sed.isExist())
		return 1;
}
