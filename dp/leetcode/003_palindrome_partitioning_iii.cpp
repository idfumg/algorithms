#include "../../template.hpp"

int rec2(const string& s, const int i, const int j) {
    if (i >= j) return 0;
    if (j - i == 1) return s[i - 1] != s[j - 1];
    if (s[i - 1] == s[j - 1]) return rec2(s, i + 1, j - 1);
    return 1 + rec2(s, i + 1, j - 1);
}

int rec2(const string& s) {
    return rec2(s, 1, s.size());
}

int rec(const string& s, const int k, const int n, const int length) {
    if (n == 0 and k > 0) return INF;
    if (n != 0 and k == 0) return INF;
    if (n == 0 and k == 0) return 0;

    const int changes = rec2(s, n, n + length - 1);
    return min(rec(s, k, n - 1, length + 1), rec(s, k - 1, n - 1, 1) + changes);
}

int rec(const string& s, const int k) {
    return rec(s, k, s.size(), 1);
}

int tab(const string& s, const int K) {
    int n = s.size();
    vvi changes(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i >= j) changes[i][j] = 0;
            else if (j - i == 1) changes[i][j] = s[i - 1] != s[j - 1];
            else if (s[i - 1] == s[j - 1]) changes[i][j] = changes[i + 1][j - 1];
            else changes[i][j] = 1 + changes[i + 1][j - 1];
        }
    }
    vvvi dp(K + 1, vvi(n + 1, vi(n + 2, INF)));
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i <= n; ++i) {
            for (int j = n; j >= 1; --j) {
                if (i == 0 and k != 0) dp[k][i][j] = INF;
                else if (i != 0 and k == 0) dp[k][i][j] = INF;
                else if (i == 0 and k == 0) dp[k][i][j] = 0;
                else {
                    dp[k][i][j] = dp[k][i - 1][j + 1];
                    if (i + j - 1 >= 0 and i + j - 1 <= n) {
                        dp[k][i][j] = min(dp[k][i][j], dp[k - 1][i - 1][1] + changes[i][i + j - 1]);
                    }
                }
            }
        }
    }
    return dp[K][n][1];
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
