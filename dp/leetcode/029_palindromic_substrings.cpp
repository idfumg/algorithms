#include "../../template.hpp"

int rec_(const string& s, const int i, const int j) {
    if (i > j) return 1;
    return s[i - 1] == s[j - 1] and rec_(s, i + 1, j - 1);
}

int rec(const string& s, const int i, const int j) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (j - i == 1) return s[i - 1] == s[j - 1] ? 3 : 2;
    if (s[i - 1] == s[j - 1]) return rec_(s, i, j) + rec(s, i + 1, j) + rec(s, i, j - 1) - rec(s, i + 1, j - 1);
    return rec(s, i + 1, j) + rec(s, i, j - 1) - rec(s, i + 1, j - 1);
}

int rec(const string& s) {
    const int n = s.size();
    return rec(s, 1, n);
}

int tab(const string& s) {
    const int n = s.size();
    vvi pali(n + 1, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) pali[i][j] = 0;
            else if (i == j) pali[i][j] = 1;
            else if (j - i == 1) pali[i][j] = s[i - 1] == s[j - 1];
            else if (s[i - 1] == s[j - 1]) pali[i][j] = pali[i + 1][j - 1];
            else pali[i][j] = 0;
        }
    }
    vvi dp(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) dp[i][j] = 0;
            else if (i == j) dp[i][j] = 1;
            else if (j - i == 1) dp[i][j] = s[i - 1] == s[j - 1] ? 3 : 2;
            else if (s[i - 1] == s[j - 1]) dp[i][j] = pali[i][j] + dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            else dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
    }
    return dp[1][n];
}

int tab2(const string& s) {
    const int n = s.size();
    vvi dp(n + 2, vi(n + 1));
    int ans = 0;
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) dp[i][j] = 0;
            else if (i == j) dp[i][j] = 1;
            else if (j - i == 1) dp[i][j] = s[i - 1] == s[j - 1];
            else if (s[i - 1] == s[j - 1]) dp[i][j] = dp[i + 1][j - 1];
            else dp[i][j] = 0;
            ans += dp[i][j];
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << rec("abc") << endl; // 3
    cout << rec("aaa") << endl; // 6
    cout << rec("aaaaa") << endl; // 15
    cout << endl;
    cout << tab("abc") << endl; // 3
    cout << tab("aaa") << endl; // 6
    cout << tab("aaaaa") << endl; // 15
    cout << endl;
    cout << tab2("abc") << endl; // 3
    cout << tab2("aaa") << endl; // 6
    cout << tab2("aaaaa") << endl; // 15
}
