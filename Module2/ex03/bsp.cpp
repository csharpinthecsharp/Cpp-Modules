#include "Point.hpp"

bool bsp ( Point const a, Point const b, Point const c, Point const point) {
    float x = a.getX().toFloat() + b.getX().toFloat() + c.getX().toFloat();
    float y = a.getY().toFloat() + b.getX().toFloat() + c.getX().toFloat();
    //determine if inside;
    if ( true )
        return true;
    return false;
}