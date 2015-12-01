#include "point.hpp"

#include <cmath>

namespace algorithms {

    double euclidean_distance(const Point &a, const Point &b) {
        return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
    }

}