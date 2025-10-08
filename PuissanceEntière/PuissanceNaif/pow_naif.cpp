#include <iostream>

int pow_naif(int x, int n) {
    if (n < 0) return 0;
    int r = 1;
    for (int i = 0; i < n; ++i) r *= x;
    return r;
}

int main() {
    int bases[] = {0, 1, 2, -5, 7, -8};
    int exps[] = {0, 1, 2, 3, 5, 10};

    for (int x : bases) {
        for (int n : exps) {
            std::cout << pow_naif(x, n) << "\n";
        }
    }
    return 0;
}