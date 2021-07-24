#include "../../template.hpp"

int rec(const vi& arr, const int n, const int one, const int m) {
    if (n >= arr.size()) {
        return 0;
    }

    if (one == 1) {
        int sum = 0;
        int ans = -INF;
        for (int i = 1; i <= 2 * m and n + i - 1 < arr.size(); ++i) {
            sum += arr[n + i - 1];
            ans = max(ans, sum + rec(arr, n + i, 1 - one, max(i, m)));
        }
        return ans;
    }

    int ans = INF;
    for (int i = 1; i <= 2 * m and n + i - 1 < arr.size(); ++i) {
        ans = min(ans, rec(arr, n + i, 1 - one, max(i, m)));
    }
    return ans;
}

int rec(const vi& arr) {
    return rec(arr, 0, 1, 1);
}

int tab(const vi& arr) {
    const int n = arr.size();
    vvvi dp(n + 1, vvi(2, vi(n + 1)));
    for (int i = n - 1; i >= 0; --i) {
        for (int one : {1, 0}) {
            for (int m = n; m >= 1; --m) {
                if (one == 1) {
                    int sum = 0;
                    int ans = -INF;
                    for (int k = 1; k <= 2 * m and i + k - 1 < n; ++k) {
                        sum += arr[i + k - 1];
                        ans = max(ans, sum + dp[i + k][1 - one][max(k, m)]);
                    }
                    dp[i][one][m] = ans;
                }
                else {
                    int ans = INF;
                    for (int k = 1; k <= 2 * m and i + k - 1 < n; ++k) {
                        ans = min(ans, dp[i + k][1 - one][max(k, m)]);
                    }
                    dp[i][one][m] = ans;
                }
            }
        }
    }
    return dp[0][1][1];
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
