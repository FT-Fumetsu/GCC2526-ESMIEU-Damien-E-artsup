#ifndef _POINTSET_HPP_
#define _POINTSET_HPP_

#include <vector>

struct Point {
    double x;
    double y;

    double distanceEuclid(const Point& other) const;
    int distanceManhattan(const Point& other) const;
    int distanceChebyshev(const Point& other) const;
};

class PointSet {
private:
    std::vector<Point> points;
    int width;
    int height;

public:
    PointSet(int n, int width, int height);

    const std::vector<Point>& getPoints() const;
    const Point& operator[](int i) const;
    int size() const;
};

#endif // _POINTSET_HPP_
