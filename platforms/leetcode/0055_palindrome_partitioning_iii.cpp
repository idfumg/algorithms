#include "../../template.hpp"

int rec(const string& s, const int i, const int j) {
    if (i >= j) return 0;
    if (j - i == 1) return s[i - 1] != s[j - 1] ? 1 : 0;
    if (s[i - 1] == s[j - 1]) return rec(s, i + 1, j - 1);
    return min(rec(s, i + 1, j), rec(s, i, j - 1));
}

int rec(const string& s, const int k, const int n, const int count) {
    if (n == 0 and count != 1) return INF;
    if (n == 0 and k == 0) return 0;
    if (n == 0 and k != 0) return INF;
    if (k > 0) return min(rec(s, k, n - 1, count + 1), rec(s, k - 1, n - 1, 1) + rec(s, n, n + count - 1));
    return rec(s, k, n - 1, count + 1);
}

int rec(const string& s, const int k) {
    return rec(s, k, s.size(), 1);
}

int tab(const string& s, const int K) {
    const int n = s.size();
    vvi count(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) count[i][j] = 0;
            else if (i == j) count[i][j] = 0;
            else if (j - i == 1) count[i][j] = s[i - 1] != s[j - 1];
            else if (s[i - 1] == s[j - 1]) count[i][j] = count[i + 1][j - 1];
            else count[i][j] = min(count[i + 1][j], count[i][j - 1]);
        }
    }
    vvvi dp(n + 1, vvi(n + 2, vi(K + 1, INF)));
    for (int i = 0; i <= n; ++i) {
        for (int j = n; j >= 1; --j) {
            for (int k = 0; k <= K; ++k) {
                if (i == 0 and j != 1) dp[i][j][k] = INF;
                else if (i == 0 and k == 0) dp[i][j][k] = 0;
                else if (i == 0 and k != 0) dp[i][j][k] = INF;
                else if (k > 0) dp[i][j][k] = min(
                    dp[i - 1][j + 1][k],
                    dp[i - 1][1][k - 1] + (i + j - 1 <= n ? count[i][i + j - 1] : 0));
                else dp[i][j][k] = dp[i - 1][j + 1][k];
            }
        }
    }
    return dp[n][1][K];
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
