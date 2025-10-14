#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <cassert>
#include <cctype>

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

bool anagrammeOccurence(const string &a_in, const string &b_in){
    string a = normalise(a_in);
    string b = normalise(b_in);

    if(a.length() != b.length()) return false;

    unordered_map<char,int> countA;
    unordered_map<char,int> countB;

    for(char ch : a) ++countA[ch];
    for(char ch : b) ++countB[ch];

    if(countA.size() != countB.size()) return false;
    for(const auto &p : countA){
        char key = p.first;
        int val = p.second;
        auto it = countB.find(key);
        if(it == countB.end() || it->second != val) return false;
    }
    return true;
}

bool anagrammeOptimised(const string &a_in, const string &b_in){
    string a = normalise(a_in);
    string b = normalise(b_in);

    if(a.length() != b.length()) return false;

    array<int, 256> counts{};
    counts.fill(0);

    for(unsigned char ch : a){
        counts[ch] += 1;
    }

    for(unsigned char ch : b){
        counts[ch] -= 1;
    }

    for(int i = 0; i < 256; ++i){
        if(counts[i] != 0) return false;
    }
    return true;
}

int main(){
    vector<tuple<string, char, int>> o_tests = {
        {"Mississippi", 's', 4},
        {"Mississippi", 'i', 4},
        {"Mississippi", 'p', 2},
        {"", 'a', 0}
    };

    for(const auto &t : o_tests){
        string a;
        char b;
        int expected;
        tie(a, b, expected) = t;

        int occ = occurences(a, b);

        cout << "Combien y'a-t-il de '" << b <<"' dans le mot '" << a << "' ? "
        << occ << (occ == expected ? "✅ OK" : "❌ FAIL") << "\n";
    }

    cout << "Test sur les occurences terminés !" << "\n" 
    << "--------------------------------------"<< "\n";

    vector<tuple<string, string, bool>> tests = {
        {"Listen", "Silent", true},
        {"Triangle", "Integral", true},
        {"Apple", "Pabble", false},
        {"", "", true}, // deux chaînes vides -> anagrammes
        {"a", "", false},
        {"Dormitory", "Dirty room", true}, // avec espace : normalise
        {"Conversation", "Voices rant on", true},
        {"The eyes", "They see", true},
        {"abc", "ab", false},
        {"aabbcc", "abccba", true},
        {"Listen", "Silence", false}
    };

    for(const auto &t : tests){
        string a, b;
        bool expected;
        tie(a,b,expected) = t;

        bool r_sorted = anagrammeWithSortedWords(a,b);
        bool r_map = anagrammeOccurence(a,b);
        bool r_opt = anagrammeOptimised(a,b);

        cout << "'" << a << "' vs '" << b << "': "
             << boolalpha 
             << "sorted = " << r_sorted << (r_sorted == expected ? "✅ OK" : "❌ FAIL") 
             << " map = " << r_map << (r_map == expected ? "✅ OK" : "❌ FAIL") 
             << " optimised = " << r_opt << (r_opt == expected ? "✅ OK" : "❌ FAIL") <<"\n";

        assert(r_sorted == expected);
        assert(r_map == expected);
        assert(r_opt == expected);
    }
    return 0;
}