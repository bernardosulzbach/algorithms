#pragma once

#include <ostream>

namespace algorithms {

    class Point {
    public:
        Point() : x(0), y(0) { }

        Point(double x_value, double y_value) : x(x_value), y(y_value) { }

        ~Point() { }

        double x;
        double y;

    };

    bool operator<(const Point &a, const Point &b);

    bool operator==(const Point &a, const Point &b);

    std::ostream &operator<<(std::ostream &os, const Point &p);

}
