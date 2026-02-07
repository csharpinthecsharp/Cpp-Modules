#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {
    private:
        T* _array;
        size_t _size;
    public:
        Array() :_size(0) {             
            _array = new T[_size];
            for (unsigned int i(0); i < _size; i++) {
                _array[i] = T();
            }
        } 

        Array( unsigned int n ) : _size(n) {
            _array = new T[_size];
            for (unsigned int i(0); i < _size; i++) {
                _array[i] = T();
            }
        } 

        ~Array() { delete[] _array; }

        Array( const Array& ay ) { *this = ay; }

        Array &operator=( const Array& ay ) {
            if (this != &ay) {
                this->_size = ay._size;
                for (unsigned int i(0); i < this->_size; i++) {
                    this->_array[i] = ay._array[i];
                }
            }
            return *this;
        }
        
        T &operator[]( unsigned int i ) const {
            if (this->size() < i)
                throw OutOfBoundsException();
            return this->_array[i]; 
        }

        unsigned size() const { return _size; }

        void setArrayAtIndex( const T& content, unsigned int i ) { (*this)[i] = content; }

        class OutOfBoundsException : public std::exception {
            public:
                const char* what() const throw() {
                    return "index is out of bounds";
                }
        };
};

template <typename T> std::ostream& operator<<(std::ostream& os, const Array<T>& ay ) {
    for (unsigned int i(0); i < ay.size(); i++) {
        os << ay[i];
        if (i + 1 != ay.size())
            os << std::endl;
    }
    return os;
}
#endif