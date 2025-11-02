#include <iostream>
#include <vector>
#include <string>

ptrdiff_t naif_insertion(std::vector<int>& tab){
    ptrdiff_t iterations = 0;
    if(tab.size() < 2) return iterations;

    ptrdiff_t n = tab.size();

    for (ptrdiff_t i = 1; i < n; ++i){
        ++iterations;
        int key = tab[i];
        std::ptrdiff_t j = i - 1;

        while (j >= 0 && tab[j] > key){
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[(j + 1)] = key;
    }
    return iterations;
}

std::string vec_to_string(const std::vector<int>& v) {
    std::string s = "[";
    for (ptrdiff_t i = 0; i < v.size(); ++i) {
        s += std::to_string(v[i]);
        if (i + 1 < v.size()) s += ", ";
    }
    s += "]";
    return s;
}

void run_test() {
    std::vector<std::vector<int>> tests = {
        {},                                     //Tableau de valeur nul
        {1},                                    //Tableau avec une valeur
        {2, 1},                                 //Tableau avec 2 valeurs non triées
        {1, 2, 3, 4, 5},                        //Tableau déjà trié
        {5, 4, 3, 2, 1},                        //Tableau inverse (cas le plus complexe)
        {3, 1, 4, 1, 5, 9, 2},                  //Tableau aléatoire
        {10, -1, 2, 7, 3, 3, 0},                //Tableau aléatoire
        {-3, -1, 0, 3, 8, 11, 22, 63, 80, 100}, //Long tableau rangé
        {100, 80, 63, 22, 11, 8, 3, 0, -1, -3}, //Long tableau inverse
    };

    for (auto tab : tests) {
        std::vector<int> original = tab;
        ptrdiff_t iterations = naif_insertion(tab);
        std::cout << "Tableau d'entrée : " << vec_to_string(original)
             << ", tableau trié : " << vec_to_string(tab)
             << ", nombre d'itérations : " << iterations << ".\n";
    }
}

int main() {
    run_test();
    return 0;
}