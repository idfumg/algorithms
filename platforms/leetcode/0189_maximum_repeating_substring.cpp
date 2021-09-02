#include "../../template.hpp"

int sol(const string& s, const string& t, const int m, const int n) {
    if (m == 0) return 0;
    if (s[m - 1] == t[n - 1] and n == 1) return 1 + sol(s, t, m - 1, t.size());
    if (s[m - 1] == t[n - 1]) return sol(s, t, m - 1, n - 1);
    return 0;
}

int sol(const string& s, const string& t) {
    int ans = 0;
    for (int i = s.size(); i >= 1; --i) {
        ans = max(ans, sol(s, t, i, t.size()));
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol("ababc", "ab") << endl; // 2
    cout << sol("ababc", "ba") << endl; // 1
    cout << sol("ababc", "ac") << endl; // 0
}
