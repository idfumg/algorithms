#include "../../template.hpp"

string sol(const string& s) {
    const int n = s.size();
    const auto is_nice = [](const string& s, const int i, const int j)->bool{
        unordered_set<char> m;
        for (int k = i; k <= j; ++k) {
            m.insert(s[k]);
        }
        for (int k = i; k <= j; ++k) {
            if (isupper(s[k]) and not m.count(tolower(s[k]))) return false;
            else if (islower(s[k]) and not m.count(toupper(s[k]))) return false;
        }
        return true;
    };
    int idx = 0;
    int jdx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (is_nice(s, i, j) and j - i + 1 > jdx - idx + 1) {
                idx = i;
                jdx = j;
            }
        }
    }
    return jdx - idx + 1 > 1 ? s.substr(idx, jdx - idx + 1) : "";
}

int main() { TimeMeasure _; __x();
    cout << sol("YazaAay") << endl; // "aAa"
    cout << sol("Bb") << endl; // "Bb"
    cout << sol("c") << endl; // ""
    cout << sol("ca") << endl; // ""
    cout << sol("dDzeE") << endl; // "dD"
}
