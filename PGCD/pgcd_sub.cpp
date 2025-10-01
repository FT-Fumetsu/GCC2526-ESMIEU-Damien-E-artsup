#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int pgcd_sub(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (a == 0 && b == 0) return 0;
    if (a == 0) return b;
    if (b == 0) return a;

    while (a != b) {
        if (a > b) a = a - b;
        else       b = b - a;
    }
    return a;
}

void run_test(int a, int b) {
    cout << "PGCD(" << a << ", " << b << ") = " << pgcd_sub(a, b) << "\n";
}

int main() {
    vector<pair<int,int>> tests = {
        {12, 18},
        {-12, 18},
        {12, -18},
        {-12, -18},
        {7, 13},
        {17, 17},
        {0, 5},
        {5, 0},
        {100, 25},
        {25, 100},
        {13, 26},
        {14, 15},
        {1000000000, 500000000},
        {1836311903, 1134903170}
    };

    for (auto [a,b] : tests) {
        run_test(a, b);
    }

    return 0;
}
