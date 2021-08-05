#include "../../template.hpp"

int tab(const string& s) {
    int n = s.size();
    vvb changes(n + 2, vb(n + 1, false));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) changes[i][j] = 0;
            else if (i == j) changes[i][j] = 1;
            else if (j - i == 1) changes[i][j] = s[i - 1] == s[j - 1];
            else if (s[i - 1] == s[j - 1]) changes[i][j] = changes[i + 1][j - 1];
            else changes[i][j] = 0;
        }
    }
    if (changes[1][n]) {
        return 0;
    }
    vvi dp(n + 1, vi(n + 2, INF));
    for (int i = 0; i <= n; ++i) {
        for (int j = n; j >= 1; --j) {
            if (i == 0 and j != 1) dp[i][j] = INF;
            else if (i == 0 and j == 1) dp[i][j] = 0;
            else {
                dp[i][j] = dp[i - 1][j + 1];
                if (i + j - 1 >= 0 and i + j - 1 <= n and changes[i][i + j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][1] + 1);
                }
            }
        }
    }
    return dp[n][1] - 1;
}

int main() { TimeMeasure _; __x();
    cout << tab("a") << endl; // 0
    cout << tab("aa") << endl; // 0
    cout << tab("ab") << endl; // 1
    cout << tab("aaa") << endl; // 0
    cout << tab("aab") << endl; // 1
}
