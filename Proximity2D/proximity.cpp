#include <iostream>
#include <cmath> //fabs
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random> //mt19937 && random_device
#include <chrono>

using namespace std;

struct Point2D{
    string name;
    double x;
    double y;
};

bool near2D_euclid(const Point2D& a, const Point2D& b, double seuil){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dist = sqrt(dx * dx + dy * dy);
    return dist <= seuil;
}

bool near2D_euclid_optimised(const Point2D& a, const Point2D& b, double seuil){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dist = dx * dx + dy * dy;
    return dist <= seuil * seuil;
}

bool near2D_manh(const Point2D& a, const Point2D& b, double seuil){
    double dx = fabs(a.x - b.x);
    double dy = fabs(a.y - b.y);
    double manh = dx + dy;
    return manh <= seuil;
}

void displayPoint(const Point2D& p){
    cout << p.name 
         << " (x=" << fixed << setprecision(3) << p.x 
         << ", y=" << p.y << ")" << endl;
}

bool collisionCircle(const Point2D& a, double rayonA, const Point2D& b, double rayonB){
    double seuil = rayonA + rayonB;
    return near2D_euclid_optimised(a, b, seuil);
}

bool collisionRect_naif(double minX1, double minY1, double maxX1, double maxY1,
                        double minX2, double minY2, double maxX2, double maxY2) {
    bool overlapX = (minX1 <= maxX2) && (maxX1 >= minX2);
    bool overlapY = (minY1 <= maxY2) && (maxY1 >= minY2);
    return overlapX && overlapY;
}

struct Rectangle{
    Point2D min;
    Point2D max;
};

bool strong_collisionRect(const Rectangle& r1, const Rectangle& r2) {
    bool overlapX = (r1.min.x <= r2.max.x) && (r1.max.x >= r2.min.x);
    bool overlapY = (r1.min.y <= r2.max.y) && (r1.max.y >= r2.min.y);
    return overlapX && overlapY;
}

std::vector<Rectangle> generate_rectangles(size_t n, double worldSize, double minSize, double maxSize) {
    std::vector<Rectangle> out;
    out.reserve(n);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> posDist(0.0, worldSize);
    std::uniform_real_distribution<double> sizeDist(minSize, maxSize);

    for (size_t i = 0; i < n; ++i) {
        double cx = posDist(gen);
        double cy = posDist(gen);
        double w = sizeDist(gen);
        double h = sizeDist(gen);

        double halfW = w * 0.5;
        double halfH = h * 0.5;

        double minX = std::max(0.0, cx - halfW);
        double minY = std::max(0.0, cy - halfH);
        double maxX = std::min(worldSize, cx + halfW);
        double maxY = std::min(worldSize, cy + halfH);

        if (maxX < minX) std::swap(minX, maxX);
        if (maxY < minY) std::swap(minY, maxY);

        Rectangle r;
        r.min.name = "min";
        r.min.x = minX;
        r.min.y = minY;
        r.max.name = "max";
        r.max.x = maxX;
        r.max.y = maxY;

        out.push_back(r);
    }
    return out;
}

std::pair<long long, std::uint64_t>
measure_naive_pairwise(const std::vector<Rectangle>& rects) {
    using clock = std::chrono::steady_clock;
    auto t0 = clock::now();

    std::uint64_t collisions = 0;
    size_t n = rects.size();
    for (size_t i = 0; i < n; ++i) {
        double minX1 = rects[i].min.x;
        double minY1 = rects[i].min.y;
        double maxX1 = rects[i].max.x;
        double maxY1 = rects[i].max.y;
        for (size_t j = i + 1; j < n; ++j) {
            double minX2 = rects[j].min.x;
            double minY2 = rects[j].min.y;
            double maxX2 = rects[j].max.x;
            double maxY2 = rects[j].max.y;

            if (collisionRect_naif(minX1, minY1, maxX1, maxY1,
                                   minX2, minY2, maxX2, maxY2)) {
                ++collisions;
            }
        }
    }

    auto t1 = clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count();
    return {dur, collisions};
}

int main() {
    Point2D A{"A", 0.0, 0.0};
    Point2D B{"B", 1.2, 0.9};
    Point2D C{"C", 3.0, 4.0};
    Point2D D{"D", 0.4, -0.3};

    cout << "Points :" << endl;
    displayPoint(A);
    displayPoint(B);
    displayPoint(C);
    displayPoint(D);
    cout << endl;

    double seuils[] = {0.5, 1.0, 2.5, 5.0};
    for (double s : seuils) {
        cout << "Seuil = " << s << endl;

        cout << " A-B : Euclidien = " << (near2D_euclid(A,B,s) ? "PROCHE" : "LOIN")
             << " | Manhattan = " << (near2D_manh(A,B,s) ? "PROCHE" : "LOIN") << endl;

        cout << " A-C : Euclidien = " << (near2D_euclid(A,C,s) ? "PROCHE" : "LOIN")
             << " | Manhattan = " << (near2D_manh(A,C,s) ? "PROCHE" : "LOIN") << endl;

        cout << " B-D : Euclidien = " << (near2D_euclid(B,D,s) ? "PROCHE" : "LOIN")
             << " | Manhattan = " << (near2D_manh(B,D,s) ? "PROCHE" : "LOIN") << endl;

        cout << endl;
    }

    cout << "Tests collision cercles :" << endl;
    double rA = 0.5, rB = 1.0, rC = 0.7;

    cout << "A(r=" << rA << ") vs B(r=" << rB << ") : "
         << (collisionCircle(A, rA, B, rB) ? "COLLISION" : "NO COLLISION") << endl;

    cout << "A(r=" << rA << ") vs C(r=" << rC << ") : "
         << (collisionCircle(A, rA, C, rC) ? "COLLISION" : "NO COLLISION") << endl;

    cout << endl;

    Rectangle r1{{"r1_min", 0.0, 0.0}, {"r1_max", 1.0, 1.0}};
    Rectangle r2{{"r2_min", 0.5, 0.5}, {"r2_max", 1.5, 1.5}};
    Rectangle r3{{"r3_min", 2.0, 2.0}, {"r3_max", 3.0, 3.0}};

    std::cout << (strong_collisionRect(r1,r2) ? "OVERLAP" : "NON OVERLAP") 
              << " (attendu 'OVERLAP')\n";
    std::cout << (strong_collisionRect(r1,r3) ? "OVERLAP" : "NON OVERLAP") 
              << " (attendu 'NON OVERLAP')\n";
    
    size_t n1 = 1000;
    cout << "Génération de " << n1 << " rectangles..." << endl;
    auto rects1 = generate_rectangles(n1, /*worldSize=*/1000.0, /*minSize=*/1.0, /*maxSize=*/20.0);
    cout << "Mesure en cours pour " << n1 << " objets (pairwise)..." << endl;
    auto res1 = measure_naive_pairwise(rects1);
    cout << "Résultat: durée = " << res1.first << " ms, collisions detectées = " << res1.second << "\n\n";

    size_t n2 = 10000;
    cout << "Génération de " << n2 << " rectangles..." << endl;
    auto rects2 = generate_rectangles(n2, /*worldSize=*/1000.0, /*minSize=*/1.0, /*maxSize=*/20.0);
    cout << "Mesure en cours pour " << n2 << " objets (pairwise)..." << endl;
    auto res2 = measure_naive_pairwise(rects2);
    cout << "Résultat: durée = " << res2.first << " ms, collisions detectées = " << res2.second << "\n\n";

    cout << "=== Fin des mesures ===\n";
    return 0;
}