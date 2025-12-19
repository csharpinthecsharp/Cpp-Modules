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

        float const getX() const;
        float const getY() const;
};

float formula(Point const& e, Point const& f, Point const& h);
bool bsp ( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP