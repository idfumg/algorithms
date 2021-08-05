#include "../../template.hpp"

int rec(const vi& arr, const vi& prefix, const int i, const int j, const int p) {
    if (i > j) return 0;
    if (p == 0) {
        return max(
            rec(arr, prefix, i + 1, j, 1 - p) + prefix[j] - prefix[i],
            rec(arr, prefix, i, j - 1, 1 - p) + prefix[j - 1] - prefix[i - 1]);
    }
    return min(
        rec(arr, prefix, i + 1, j, 1 - p) - (prefix[j] - prefix[i]),
        rec(arr, prefix, i, j - 1, 1 - p) - (prefix[j - 1] - prefix[i - 1]));
}

int rec(const vi& arr) {
    const int n = arr.size();
    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    return rec(arr, prefix, 1, n, 0);
}

int tab(const vi& arr) {
    const int n = arr.size();
    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    vvvi dp(n + 2, vvi(n + 1, vi(2)));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            for (int p : {1, 0}) {
                if (i > j) dp[i][j][p] = 0;
                else if (p == 0) {
                    dp[i][j][p] = max(
                        dp[i + 1][j][1 - p] + (prefix[j] - prefix[i]),
                        dp[i][j - 1][1 - p] + (prefix[j - 1] - prefix[i - 1]));
                }
                else {
                    dp[i][j][p] = min(
                        dp[i + 1][j][1 - p] - (prefix[j] - prefix[i]),
                        dp[i][j - 1][1 - p] - (prefix[j - 1] - prefix[i - 1]));
                }
            }
        }
    }
    return dp[1][n][0];
}

int main() { TimeMeasure _; __x();
    cout << rec({5,3,1,4,2}) << endl; // 6
    cout << rec({7,90,5,1,100,10,10,2}) << endl; // 122
    cout << endl;
    cout << tab({5,3,1,4,2}) << endl; // 6
    cout << tab({7,90,5,1,100,10,10,2}) << endl; // 122
}
