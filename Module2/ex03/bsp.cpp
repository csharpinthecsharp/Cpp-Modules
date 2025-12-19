#include "Point.hpp"

/* For edge AB and point P, the cross product is:
    (Bx - Ax)(Py - Ay) - (By - Ay)(Px - Ax)
- Positive value: H is on the LEFT side of line EF (counter-clockwise)
- Negative value: H is on the RIGHT side of line EF (clockwise)
- Zero: H is exactly ON the line EF
*/

float formula(Point const& e, Point const& f, Point const& h) {
    return (f.getX() - e.getX()) * (h.getY() - e.getY()) - (f.getY() - e.getY()) * (h.getX() - e.getX());
}
    
bool bsp ( Point const a, Point const b, Point const c, Point const point) {
    float d1 = formula(a, b, point);
    float d2 = formula(b, c, point);
    float d3 = formula(c, a, point);

    std::cout << "d1: " << d1 << std::endl;
    std::cout << "d2: " << d2 << std::endl;
    std::cout << "d3: " << d3 << std::endl;

    // Point is inside if all cross products have the same sign (all positive OR all negative)
    return (d1 < 0 && d2 < 0 && d3 < 0) || (d1 > 0 && d2 > 0 && d3 > 0);
}