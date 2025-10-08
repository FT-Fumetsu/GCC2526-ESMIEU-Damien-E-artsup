#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

char toLowerCase(char c){
    if(c >= 'A' && c <= 'Z'){
        return c + ('a' - 'A');
    }
    return c;
}

string normalise(const string &str) {
    string result;
    result.reserve(str.size());

    for (char c : str) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            result.push_back(toLowerCase(c));
        }
    }
    return result;
}

int occurences(const string &name, char c){
    string word = normalise(name);
    char cc = toLowerCase(c);
    int compteur = 0;
    for(char ch : word){
        if(ch == cc) ++compteur;
    }
    return compteur;
}

bool anagrammeWithSortedWords(string a, string b){
    a = normalise(a);
    b = normalise(b);

    if(a.length() != b.length()) return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a==b;
}

