#include "../../template.hpp"

int rec(const vi& arr, const int n, const int even, const int total) {
    if (n == 0) return total;
    return max(rec(arr, n - 1, even, total),
               rec(arr, n - 1, !even, total + arr[n - 1] * (even ? 1 : -1)));
}

int rec(const vi& arr) {
    return rec(arr, arr.size(), 1, 0);
}

int rec2(const vi& arr, const int n, const int even) {
    if (n == 0) return 0;
    return max(rec2(arr, n - 1, even),
               rec2(arr, n - 1, !even) + arr[n - 1] * (even ? 1 : -1));
}

int rec2(const vi& arr) {
    return rec2(arr, arr.size(), 1);
}

int tab(const vi& arr) {
    const int n = arr.size();
    vvi dp(n + 1, vi(2));
    for (int i = 1; i <= n; ++i) {
        for (int j : {1, 0}) {
            dp[i][j] = max(dp[i - 1][j],
                           dp[i - 1][!j] + arr[i - 1] * (j ? 1 : -1));
        }
    }
    return dp[n][1];
}

int tab2(const vi& arr) {
    const int n = arr.size();
    vvi dp(2, vi(2));
    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        idx = i & 1;
        for (int j : {1, 0}) {
            dp[idx][j] = max(dp[1 - idx][j],
                             dp[1 - idx][!j] + arr[i - 1] * (j ? 1 : -1));
        }
    }
    return dp[idx][1];
}

int main() { TimeMeasure _; __x();
    cout << rec({4,2,5,3}) << endl; // 7
    cout << rec({5,6,7,8}) << endl; // 8
    cout << rec({6,2,1,2,4,5}) << endl; // 10
    cout << endl;
    cout << rec2({4,2,5,3}) << endl; // 7
    cout << rec2({5,6,7,8}) << endl; // 8
    cout << rec2({6,2,1,2,4,5}) << endl; // 10
    cout << endl;
    cout << tab({4,2,5,3}) << endl; // 7
    cout << tab({5,6,7,8}) << endl; // 8
    cout << tab({6,2,1,2,4,5}) << endl; // 10
    cout << endl;
    cout << tab2({4,2,5,3}) << endl; // 7
    cout << tab2({5,6,7,8}) << endl; // 8
    cout << tab2({6,2,1,2,4,5}) << endl; // 10
}
