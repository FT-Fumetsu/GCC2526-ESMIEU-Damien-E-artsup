#include <string>
#include <vector>
#include <iostream>
#include <functional> //function
#include <chrono>
#include <random>
#include <iomanip> //setprecision
#include <stack>
#include <utility> // pair

void Swap(std::vector<int>& tab, int id1, int id2){
    int aux = tab[id1];
    tab[id1] = tab[id2];
    tab[id2] = aux;
}

// implémentation algorithme partitionnement de Lomuto
int partition(std::vector<int>& tab, int begin, int end) {
    int pivot = tab[end];
    int i = begin - 1;

    for (int j = begin; j < end; ++j) {
        if (tab[j] <= pivot) {
            ++i;
            Swap(tab, i, j);
        }
    }
    Swap(tab, i + 1, end);
    return i + 1;
}

void quick_sort(std::vector<int>& tab, int begin, int end) {
    if (begin >= end) return;

    int pivotIndex = partition(tab, begin, end);

    quick_sort(tab, begin, pivotIndex - 1);
    quick_sort(tab, pivotIndex + 1, end);
}

int hoare_partition(std::vector<int>& tab, int begin, int end) {
    int pivot = tab[begin];

    int i = begin - 1;
    int j = end + 1;

    while (true) {
        do {
            ++i;
        } while (tab[i] < pivot);

        do {
            --j;
        } while (tab[j] > pivot);

        if (i >= j) {
            return j;
        }

        Swap(tab, i, j);
    }
}

void quick_sort_hoare(std::vector<int>& tab, int begin, int end) {
    if (begin >= end) return;

    int pivotIndex = hoare_partition(tab, begin, end);
    quick_sort_hoare(tab, begin, pivotIndex);
    quick_sort_hoare(tab, pivotIndex + 1, end);
}

void quick_sort_iteratif(std::vector<int>& tab, int begin, int end) {
    if (begin >= end) return;

    std::stack<std::pair<int,int>> st;
    st.push({begin, end});

    while (!st.empty()) {
        std::pair<int,int> segment = st.top();
        int left = segment.first;
        int high = segment.second;
        st.pop();

        if (left >= high) continue;

        int p = partition(tab, left, high);

        if (p + 1 < high) st.push({p + 1, high});
        if (left < p - 1) st.push({left, p - 1});
    }
}

std::string vec_to_string(const std::vector<int>& v) {
    std::string s = "[";
    for (int i = 0; i < v.size(); ++i) {
        s += std::to_string(v[i]);
        if (i + 1 < v.size()) s += ", ";
    }
    s += "]";
    return s;
}

std::string vec_preview_or_size(const std::vector<int>& v, size_t show_limit = 50) {
    if (v.size() <= show_limit) return vec_to_string(v);
    return std::string("[size: ") + std::to_string(v.size()) + "]";
}

double measure_ms_single(std::function<void(std::vector<int>&, int, int)> sort_fn,
                         const std::vector<int>& data)
{
    using clock = std::chrono::steady_clock;
    std::vector<int> copy = data;
    auto t0 = clock::now();
    if (!copy.empty()) sort_fn(copy, 0, (int)copy.size() - 1);
    auto t1 = clock::now();
    std::chrono::duration<double, std::milli> d = t1 - t0;
    return d.count();
}

void run_test() {
    std::vector<std::vector<int>> tests = {
        {},
        {1},
        {2, 1},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {3, 1, 4, 1, 5, 9, 2},
        {10, -1, 2, 7, 3, 3, 0},
        {-3, -1, 0, 3, 8, 11, 22, 63, 80, 100},
        {100, 80, 63, 22, 11, 8, 3, 0, -1, -3},
    };

    const int big_size = 2000000;
    std::mt19937 rng(123456);
    std::uniform_int_distribution<int> dist(-1000000, 1000000);
    std::vector<int> big_vec;
    big_vec.reserve(big_size);
    for (int i = 0; i < big_size; ++i) big_vec.push_back(dist(rng));
    tests.push_back(big_vec);

    std::cout << std::fixed << std::setprecision(2);

    for (auto tab : tests) {
        std::vector<int> original = tab;

        std::vector<int> lom = tab;
        double t_lom = 0.0;
        if (!lom.empty()) {
            t_lom = measure_ms_single(
                [](std::vector<int>& v, int b, int e){ quick_sort(v, b, e); }, lom);
        }

        std::vector<int> hoa = tab;
        double t_hoa = 0.0;
        if (!hoa.empty()) {
            t_hoa = measure_ms_single(
                [](std::vector<int>& v, int b, int e){ quick_sort_hoare(v, b, e); }, hoa);
        }

        std::vector<int> iter = tab;
        double t_iter = 0.0;
        if (!iter.empty()) {
            t_iter = measure_ms_single(
                [](std::vector<int>& v, int b, int e){ quick_sort_iteratif(v, b, e); }, iter);
        }

        std::cout << "Entrée : " << vec_preview_or_size(original)
                  << "\n  Lomuto: " << vec_preview_or_size(lom) << "  (time = " << t_lom << " ms)"
                  << "\n  Hoare : " << vec_preview_or_size(hoa) << "  (time = " << t_hoa << " ms)"
                  << "\n  Iter. : " << vec_preview_or_size(iter) << "  (time = " << t_iter << " ms)\n\n";
    }
}

int main() {
    run_test();
    return 0;
}
