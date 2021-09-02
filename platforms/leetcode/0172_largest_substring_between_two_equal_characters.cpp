#include "../../template.hpp"

int sol(const string& s, const int i, const int j) {
    if (i > j) return -1;
    if (i == j) return -1;
    if (j - i == 1) return s[i - 1] == s[j - 1] ? 0 : -1;
    if (s[i - 1] == s[j - 1]) return j - i + 1 - 2;
    return max(sol(s, i + 1, j), sol(s, i, j - 1));
}

int sol(const string& s) {
    return sol(s, 1, s.size());
}

int tab(const string& s) {
    const int n = s.size();
    vvi dp(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) dp[i][j] = -1;
            else if (i == j) dp[i][j] = -1;
            else if (j - i == 1) dp[i][j] = s[i - 1] == s[j - 1] ? 0 : -1;
            else if (s[i - 1] == s[j - 1]) dp[i][j] = j - i + 1 - 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    cout << sol("aa") << endl; // 0
    cout << sol("abca") << endl; // 2
    cout << sol("cbzxy") << endl; // -1
    cout << sol("cabbac") << endl; // 4
    cout << 4 << endl; // 38
    cout << endl;
    cout << tab("aa") << endl; // 0
    cout << tab("abca") << endl; // 2
    cout << tab("cbzxy") << endl; // -1
    cout << tab("cabbac") << endl; // 4
    cout << tab("pfwftcwdbiodyoojbebtwoyqemmsgmsryugkkcwykhtaczj") << endl; // 4
}
