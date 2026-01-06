#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD      "\033[1m"

class ClapTrap {
	private:
		int _energy;
		int _damage;
		int _health;
		std::string _name;
	public:
		ClapTrap( const std::string &name );
		~ClapTrap();
		ClapTrap( const ClapTrap& cp );
		ClapTrap &operator=( const ClapTrap& cp );

		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );

		void setEnergy( const int& value );
		void setDamage( const int& value );
		void setHealth( const int& value );
		void setName( const std::string& value );
		const int getEnergy() const;
		const int getDamage() const;
		const int getHealth() const;
		const std::string getName() const;
};

std::ostream& operator<<( std::ostream& os, const ClapTrap& cp );
#endif
