#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>

class ClapTrap {
	protected:
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
