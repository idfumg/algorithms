#include "../../template.hpp"

int rec(const string& a, const string& b, const int m, const int n) {
    if (m == 0) return n;
    if (n == 0) return m;
    if (a[m - 1] == b[n - 1]) return rec(a, b, m - 1, n - 1);
    return 1 + min(rec(a, b, m - 1, n), rec(a, b, m, n - 1));
}

int rec(const string& a, const string& b) {
    return rec(a, b, a.size(), b.size());
}

int tab(const string& a, const string& b) {
    const int m = a.size(), n = b.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("sea", "eat") << endl; // 2
    cout << rec("leetcode", "etco") << endl; // 4
    cout << endl;
    cout << tab("sea", "eat") << endl; // 2
    cout << tab("leetcode", "etco") << endl; // 4
}
