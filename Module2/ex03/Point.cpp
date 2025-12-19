#include "Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point( const float x, const float y) : x(x), y(y) {
}

Point::Point( const Point& point) {
    *this = point;
}

Point &Point::operator=( const Point& point) {
    if (this != &point)
		new (this)Point(point.getX(), point.getY());
    return *this;
}

float const Point::getX() const {
    return this->x.toFloat();
}

float const Point::getY() const {
    return this->y.toFloat();
}


Point::~Point() {
}
