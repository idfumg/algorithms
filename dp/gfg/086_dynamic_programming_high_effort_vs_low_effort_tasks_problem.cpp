#include "../../template.hpp"

int rec(vi high, vi low, int n, bool skipped) {
    if (n == 0) return 0;
    if (skipped) {
        return max(rec(high, low, n - 1, false) + max(low[n - 1], high[n - 1]),
                   rec(high, low, n - 1, true));
    }
    return max(rec(high, low, n - 1, false) + low[n - 1],
               rec(high, low, n - 1, true));
}

int rec(vi high, vi low) {
    return rec(high, low, low.size(), true);
}

int tab(vi high, vi low) {
    int n = low.size();
    vvi dp(n + 1, vi(2));
    for (int i = 1; i <= n; ++i) {
        for (int j : {0, 1}) {
            if (j == 1) {
                dp[i][j] = max(dp[i - 1][0] + max(low[i - 1], high[i - 1]),
                               dp[i - 1][1]);
            }
            else {
                dp[i][j] = max(dp[i - 1][0] + low[i - 1],
                               dp[i - 1][1]);
            }
        }
    }
    return max(dp[n]);
}

int main() { TimeMeasure _; __x();
    vi high = {3, 6, 8, 7, 6};
    vi low = {1, 5, 4, 5, 3};
    cout << rec(high, low) << endl; // 20
    cout << tab(high, low) << endl;
}
