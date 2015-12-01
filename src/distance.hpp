#pragma once

#include "point.hpp"

#include <vector>
#include <algorithm>
#include <set>

namespace algorithms {

    double euclidean_distance(const Point &a, const Point &b);

    struct VerticalPointComparator {
        bool operator()(const Point &a, const Point &b) {
            return a.y < b.y;
        }
    };

    /**
     * Returns the two points closest to each other between begin and end according to their euclidean distance.
     *
     * This algorithm has O(n lg n) time complexity.
     *
     * If there is less than two points, returns a pair of default-initialized points.
     */
    template<typename InputIterator>
    std::pair<Point, Point> closest_pair_of_points(InputIterator begin,
                                                   InputIterator end) {
        if (std::distance(begin, end) < 2) return std::pair<Point, Point>();
        std::vector<Point> points(begin, end);
        std::sort(points.begin(), points.end());
        std::vector<Point>::const_iterator tail = points.begin();
        std::vector<Point>::const_iterator head = points.begin() + 1;
        double minimum_distance = euclidean_distance(*tail, *head);
        std::pair<Point, Point> best_pair = std::make_pair(*tail, *head);
        std::set<Point, VerticalPointComparator> candidates(tail, head);
        // Add the current head to the candidate set and select new head.
        candidates.insert(*head++);
        while (head != points.end()) {
            // Remove candidates that are too far horizontally.
            while ((head->x - tail->x) > minimum_distance) {
                candidates.erase(*tail++);
            }
            // Select all candidates that are not too far vertically.
            Point minimum_y(head->x, head->y - minimum_distance);
            Point maximum_y(head->x, head->y + minimum_distance);
            auto candidates_begin = candidates.lower_bound(minimum_y);
            auto candidates_end = candidates.upper_bound(maximum_y);
            // Compute all distances.
            while (candidates_begin != candidates_end) {
                double distance = euclidean_distance(*candidates_begin, *head);
                if (distance < minimum_distance) {
                    minimum_distance = distance;
                    best_pair = std::make_pair(*candidates_begin, *head);
                }
                candidates_begin++;
            }
            // Add the current head to the candidate set and select new head.
            candidates.insert(*head++);
        }
        return best_pair;
    }

    template<typename InputIterator>
    double minimum_distance(InputIterator begin, InputIterator end) {
        const std::pair<Point, Point> &points = closest_pair_of_points(begin, end);
        return euclidean_distance(points.first, points.second);
    }

}
