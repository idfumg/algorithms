#include "../../template.hpp"

int sol(const vvi& arr) {
    const int m = arr.size();
    const int n = arr[0].size();
    vvi dp(m, vi(n));
    dp[0][0] = arr[0][0] == 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 1) continue;
            if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
            if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main() { TimeMeasure _; //__x();
    cout << sol({{0,0,0},{0,1,0},{0,0,0}}) << endl; // 2
    cout << sol({{0,1},{0,0}}) << endl; // 1
    cout << sol({{1}}) << endl; // 0
    cout << sol({{0}}) << endl; // 1
}
