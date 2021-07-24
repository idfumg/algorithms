#include "../../template.hpp"

int rec(string s, int i, int j) {
    if (i > j) return 0;
    if (s[i - 1] == s[j - 1]) return 1 + rec(s, i + 1, j) + rec(s, i, j - 1);
    return rec(s, i + 1, j) + rec(s, i, j - 1) - rec(s, i + 1, j - 1);
}

int rec(string s) {
    return rec(s, 1, s.size());
}

int tab(string s) {
    int n = s.size();
    vvi dp(n + 2, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (s[i - 1] == s[j - 1]) {
                dp[i][j] = 1 + dp[i + 1][j] + dp[i][j - 1];
            }
            else {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    cout << rec("abcd") << endl; // 4
    cout << rec("aab") << endl; // 4
    cout << rec("aaaa") << endl; // 15
    cout << rec("abcb") << endl; // 6
    cout << endl;
    cout << tab("abcd") << endl;
    cout << tab("aab") << endl;
    cout << tab("aaaa") << endl;
    cout << tab("abcb") << endl;
}
