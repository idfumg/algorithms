#include "../../template.hpp"

int rec(const string& s, const string& p, const int m, const int n) {
    if (m == 0 and n == 0) return 1;
    if (m != 0 and n == 0) return 0;
    if (m == 0 and p[n - 1] == '*') return rec(s, p, m, n - 2);
    if (m == 0 and p[n - 1] != '*') return 0;
    if (p[n - 1] == '*' and s[m - 1] == p[n - 2]) return rec(s, p, m - 1, n) or rec(s, p, m, n - 2) or rec(s, p, m - 1, n - 2);
    if (p[n - 1] == '*' and p[n - 2] == '.') return rec(s, p, m - 1, n) or rec(s, p, m, n - 2) or rec(s, p, m - 1, n - 2);
    if (p[n - 1] == '*' and s[m - 1] != p[n - 2]) return rec(s, p, m, n - 2);
    if (p[n - 1] == '.') return rec(s, p, m - 1, n - 1);
    if (s[m - 1] == p[n - 1]) return rec(s, p, m - 1, n - 1);
    if (s[m - 1] != p[n - 1]) return 0;
    return 1;
}

int rec(const string& s, const string& p) {
    return rec(s, p, s.size(), p.size());
}

int tab(const string& s, const string& p) {
    const int m = s.size();
    const int n = p.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 and j == 0) dp[i][j] = 1;
            else if (i != 0 and j == 0) dp[i][j] = 0;
            else if (i == 0 and p[j - 1] == '*') dp[i][j] = dp[i][j - 2];
            else if (i == 0 and p[j - 1] != '*') dp[i][j] = 0;
            else if (p[j - 1] == '*' and s[i - 1] == p[j - 2]) dp[i][j] = dp[i - 1][j] or dp[i][j - 2] or dp[i - 1][j - 2];
            else if (p[j - 1] == '*' and p[j - 2] == '.') dp[i][j] = dp[i - 1][j] or dp[i][j - 2] or dp[i - 1][j - 2];
            else if (p[j - 1] == '*' and s[i - 1] != p[j - 2]) dp[i][j] = dp[i][j - 2];
            else if (p[j - 1] == '.') dp[i][j] = dp[i - 1][j - 1];
            else if (s[i - 1] == p[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else if (s[i - 1] != p[j - 1]) dp[i][j] = 0;
            else dp[i][j] = 1;
        }
    }
    return dp[m][n];
}

int tab_opt(const string& s, const string& p) {
    const int m = s.size();
    const int n = p.size();
    vvi dp(m + 1, vi(n + 1));
    dp[0][0] = 1;
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
        else dp[0][j] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                if (s[i - 1] == p[j - 2] or p[j - 2] == '.') {
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 2] or dp[i - 1][j - 2];
                }
                else {
                    dp[i][j] = dp[i][j - 2];
                }
            }
            else if (p[j - 1] == '.' or s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (s[i - 1] != p[j - 1]) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = 1;
            }
        }
    }
    return dp[m][n];
}

int tab_opt2(const string& s, const string& p) {
    const int m = s.size();
    const int n = p.size();
    vvi dp(2, vi(n + 1));
    int idx = 0;
    for (int i = 0; i <= m; ++i) {
        idx = i & 1;
        for (int j = 0; j <= n; ++j) {
            if (i == 0 and j == 0) dp[idx][j] = 1;
            else if (i != 0 and j == 0) dp[idx][j] = 0;
            else if (i == 0 and p[j - 1] == '*') dp[idx][j] = dp[idx][j - 2];
            else if (i == 0 and p[j - 1] != '*') dp[idx][j] = 0;
            else if (p[j - 1] == '*' and s[i - 1] == p[j - 2]) dp[idx][j] = dp[1 - idx][j] or dp[idx][j - 2] or dp[1 - idx][j - 2];
            else if (p[j - 1] == '*' and p[j - 2] == '.') dp[idx][j] = dp[1- idx][j] or dp[idx][j - 2] or dp[1 - idx][j - 2];
            else if (p[j - 1] == '*' and s[i - 1] != p[j - 2]) dp[idx][j] = dp[idx][j - 2];
            else if (p[j - 1] == '.') dp[idx][j] = dp[1 - idx][j - 1];
            else if (s[i - 1] == p[j - 1]) dp[idx][j] = dp[1 - idx][j - 1];
            else if (s[i - 1] != p[j - 1]) dp[idx][j] = 0;
            else dp[idx][j] = 1;
        }
    }
    return dp[idx][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("aa", "a") << endl; // 0
    cout << rec("aa", "a*") << endl; // 1
    cout << rec("ab", ".*") << endl; // 1
    cout << rec("aab", "c*a*b") << endl; // 1
    cout << rec("mississippi", "mis*is*p*.") << endl; // 0
    cout << endl;
    cout << tab("aa", "a") << endl; // 0
    cout << tab("aa", "a*") << endl; // 1
    cout << tab("ab", ".*") << endl; // 1
    cout << tab("aab", "c*a*b") << endl; // 1
    cout << tab("mississippi", "mis*is*p*.") << endl; // 0
    cout << endl;
    cout << tab_opt("aa", "a") << endl; // 0
    cout << tab_opt("aa", "a*") << endl; // 1
    cout << tab_opt("ab", ".*") << endl; // 1
    cout << tab_opt("aab", "c*a*b") << endl; // 1
    cout << tab_opt("mississippi", "mis*is*p*.") << endl; // 0
    cout << endl;
    cout << tab_opt2("aa", "a") << endl; // 0
    cout << tab_opt2("aa", "a*") << endl; // 1
    cout << tab_opt2("ab", ".*") << endl; // 1
    cout << tab_opt2("aab", "c*a*b") << endl; // 1
    cout << tab_opt2("mississippi", "mis*is*p*.") << endl; // 0
}
