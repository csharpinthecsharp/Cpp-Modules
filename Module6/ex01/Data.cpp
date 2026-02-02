#include "Data.hpp"

Data::Data() :
_nb_files(100),
_subject("Default") {
    std::cout << "Data constructor called" << std::endl;
}

Data::Data( unsigned int nb_files, const std::string& subject ) :
_nb_files(nb_files),
_subject(subject) {
    std::cout << "Data param constructor called" << std::endl;
}

Data::Data( const Data& da ) {
    std::cout << "Data copy constructor called" << std::endl;
    *this = da;
}

Data &Data::operator=( const Data& da ) {
    if (this != &da) {
        this->_nb_files = da._nb_files;
        this->_subject = da._subject;
    }
    std::cout << "Data copy assignment operator called" << std::endl;
    return (*this);
}

Data::~Data() {
    std::cout << "Data destructor called" << std::endl;
}

unsigned int Data::getFiles() const {
    return this->_nb_files;
}

const std::string Data::getSubject() const {
    return this->_subject;
}

std::ostream& operator<<( std::ostream& os, const Data& da ) {
    os << "=== Data ===" << std::endl;
    os << "Subject: " << da.getSubject() << std::endl;
    os << "Files: " << da.getFiles() << std::endl;
    os << "=== EOF DATA ===" << std::endl;
    return os;
}
