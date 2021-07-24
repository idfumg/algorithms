#include "../../template.hpp"

int rec(const vi& arr, const vi& prefix, const int i, const int j, const int one) {
    if (i >= j) return 0;
    if (one) return max(
        rec(arr, prefix, i + 1, j, 0) + prefix[j] - prefix[i],
        rec(arr, prefix, i, j - 1, 0) + prefix[j - 1] - prefix[i - 1]);
    return min(
        rec(arr, prefix, i + 1, j, 1) - prefix[j] + prefix[i],
        rec(arr, prefix, i, j - 1, 1) - prefix[j - 1] + prefix[i - 1]);
}

int rec(const vi& arr) {
    const int n = arr.size();
    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    return rec(arr, prefix, 1, n, 1);
}

int tab(const vi& arr) {
    const int n = arr.size();
    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    int idx = 0;
    vvvi dp(2, vvi(n + 1, vi(2)));
    for (int i = n; i >= 1; --i) {
        idx = i & 1;
        for (int j = 1; j <= n; ++j) {
            for (int one : {0, 1}) {
                if (i >= j) {
                    dp[idx][j][one] = 0;
                }
                else if (one) {
                    dp[idx][j][1] = max(
                        dp[1 - idx][j][0] + prefix[j] - prefix[i],
                        dp[idx][j - 1][0] + prefix[j - 1] - prefix[i - 1]);
                }
                else {
                    dp[idx][j][0] = min(
                        dp[1 - idx][j][1] - prefix[j] + prefix[i],
                        dp[idx][j - 1][1] - prefix[j - 1] + prefix[i - 1]);
                }
            }
        }
    }
    return dp[idx][n][1];
}

int main() { TimeMeasure _; __x();
    cout << rec({5,3,1,4,2}) << endl; // 6
    cout << rec({7,90,5,1,100,10,10,2}) << endl; // 122
    cout << endl;
    cout << tab({5,3,1,4,2}) << endl; // 6
    cout << tab({7,90,5,1,100,10,10,2}) << endl; // 122
}
