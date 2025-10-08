#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

string normalise(const string &str) {
    string result;
    result.reserve(str.size());

    for (char c : str) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            result.push_back(toLowerCase(c));
        }
    }
    return result;
}

bool is_palindrome(const string &name) {
    string s = normalise(name);
    int n = static_cast<int>(s.length());
    if(n == 0) return false;
    bool result = true;

    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            result = false;
            break;
        }
    }
    return result;
}

void run_test(const string &name, bool expected) {
    bool result = is_palindrome(name);
    cout << "Test : \"" << name << "\" -> "
         << boolalpha //Boolalpha permet de noté un bool en "True" ou "False" au lieu de "1" ou "0".
         << result
         << " (attendu: " << expected << ") "
         << (result == expected ? "✅ OK" : "❌ FAIL")
         << "\n"; 
}

int main() {
    vector<pair<string, bool>> tests = {
        {"kayak", true},                            //test sans majuscule
        {"KAYak", true},                            //test avec majuscules
        {"tableau", false},                         //test de non palindrome
        {"", false},                                //test de string vide
        {"!!!", false},                             //test avec des caractères spéciaux
        {"9475", false},                            //test avec des chiffres
        {"A man, a plan, a canal: Panama", true},  //Test d'une phrase complète, un palindrome anglais connu
        {"Elu par cette crapule !", true}           //Test de palindrome français
    };

    for (auto &t : tests) {
        run_test(t.first, t.second);
    }
    return 0;
}
