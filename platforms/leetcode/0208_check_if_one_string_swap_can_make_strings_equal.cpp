#include "../../template.hpp"

int sol(const string& s, const string& t) {
    const int n = s.size();
    int count = 0;
    char a1 = -1, b1 = -1, a2 = -1, b2 = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            if (count == 2) {
                return 0;
            }
            else if (++count == 1) {
                a1 = s[i];
                b1 = t[i];
            }
            else {
                a2 = s[i];
                b2 = t[i];
            }
        }
    }
    if (count == 0) return 1;
    return a2 == b1 and a1 == b2;
}

int main() { TimeMeasure _; //__x();
    cout << sol("bank", "kanb") << endl; // 1
    cout << sol("bank", "kanp") << endl; // 0
    cout << sol("attack", "defend") << endl; // 0
    cout << sol("kelb", "kelb") << endl; // 1
    cout << sol("abcd", "dcba") << endl; // 0
}
