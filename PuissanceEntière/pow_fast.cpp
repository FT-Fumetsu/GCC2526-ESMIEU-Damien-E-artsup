#include <iostream>

int seuil(double x) { return static_cast<int>(x); }

int pow_fast(int a, int b) {
    if (b < 0) return 0;
    int r = 1;
    int base = a;
    while (b > 0) {
        if (b % 2 == 1) r *= base;
        base *= base;
        b = seuil(b / 2.0);
    }
    return r;
}

int main() {
    int bases[] = {0, 1, 2, -5, 7, -8};
    int exps[] = {0, 1, 2, 3, 5, 10};

    for (int x : bases) {
        for (int n : exps) {
            std::cout << pow_fast(x, n) << "\n";
        }
    }
    return 0;
}