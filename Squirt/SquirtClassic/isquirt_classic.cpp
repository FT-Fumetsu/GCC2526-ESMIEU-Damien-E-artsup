#include <iostream>
#include <vector>

int isqrt_classic(int n) {
    if (n < 2) return n;
    int low = 1, high = n, r = 0;
    int iterations = 0;
    while (low <= high) {
        int pivot = (low + high) / 2;
        if (pivot <= n / pivot) {
            r = pivot;
            low = pivot + 1;
            iterations++;
        } else {
            high = pivot - 1;
            iterations++;
        }
    }
    std::cout << "(La version classique a pris " << iterations << " itérations pour n=" << n << ")\n";
    return r;
}

int main() {
    std::vector<int> values = {0, 1, 2, 3, 4, 10, 16, 19, 100, 12345, 1000000};

    std::cout << "=== Version classique ===\n";
    for (int n : values) {
        std::cout << "isqrt_classic(" << n << ") = " << isqrt_classic(n) << "\n";
    }

    return 0;
}
