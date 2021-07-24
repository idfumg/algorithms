#include "../../template.hpp"

int rec(const int n, const int target) {
    if (target == 0) return 1;
    if (n == 0) return 0;
    return rec(n - 1, target) + rec(n, target - 1);
}

int rec(const int target) {
    constexpr int n = 5;
    return rec(n, target);
}

int tab(const int target) {
    constexpr int n = 5;
    vvi dp(n + 1, vi(target + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= target; ++j) {
            if (j == 0) dp[i][j] = 1;
            else if (i == 0) dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n][target];
}

int tab2(const int target) {
    constexpr int n = 5;
    int idx = 0;
    vvi dp(2, vi(target + 1));
    for (int i = 0; i <= n; ++i) {
        idx = i & 1;
        for (int j = 0; j <= target; ++j) {
            if (j == 0) dp[idx][j] = 1;
            else if (i == 0) dp[idx][j] = 0;
            else dp[idx][j] = dp[1 - idx][j] + dp[idx][j - 1];
        }
    }
    return dp[idx][target];
}

int main() { TimeMeasure _; __x();
    cout << rec(1) << endl; // 5
    cout << rec(2) << endl; // 15
    cout << rec(33) << endl; // 66045
    cout << endl;
    cout << tab(1) << endl; // 5
    cout << tab(2) << endl; // 15
    cout << tab(33) << endl; // 66045
    cout << endl;
    cout << tab2(1) << endl; // 5
    cout << tab2(2) << endl; // 15
    cout << tab2(33) << endl; // 66045
}
