#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

// Implémentation de l'algorithme d'Euclide avec modulo
int pgcd_modulo(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (a == 0 && b == 0) return 0; // cas hors précondition
    if (a == 0) return b;
    if (b == 0) return a;

    while (b != 0) {
        int r = a % b; // reste de la division euclidienne
        a = b;         // on décale
        b = r;
    }
    return a;
}

// Affiche le résultat d'un test
void run_test(int a, int b) {
    cout << "PGCD(" << a << ", " << b << ") = " << pgcd_modulo(a, b) << "\n";
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
        {1000000000LL, 500000000LL},
        {1836311903LL, 1134903170LL},
        {1LL<<50, (1LL<<50) * 3}
    };

    for (auto [a,b] : tests) {
        run_test(a, b);
    }

    return 0;
}
