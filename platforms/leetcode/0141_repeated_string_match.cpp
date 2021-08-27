#include "../../template.hpp"

int sol(const string& s, const string& t, const int m, const int n) {
    if (n == 0) return 1;
    if (m == 0) return sol(s, t, s.size(), n) + 1;
    if (s[m - 1] != t[n - 1]) return -INF;
    return sol(s, t, m - 1, n - 1);
}

int sol(const string& s, const string& t) {
    const int n = s.size();
    for (int i = n; i >= 1; --i) {
        if (s[i - 1] == t.back()) {
            const int ans = sol(s, t, i, t.size());
            if (ans >= 0) return ans;
        }
    }
    return -1;
}

int main() { TimeMeasure _; __x();
    cout << sol("abcd", "cdabcdab") << endl; // 3
    cout << sol("a", "aa") << endl; // 2
    cout << sol("a", "a") << endl; // 1
    cout << sol("abc", "wxyz") << endl; // -1
    cout << sol("aaaaaaaaaaaaaaaaaaaaaab", "ba") << endl; // 2
}
