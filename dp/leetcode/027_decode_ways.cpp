#include "../../template.hpp"

int rec(const string& s, const int n, const int current, vvi& memo) {
    if (n > s.size() and 0 < current and current <= 26) return 1;
    if (current == 0 or n > s.size() or current > 26) return 0;
    if (memo[n][current] != -1) return memo[n][current];

    const int digit = s[n - 1] - '0';
    const int a = rec(s, n + 1, current * 10 + digit, memo);
    const int b = rec(s, n + 1, digit, memo);
    return memo[n][current] = a + b;
}

int rec(const string& s) {
    vvi memo(s.size() + 2, vi(27, -1));
    return rec(s, 2, s.front() - '0', memo);
}

int tab(const string& s) {
    const int n = s.size();
    vvi dp(n + 2, vi(27));
    for (int j = 26; j >= 1; --j) {
        dp[n + 1][j] = 1;
    }
    for (int i = n; i >= 2; --i) {
        for (int j = 26; j >= 1; --j) {
            const int digit = s[i - 1] - '0';
            const int a = j * 10 + digit <= 26 ? dp[i + 1][j * 10 + digit] : 0;
            const int b = dp[i + 1][digit];
            dp[i][j] = a + b;
        }
    }
    return dp[2][s.front() - '0'];
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
