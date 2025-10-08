#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int collatz_steps(long long n) {
    if (n <= 0) {
        return -1;
    }

    int steps = 1;

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        ++steps;
    }
    return steps;
}


void run_test(long long n, int expected = -1) {
    cout << "Test avec n = " << n << " :" << endl;
    int result = collatz_steps(n);

    if(result == -1){
        cout << "Erreur : n doit être strictement positif. Résultat :" << result;
    }
    else{
        cout << "Longueur obtenue : " << result;
    }
    cout << (result == expected ? "✅ OK" : "❌ FAIL") << "\n";
    cout << "----------------------------------" << endl;
}

int main() {
    vector<pair<long long, int>> tests = {
        {1, 1},             //Test avec 1
        {6, 9},             //Test avec un chiffre classique
        {27, 112},          //Test avec un nombre premier
        {1000000, 153},     //Test avec un grand nombre
        {0, -1},            //Test avec 0
        {-5, -1}            //Test avec un chiffre négatif
    };

    for (auto &t : tests) {
        run_test(t.first, t.second);
    }

    return 0;
}
