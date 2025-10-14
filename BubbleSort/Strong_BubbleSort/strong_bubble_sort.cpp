#include <iostream>
#include <vector>
#include <string>

using namespace std;

size_t naif_bubble_sort(vector<int>& tab) {
    size_t iterations = 0;
    if (tab.size() < 2) return iterations;

    size_t n = tab.size();

    for (size_t i = n - 1; i > 0; --i){
        for (size_t j = 0; j < i; ++j) {
            ++iterations;
            if (tab[j] > tab[j + 1]) {
                int aux = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = aux;
            }
        }
        if (i == 1) break;
    }
    return iterations;
}

string vec_to_string(const vector<int>& v) {
    string s = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        s += to_string(v[i]);
        if (i + 1 < v.size()) s += ", ";
    }
    s += "]";
    return s;
}

void run_test() {
    vector<vector<int>> tests = {
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
        vector<int> original = tab;
        size_t iterations = naif_bubble_sort(tab);
        cout << "Tableau d'entrée : " << vec_to_string(original)
             << ", tableau trié : " << vec_to_string(tab)
             << ", nombre d'itérations : " << iterations << ".\n";
    }
}

int main() {
    run_test();
    return 0;
}
