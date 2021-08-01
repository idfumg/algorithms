#include "../../template.hpp"

int is_pali(const string& s, const int i, const int j) {
    if (i > j) return 1;
    return s[i - 1] == s[j - 1] and is_pali(s, i + 1, j - 1);
}

int rec(const string& s, const int i, const int j) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (j - i == 1) return s[i - 1] == s[j - 1] ? 2 : 1;
    if (s[i - 1] == s[j - 1] and is_pali(s, i, j)) return j - i + 1;
    return max(
        rec(s, i + 1, j),
        rec(s, i, j - 1));
}

int rec(const string& s) {
    return rec(s, 1, s.size());
}

string tab(const string& s) {
    const int n = s.size();
    vvi pali(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) pali[i][j] = 1;
            else pali[i][j] = s[i - 1] == s[j - 1] and pali[i + 1][j - 1];
        }
    }
    vvi dp(n + 2, vi(n + 1));
    int ans = -INF;
    int idx = 0;
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) dp[i][j] = 0;
            else if (i == j) dp[i][j] = 1;
            else if (j - i == 1) dp[i][j] = s[i - 1] == s[j - 1] ? 2 : 1;
            else if (s[i - 1] == s[j - 1] and pali[i][j]) dp[i][j] = j - i + 1;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            if (ans < dp[i][j]) {
                ans = dp[i][j];
                idx = i;
            }
        }
    }
    return s.substr(idx - 1, ans);
}

int main() { TimeMeasure _; __x();
    cout << rec("babad") << endl; // "bab"
    cout << rec("cbbd") << endl; // "bb"
    cout << rec("a") << endl; // "a"
    cout << rec("ac") << endl; // "a"
    cout << endl;
    cout << tab("babad") << endl; // "bab"
    cout << tab("cbbd") << endl; // "bb"
    cout << tab("a") << endl; // "a"
    cout << tab("ac") << endl; // "a"
}
