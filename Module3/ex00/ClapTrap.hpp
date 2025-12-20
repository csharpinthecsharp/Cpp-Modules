#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

class ClapTrap {
	private:
		int _energy;
		int _damage;
		int _health;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap( const ClapTrap& cp );
		ClapTrap=operato
		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
};
#endif
