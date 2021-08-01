#include "../../template.hpp"

int rec(const vi& arr, const int n, const int M, const int p) {
    if (n > arr.size() - 1) {
        return 0;
    }
    if (p == 0) {
        int sum = 0;
        int ans = -INF;
        for (int k = 1; k <= 2 * M; ++k) {
            if (n + k - 1 < arr.size()) {
                sum += arr[n + k - 1];
                ans = max(ans, rec(arr, n + k, max(k, M), 1 - p) + sum);
            }
        }
        return ans;
    }
    int ans = INF;
    for (int k = 1; k <= 2 * M; ++k) {
        if (n + k - 1 < arr.size()) {
            ans = min(ans, rec(arr, n + k, max(k, M), 1 - p));
        }
    }
    return ans;
}

int rec(const vi& arr) {
    return rec(arr, 0, 1, 0);
}

int tab(const vi& arr) {
    const int n = arr.size();
    vvvi dp(n + 1, vvi(n + 1, vi(2)));
    for (int i = n - 1; i >= 0; --i) {
        for (int m = n - 1; m >= 1; --m) {
            for (int p : {1, 0}) {
                if (p == 0) {
                    int sum = 0;
                    int ans = -INF;
                    for (int k = 1; k <= 2 * m; ++k) {
                        if (i + k - 1 < n) {
                            sum += arr[i + k - 1];
                            ans = max(ans, sum + dp[i + k][max(k, m)][1 - p]);
                        }
                    }
                    dp[i][m][p] = ans;
                }
                else {
                    int ans = INF;
                    for (int k = 1; k <= 2 * m; ++k) {
                        if (i + k - 1 < n) {
                            ans = min(ans, dp[i + k][max(k, m)][1 - p]);
                        }
                    }
                    dp[i][m][p] = ans;
                }
            }
        }
    }
    return dp[0][1][0];
}

int main() { TimeMeasure _; __x();
    cout << rec({2,7,9,4,4}) << endl; // 10
    cout << rec({1,2,3,4,5,100}) << endl; // 104
    cout << rec({88,65,58,68,64,28,12,79}) << endl; // 260
    cout << endl;
    cout << tab({2,7,9,4,4}) << endl; // 10
    cout << tab({1,2,3,4,5,100}) << endl; // 104
    cout << tab({88,65,58,68,64,28,12,79}) << endl; // 260
}
