#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <iomanip>

class Zombie {
    public:
        void announce( void );
        void announce_heap( void );

        Zombie( std::string name );
        ~Zombie( void );
    private:
        std::string _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif