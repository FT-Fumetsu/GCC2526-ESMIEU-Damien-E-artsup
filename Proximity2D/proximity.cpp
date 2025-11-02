// TODO continuer l'exo avec ce qu'il m'a donné dans le notion
#include <iostream>
#include <cmath> //fabs
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

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

// TODO : à refaire avec les near functions
bool collisionRect(const vector<pair<double,double>>& rectA,
                   const vector<pair<double,double>>& rectB) 
{
    if (rectA.size() != 4 || rectB.size() != 4) return false;

    double minAx = rectA[0].first, maxAx = rectA[0].first;
    double minAy = rectA[0].second, maxAy = rectA[0].second;
    for (const auto& p : rectA) {
        minAx = min(minAx, p.first);
        maxAx = max(maxAx, p.first);
        minAy = min(minAy, p.second);
        maxAy = max(maxAy, p.second);
    }

    double minBx = rectB[0].first, maxBx = rectB[0].first;
    double minBy = rectB[0].second, maxBy = rectB[0].second;
    for (const auto& p : rectB) {
        minBx = min(minBx, p.first);
        maxBx = max(maxBx, p.first);
        minBy = min(minBy, p.second);
        maxBy = max(maxBy, p.second);
    }

    bool separatedX = (maxAx < minBx) || (maxBx < minAx);
    bool separatedY = (maxAy < minBy) || (maxBy < minAy);
    return !(separatedX || separatedY);
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

    vector<pair<double,double>> rect1 = { {0.0,0.0}, {1.0,0.0}, {1.0,1.0}, {0.0,1.0} };
    vector<pair<double,double>> rect2 = { {0.5,0.5}, {1.5,0.5}, {1.5,1.5}, {0.5,1.5} };
    vector<pair<double,double>> rect3 = { {2.0,2.0}, {3.0,2.0}, {3.0,3.0}, {2.0,3.0} };

    cout << "Rect1 vs Rect2 : " << (collisionRect(rect1, rect2) ? "OVERLAP" : "SEPARATED") << endl;
    cout << "Rect2 vs Rect3 : " << (collisionRect(rect2, rect3) ? "OVERLAP" : "SEPARATED") << endl;
    cout << "Rect1 vs Rect3 : " << (collisionRect(rect1, rect3) ? "OVERLAP" : "SEPARATED") << endl;

    return 0;
}