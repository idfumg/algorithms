#include "../../template.hpp"

int rec(const vi& arr, const int i, const int j, const int p) {
    if (i > j) return 0;
    if (p == 0) return max(rec(arr, i + 1, j, 1 - p) + arr[i - 1],
                           rec(arr, i, j - 1, 1 - p) + arr[j - 1]);
    return min(rec(arr, i + 1, j, 1 - p) - arr[i - 1],
               rec(arr, i, j - 1, 1 - p) - arr[j - 1]);
}

int rec(const vi& arr) {
    return rec(arr, 1, arr.size(), 0) > 0;
}

int tab(const vi& arr) {
    const int n = arr.size();
    vvvi dp(n + 2, vvi(n + 1, vi(2)));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            for (int p = 1; p >= 0; --p) {
                if (i > j) {
                    dp[i][j][p] = 0;
                }
                else if (p == 0) {
                    dp[i][j][p] = max(dp[i + 1][j][1 - p] + arr[i - 1],
                                      dp[i][j - 1][1 - p] + arr[j - 1]);
                }
                else {
                    dp[i][j][p] = min(dp[i + 1][j][1 - p] - arr[i - 1],
                                      dp[i][j - 1][1 - p] - arr[j - 1]);
                }
            }
        }
    }
    return dp[1][n][0] > 0;
}

int main() { TimeMeasure _; __x();
    cout << rec({5,3,4,5}) << endl;
    cout << endl;
    cout << tab({5,3,4,5}) << endl;
    cout << tab({7,7,12,16,41,48,41,48,11,9,34,2,44,30,27,12,11,39,31,8,23,11,47,25,15,23,4,17,11,50,16,50,38,34,48,27,16,24,22,48,50,10,26,27,9,43,13,42,46,24}) << endl;
}
