#include "../../template.hpp"

int rec(const string& a, const string& b, const int m, const int n) {
    if (m == 0 and n == 0) return true;
    if (n == 0) return false;
    if (m == 0 and b[n - 1] == '*') return rec(a, b, m, n - 1);
    if (m == 0 and b[n - 1] != '*') return false;
    if (b[n - 1] == '*') return rec(a, b, m - 1, n) or rec(a, b, m, n - 1);
    if (a[m - 1] == b[n - 1]) return rec(a, b, m - 1, n - 1);
    if (b[n - 1] == '?') return rec(a, b, m - 1, n - 1);
    return false;
}

int rec(const string& a, const string& b) {
    return rec(a, b, a.size(), b.size());
}

int tab(const string& a, const string& b) {
    const int m = a.size();
    const int n = b.size();
    int idx = 0;
    vvb dp(2, vb(n + 1));
    for (int i = 0; i <= m; ++i) {
        idx = i & 1;
        for (int j = 0; j <= n; ++j) {
            if (i == 0 and j == 0) dp[idx][j] = 1;
            else if (j == 0) dp[idx][j] = 0;
            else if (i == 0 and b[j - 1] == '*') dp[idx][j] = dp[idx][j - 1];
            else if (i == 0 and b[j - 1] != '*') dp[idx][j] = 0;
            else if (b[j - 1] == '*') dp[idx][j] = dp[1 - idx][j] or dp[idx][j - 1];
            else if (a[i - 1] == b[j - 1]) dp[idx][j] = dp[1 - idx][j - 1];
            else if (b[j - 1] == '?') dp[idx][j] = dp[1 - idx][j - 1];
            else dp[idx][j] = 0;
        }
    }
    return dp[idx][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("aa", "a") << endl; // 0
    cout << rec("aa", "*") << endl; // 1
    cout << rec("cb", "?a") << endl; // 0
    cout << rec("adceb", "*a*b") << endl; // 1
    cout << rec("acdcb", "a*c?b") << endl; // 0
    cout << endl;
    cout << tab("aa", "a") << endl; // 0
    cout << tab("aa", "*") << endl; // 1
    cout << tab("cb", "?a") << endl; // 0
    cout << tab("adceb", "*a*b") << endl; // 1
    cout << tab("acdcb", "a*c?b") << endl; // 0
}
