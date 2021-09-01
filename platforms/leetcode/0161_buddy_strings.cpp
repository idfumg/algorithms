#include "../../template.hpp"

int sol(const string& s, const string& t) {
    const int n = s.size();
    if (n != t.size()) return 0;
    int idx1 = -1, idx2 = -1;
    array<int, 32> letters{};
    bool the_same = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            if (idx1 != -1 and idx2 != -1) return 0;
            else if (idx1 == -1) idx1 = i;
            else idx2 = i;
        }
        if (++letters[s[i] - 'a'] >= 2) {
            the_same = true;
        }
    }
    if (idx1 != -1 and idx2 != -1) return s[idx1] == t[idx2] and s[idx2] == t[idx1];
    if (idx1 != -1 or idx2 != -1) return 0;
    return the_same;
}

int main() { TimeMeasure _; __x();
    cout << sol("ab", "ba") << endl; // 1
    cout << sol("ab", "ab") << endl; // 0
    cout << sol("aa", "aa") << endl; // 1
    cout << sol("aaaaaaabc", "aaaaaaacb") << endl; // 1
    cout << sol("abcaa", "abcbb") << endl; // 0
    cout << sol("abac", "abad") << endl; // 0
}
