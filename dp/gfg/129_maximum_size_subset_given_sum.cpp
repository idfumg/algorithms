#include "../../template.hpp"

int rec(vi arr, int sum, int n, int count) {
    if (sum == 0) return count;
    if (n == 0 or sum < 0) return -INF;
    return max(rec(arr, sum, n - 1, count),
               rec(arr, sum - arr[n - 1], n - 1, count + 1));
}

int rec(vi arr, int sum) {
    return rec(arr, sum, arr.size(), 0);
}

int rec2(vi arr, int sum, int n) {
    if (sum == 0) return 0;
    if (n == 0 or sum < 0) return -INF;
    return max(rec2(arr, sum, n - 1),
               rec2(arr, sum - arr[n - 1], n - 1) + 1);
}

int rec2(vi arr, int sum) {
    return rec2(arr, sum, arr.size());
}

int tab(vi arr, int sum) {
    int n = arr.size();
    vvvi dp(sum + 1, vvi(n + 1, vi(n + 2)));
    for (int i = 0; i <= sum; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = n; k >= 0; --k) {
                if (i == 0) {
                    dp[i][j][k] = k;
                }
                else if (j == 0) {
                    dp[i][j][k] = -INF;
                }
                else {
                    dp[i][j][k] = dp[i][j - 1][k];
                    if (i >= arr[j - 1]) {
                        dp[i][j][k] = max(dp[i][j][k],
                                          dp[i - arr[j - 1]][j - 1][k + 1]);
                    }
                }
            }
        }
    }
    return dp[sum][n][0];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {2, 3, 5, 7, 10, 15}; int sum1 = 10; // 3
    vi arr2 = {1, 2, 3, 4, 5}; int sum2 = 4; // 2
    vi arr3 = {2, 3, 5, 10}; int sum3 = 20; // 4

    cout << rec(arr1, sum1) << endl;
    cout << rec(arr2, sum2) << endl;
    cout << rec(arr3, sum3) << endl;
    cout << '\n';
    cout << rec2(arr1, sum1) << endl;
    cout << rec2(arr2, sum2) << endl;
    cout << rec2(arr3, sum3) << endl;
    cout << '\n';
    cout << tab(arr1, sum1) << endl;
    cout << tab(arr2, sum2) << endl;
    cout << tab(arr3, sum3) << endl;
}
