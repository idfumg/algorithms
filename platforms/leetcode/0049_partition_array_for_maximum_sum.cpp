#include "../../template.hpp"

int rec_(const vi& arr, const int i, const int j) {
    if (i > j) return -INF;
    if (i == j) return arr[i - 1];
    if (j - i == 1) return max(arr[i - 1], arr[j - 1]);
    return max(arr[i - 1], rec_(arr, i + 1, j));
}

int rec(const vi& arr, const int k, const int n, const int count) {
    if (count > k) return -INF;
    if (n == 0 and count != 1) return -INF;
    if (n == 0 and count == 1) return 0;
    return max(
        rec(arr, k, n - 1, count + 1),
        rec(arr, k, n - 1, 1) + rec_(arr, n, n + count - 1) * count);
}

int rec(const vi& arr, const int k) {
    return rec(arr, k, arr.size(), 1);
}

int tab(const vi& arr, const int k) {
    const int n = arr.size();
    vvi maxs(n + 2, vi(n + 2));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) maxs[i][j] = -INF;
            else maxs[i][j] = max(arr[i - 1], maxs[i + 1][j]);
        }
    }
    vvi dp(n + 1, vi(k + 2, -INF));
    for (int i = 0; i <= n; ++i) {
        for (int j = k; j >= 1; --j) {
            if (i == 0 and j != 1) dp[i][j] = -INF;
            else if (i == 0 and j == 1) dp[i][j] = 0;
            else dp[i][j] = max(
                dp[i - 1][j + 1],
                dp[i - 1][1] + (i + j - 1 <= n ? maxs[i][i + j - 1] * j : 0));
        }
    }
    return dp[n][1];
}

int tab_opt(const vi& arr, const int k) {
    const int n = arr.size();
    vvi maxs(n + 2, vi(n + 2));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) maxs[i][j] = -INF;
            else maxs[i][j] = max(arr[i - 1], maxs[i + 1][j]);
        }
    }
    int idx = 0;
    vvi dp(2, vi(k + 2, -INF));
    for (int i = 0; i <= n; ++i) {
        idx = i & 1;
        for (int j = k; j >= 1; --j) {
            if (i == 0 and j != 1) dp[idx][j] = -INF;
            else if (i == 0 and j == 1) dp[idx][j] = 0;
            else dp[idx][j] = max(
                dp[1 - idx][j + 1],
                dp[1 - idx][1] + (i + j - 1 <= n ? maxs[i][i + j - 1] * j : 0));
        }
    }
    return dp[idx][1];
}

int main() { TimeMeasure _; __x();
    cout << rec({1,15,7,9,2,5,10}, 3) << endl; // 84
    cout << rec({1,4,1,5,7,3,6,1,9,9,3}, 4) << endl; // 83
    cout << rec({1}, 1) << endl; // 1
    cout << endl;
    cout << tab({1,15,7,9,2,5,10}, 3) << endl; // 84
    cout << tab({1,4,1,5,7,3,6,1,9,9,3}, 4) << endl; // 83
    cout << tab({1}, 1) << endl; // 1
    cout << endl;
    cout << tab_opt({1,15,7,9,2,5,10}, 3) << endl; // 84
    cout << tab_opt({1,4,1,5,7,3,6,1,9,9,3}, 4) << endl; // 83
    cout << tab_opt({1}, 1) << endl; // 1
}
