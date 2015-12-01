#include "point.hpp"

namespace algorithms {

    bool operator<(const Point &a, const Point &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }

    bool operator==(const Point &a, const Point &b) {
        return a.x == b.x && a.y == b.y;
    }

    std::ostream &operator<<(std::ostream &os, const Point &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

}
