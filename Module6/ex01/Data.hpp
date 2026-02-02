#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
    private:
        unsigned int _nb_files;
        std::string _subject;
    public:
        Data();
        Data( unsigned int nb_files, const std::string& subject );
        Data( const Data& da );
        Data &operator=( const Data& da );
        ~Data();

        unsigned int getFiles() const;
        const std::string getSubject() const;
};

std::ostream& operator<<( std::ostream& os, const Data& da );

#endif