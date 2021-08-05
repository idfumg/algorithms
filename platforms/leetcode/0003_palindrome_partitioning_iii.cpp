#include "../../template.hpp"

int rec_(const string& s, const int i, const int j) {
    if (i > j) return 0;
    if (j - i == 1) return s[i - 1] != s[j - 1];
    if (s[i - 1] == s[j - 1]) return rec_(s, i + 1, j - 1);
    return rec_(s, i + 1, j - 1) + 1;
}

int rec(const string& s, const int k, const int n, const int count) {
    if (n == 0 and k == 0) return 0;
    if (n == 0 and k > 0) return INF;
    if (n != 0 and k == 0) return INF;
    const int changes = rec_(s, n, n + count - 1);
    return min(rec(s, k, n - 1, count + 1), rec(s, k - 1, n - 1, 1) + changes);
}

int rec(const string& s, const int k) {
    return rec(s, k, s.size(), 1);
}

int tab(const string& s, const int K) {
    const int n = s.size();
    vvi changes(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i >= j) changes[i][j] = 0;
            else if (j - i == 1) changes[i][j] = s[i - 1] != s[j - 1];
            else if (s[i - 1] == s[j - 1]) changes[i][j] = changes[i + 1][j - 1];
            else changes[i][j] = 1 + changes[i + 1][j - 1];
        }
    }
    int idx = 0;
    vvvi dp(n + 1, vvi(n + 2, vi(K + 1, INF)));
    for (int i = 0; i <= n; ++i) {
        idx = i & 1;
        for (int j = n; j >= 1; --j) {
            for (int k = 0; k <= K; ++k) {
                if (k == 0 and i == 0) dp[idx][j][k] = 0;
                else if (i == 0 and k > 0) dp[idx][j][k] = INF;
                else if (i != 0 and k == 0) dp[idx][j][k] = INF;
                else {
                    dp[idx][j][k] = dp[1 - idx][j + 1][k];
                    if (i + j - 1 <= n and i + j - 1 >= 0) {
                        dp[idx][j][k] = min(dp[idx][j][k], dp[1 - idx][1][k - 1] + changes[i][i + j - 1]);
                    }
                }
            }
        }
    }
    return dp[idx][1][K];
}

int main() { TimeMeasure _; __x();
    cout << rec("a", 1) << endl; // 0
    cout << rec("aa", 1) << endl; // 0
    cout << rec("ab", 1) << endl; // 1
    cout << rec("aaa", 1) << endl; // 0
    cout << rec("abc", 2) << endl; // 1
    cout << rec("aabbc", 3) << endl; // 0
    cout << rec("leetcode", 8) << endl; // 0
    cout << endl;
    cout << tab("a", 1) << endl; // 0
    cout << tab("aa", 1) << endl; // 0
    cout << tab("ab", 1) << endl; // 1
    cout << tab("aaa", 1) << endl; // 0
    cout << tab("abc", 2) << endl; // 1
    cout << tab("aabbc", 3) << endl; // 0
    cout << tab("leetcode", 8) << endl; // 0
}
