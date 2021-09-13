#include "../../template.hpp"

int sol(const string& s, const int k, const int i, const int j) {
    if (i > j) return 0;
    if (i == j) return 0;
    if (j - i == 1) return s[i - 1] == s[j - 1] ? 0 : 1;
    if (s[i - 1] == s[j - 1]) return sol(s, k, i + 1, j - 1);
    return min(sol(s, k, i + 1, j), sol(s, k, i, j - 1)) + 1;
}

int sol(const string& s, const int k) {
    return sol(s, k, 1, s.size()) <= k;
}

int tab(const string& s, const int k) {
    const int n = s.size();
    vvi dp(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) dp[i][j] = 0;
            else if (i == j) dp[i][j] = 0;
            else if (j - i == 1) dp[i][j] = s[i - 1] == s[j - 1] ? 0 : 1;
            else if (s[i - 1] == s[j - 1]) dp[i][j] = dp[i + 1][j - 1];
            else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
    }
    return dp[1][n] <= k;
}

int main() { TimeMeasure _; __x();
    cout << sol("abcdeca", 2) << endl; // 1
    cout << sol("abbababa", 1) << endl; // 1
    cout << endl;
    cout << tab("abcdeca", 2) << endl; // 1
    cout << tab("abbababa", 1) << endl; // 1
}
