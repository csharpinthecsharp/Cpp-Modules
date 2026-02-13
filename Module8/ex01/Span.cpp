#include "Span.hpp"

Span::Span() : _N(0) {

}

Span::Span( unsigned int N ) : _N(N) {

}

Span::~Span() {

}

Span::Span( const Span& sn ) {
    *this = sn;
}

Span &Span::operator=( const Span& sn ) {
    (void)sn;
    return *this;
}

void Span::addNumber( int nb ) {
    if (_N == _container.size())
        throw MaxElementsException();
    _container.push_back(nb);
}

int Span::shortestSpan() const {
    if (_container.size() < 2)
        throw SpanBlankException();

    std::vector<int> temp = _container;
    std::sort(temp.begin(), temp.end());

    int dist = temp.at(1) - temp.at(0);
    for (size_t i(1); i < temp.size(); i++) {
            int diff = temp.at(i) - temp.at(i - 1);
        if (dist > diff)
            dist = diff;
    }
    return dist;
}

int Span::longestSpan() const {
    if (_container.size() < 2)
        throw SpanBlankException();
    std::vector<int>::const_iterator max = std::max_element(_container.begin(), _container.end());
    std::vector<int>::const_iterator min = std::min_element(_container.begin(), _container.end());
    return (*max - *min);
}


std::vector<int> Span::getContainer() const {
    return this->_container;
}

std::ostream &operator<<( std::ostream& os, const Span& sn ) {
    for (size_t i(0); i < sn.getContainer().size(); i++)
        os << sn.getContainer().at(i) << std::endl;
    return os;
}