#include "../../template.hpp"

int sol(const vvi& arr, const int n, const int prev_color) {
    if (n == 0) return 0;
    int ans = INF;
    for (int i = 0; i < arr[n - 1].size(); ++i) {
        if (i != prev_color) {
            ans = min(ans, sol(arr, n - 1, i) + arr[n - 1][i]);
        }
    }
    return ans;
}

int sol(const vvi& arr) {
    const int n = arr.size();
    int ans = INF;
    for (int i = 0; i < arr[n - 1].size(); ++i) {
        ans = min(ans, sol(arr, n - 1, i) + arr[n - 1][i]);
    }
    return ans;
}

int tab(const vvi& arr) {
    const int n = arr.size();
    vvi dp(n + 1, vi(4));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            int ans = INF;
            for (int k = 0; k < arr[n - 1].size(); ++k) {
                if (k != j) {
                    ans = min(ans, dp[i - 1][k] + arr[i - 1][k]);
                }
            }
            dp[i][j] = ans;
        }
    }

    int ans = INF;
    for (int i = 0; i < arr[n - 1].size(); ++i) {
        ans = min(ans, dp[n - 1][i] + arr[n - 1][i]);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({{17,2,17},{16,16,5},{14,3,19}}) << endl; // 10
    cout << sol({{7,6,2}}) << endl; // 2
    cout << sol({{3,5,3},{6,17,6},{7,13,18},{9,10,18}}) << endl; // 26
    cout << endl;
    cout << tab({{17,2,17},{16,16,5},{14,3,19}}) << endl; // 10
    cout << tab({{7,6,2}}) << endl; // 2
    cout << tab({{3,5,3},{6,17,6},{7,13,18},{9,10,18}}) << endl; // 26
}
