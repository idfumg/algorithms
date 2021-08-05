#include "../../template.hpp"

int rec(const string& s, const int n, const int current, vvi& dp) {
    if (current < 1 or current > 26) return 0;
    if (n >= s.size()) return 1;
    if (dp[n][current] != -INF) return dp[n][current];
    return dp[n][current] =
        rec(s, n + 1, current * 10 + s[n] - '0', dp) +
        rec(s, n + 1, s[n] - '0', dp);
}

int rec(const string& s) {
    vvi dp(s.size() + 1, vi(27, -INF));
    return rec(s, 1, s[0] - '0', dp);
}

int tab(const string& s) {
    const int n = s.size();
    vvi dp(n + 3, vi(27));
    for (int j = 26; j >= 1; --j) {
        dp[n][j] = 1;
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 26; j >= 1; --j) {
            const int d = s[i] - '0';
            dp[i][j] =
                (j * 10 + d < 27 ? dp[i + 1][j * 10 + d] : 0) +
                dp[i + 1][d];
        }
    }
    return dp[1][s[0] - '0'];
}

int main() { TimeMeasure _; __x();
    cout << rec("12") << endl; // 2
    cout << rec("226") << endl; // 3
    cout << rec("0") << endl; // 0
    cout << rec("06") << endl; // 0
    cout << rec("26") << endl; // 2
    cout << rec("10") << endl; // 1
    cout << rec("111111111111111111111111111111111111111111111") << endl; // 1836311903
    cout << rec("2101") << endl; // 1
    cout << endl;
    cout << tab("12") << endl; // 2
    cout << tab("226") << endl; // 3
    cout << tab("0") << endl; // 0
    cout << tab("06") << endl; // 0
    cout << tab("26") << endl; // 2
    cout << tab("10") << endl; // 1
    cout << tab("111111111111111111111111111111111111111111111") << endl; // 1836311903
    cout << tab("2101") << endl; // 1
}
