#include <iostream>
#include <vector>

int isqrt_newton(int n) {
    if (n < 2) return n;
    int x = n;
    int iterations = 0;
    while (x > n / x) {
        x = (x + n / x) / 2;
        iterations++;
    }
    std::cout << "(Newton a pris " << iterations << " itérations pour n=" << n << ")\n";
    return x;
}

int main() {
    std::vector<int> values = {0, 1, 2, 3, 4, 10, 16, 19, 100, 12345, 1000000};

    std::cout << "=== Version Newton ===\n";
    for (int n : values) {
        std::cout << "isqrt_newton(" << n << ") = " << isqrt_newton(n) << "\n";
    }

    return 0;
}
