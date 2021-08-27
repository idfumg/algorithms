#include "../../template.hpp"

int sol(const string& s, const int i, const int n) {
    if (n < i) return 0;
    if (i == n) return 1;
    if (s.substr(0, n / 2 + 1) == s.substr(n / 2 + 1, n - n / 2)) return sol(s, i, n / 2);
    if (s.substr(n - i, i + 1) == s.substr(0, i + 1)) return sol(s, i, n - i - 1);
    return 0;
}

int sol(const string& s) {
    const int n = s.size();
    for (int i = 0; i < n - 1; ++i) {
        if (s[n - 1] == s[i]) {
            if (sol(s, i, n - 1)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() { TimeMeasure _; __x();
    cout << sol("abab") << endl; // 1
    cout << sol("aba") << endl; // 0
    cout << sol("abcabcabcabc") << endl; // 1
    cout << sol("ababab") << endl; // 1
    cout << sol("aabaaba") << endl; // 0
}
