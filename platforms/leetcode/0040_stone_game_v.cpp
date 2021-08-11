#include "../../template.hpp"

int rec(const vi& arr, const vi& prefix, const int i, const int j) {
    if (i >= j) return 0;
    int ans = -INF;
    for (int k = i; k < j; ++k) {
        const int left = prefix[k] - prefix[i - 1];
        const int right = prefix[j] - prefix[k];
        if (left > right) ans = max(ans, right + rec(arr, prefix, k + 1, j));
        else if (right > left) ans = max(ans, left + rec(arr, prefix, i, k));
        else ans = max(ans, left + max(rec(arr, prefix, i, k), rec(arr, prefix, k + 1, j)));
    }
    return ans;
}

int rec(const vi& arr) {
    const int n = arr.size();
    vi prefix(arr.size() + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    return rec(arr, prefix, 1, n);
}

int tab(const vi& arr) {
    const int n = arr.size();
    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    vvi dp(n + 1, vi(n + 2));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i >= j) {
                dp[i][j] = 0;
            }
            else {
                int ans = -INF;
                for (int k = i; k < j; ++k) {
                    const int left = prefix[k] - prefix[i - 1];
                    const int right = prefix[j] - prefix[k];
                    if (left > right) ans = max(ans, right + dp[k + 1][j]);
                    else if (right > left) ans = max(ans, left + dp[i][k]);
                    else ans = max(ans, max(dp[i][k], dp[k + 1][j]) + left);
                }
                dp[i][j] = ans;
            }
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    cout << rec({6,2,3,4,5,5}) << endl; // 18
    cout << rec({7,7,7,7,7,7,7}) << endl; // 28
    cout << rec({4}) << endl; // 0
    cout << rec({10,9,8,7,6,5,4,3,2,1}) << endl; // 37
    cout << rec({2,1,1}) << endl; // 3
    cout << endl;
    cout << tab({6,2,3,4,5,5}) << endl; // 18
    cout << tab({7,7,7,7,7,7,7}) << endl; // 28
    cout << tab({4}) << endl; // 0
    cout << tab({10,9,8,7,6,5,4,3,2,1}) << endl; // 37
    cout << tab({2,1,1}) << endl; // 3
}
