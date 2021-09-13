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
    const int K = arr[0].size();
    vvi dp(n + 1, vi(K + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < K; ++j) {
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
    cout << sol({{1,5,3},{2,9,4}}) << endl; // 5
    cout << sol({{1,3},{2,4}}) << endl; // 5
    cout << sol({{17,9,6,2,6,18,8,12,3,5,9,11,20,8,13,16}}) << endl; // 2
    cout << endl;
    cout << tab({{1,5,3},{2,9,4}}) << endl; // 5
    cout << tab({{1,3},{2,4}}) << endl; // 5
    cout << tab({{17,9,6,2,6,18,8,12,3,5,9,11,20,8,13,16}}) << endl; // 2
}
