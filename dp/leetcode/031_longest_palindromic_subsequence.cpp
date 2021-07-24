#include "../../template.hpp"

int rec(const string& s, const int i, const int j) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (j - i == 1) return s[i - 1] == s[j - 1] ? 2 : 1;
    if (s[i - 1] == s[j - 1]) return max({2 + rec(s, i + 1, j - 1), rec(s, i + 1, j), rec(s, i, j - 1)});
    return max(rec(s, i + 1, j), rec(s, i, j - 1));
}

int rec(const string& s) {
    return rec(s, 1, s.size());
}

int tab(const string& s) {
    const int n = s.size();
    vvi dp(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) dp[i][j] = 0;
            else if (i == j) dp[i][j] = 1;
            else if (j - i == 1) dp[i][j] = s[i - 1] == s[j - 1] ? 2 : 1;
            else if (s[i - 1] == s[j - 1]) dp[i][j] = max({2 + dp[i + 1][j - 1], dp[i][j - 1], dp[i + 1][j]});
            else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("bbbab") << endl; // 4
    cout << rec("cbbd") << endl; // 2
    cout << rec("abcdef") << endl; // 1
    cout << endl;
    cout << tab("bbbab") << endl; // 4
    cout << tab("cbbd") << endl; // 2
    cout << tab("abcdef") << endl; // 1
}
