#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point( const float x, const float y );
        Point( const Point& point );
        Point &operator=( const Point& point );
        ~Point();

        Fixed const getX() const;
        Fixed const getY() const;
};

bool bsp ( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP