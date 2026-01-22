#include "PointSet.hpp"
#include <cstdlib>
#include <cmath>
#include <algorithm>

double Point::distanceEuclid(const Point& other) const {
    return std::sqrt((x - other.x)*(x - other.x)
                   + (y - other.y)*(y - other.y));
}

int Point::distanceManhattan(const Point& other) const {
    return std::abs(x - other.x) + std::abs(y - other.y);
}

int Point::distanceChebyshev(const Point& other) const {
    return std::max(std::abs(x - other.x), std::abs(y - other.y));
}

PointSet::PointSet(int n, int w, int h)
    : width(w), height(h)
{
    points.resize(n);
    for (auto& p : points) {
        p.x = rand() % width;
        p.y = rand() % height;
    }
}

const std::vector<Point>& PointSet::getPoints() const {
    return points;
}

const Point& PointSet::operator[](int i) const {
    return points[i];
}

int PointSet::size() const {
    return points.size();
}
