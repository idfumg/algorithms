#include "../../template.hpp"

int rec(const vi& arr, const int n, const int p, const int m) {
    if (n > arr.size() - 1) return 0;
    if (p == 0) {
        int sum = 0;
        int ans = -INF;
        for (int k = 1; k <= m; ++k) {
            if (n + k - 1 < arr.size()) {
                sum += arr[n + k - 1];
                ans = max(ans, rec(arr, n + k, 1 - p, m) + sum);
            }
        }
        return ans;
    }
    int sum = 0;
    int ans = INF;
    for (int k = 1; k <= m; ++k) {
        if (n + k - 1 < arr.size()) {
            sum += arr[n + k - 1];
            ans = min(ans, rec(arr, n + k, 1 - p, m) - sum);
        }
    }
    return ans;
}

string rec(const vi& arr) {
    const int ans = rec(arr, 0, 0, 3);
    return ans == 0
        ? "Tie"
        : ans > 0
            ? "Alice"
            : "Bob";
}

string tab(const vi& arr) {
    const int n = arr.size();
    const int m = 3;
    vvi dp(n + 1, vi(2));
    for (int i = n - 1; i >= 0; --i) {
        for (int p : {1, 0}) {
            if (p == 0) {
                int sum = 0;
                int ans = -INF;
                for (int k = 1; k <= m; ++k) {
                    if (i + k - 1 < n) {
                        sum += arr[i + k - 1];
                        ans = max(ans, dp[i + k][1 - p] + sum);
                    }
                }
                dp[i][p] = ans;
            }
            else {
                int sum = 0;
                int ans = INF;
                for (int k = 1; k <= m; ++k) {
                    if (i + k - 1 < n) {
                        sum += arr[i + k - 1];
                        ans = min(ans, dp[i + k][1 - p] - sum);
                    }
                }
                dp[i][p] = ans;
            }
        }
    }
    const int ans = dp[0][0];
    return ans == 0
        ? "Tie"
        : ans > 0
            ? "Alice"
            : "Bob";
}

int main() { TimeMeasure _; __x();
    cout << rec({1,2,3,7}) << endl; // Bob
    cout << rec({1,2,3,-9}) << endl; // Alice
    cout << rec({1,2,3,6}) << endl; // Tie
    cout << rec({1,2,3,-1,-2-3,7}) << endl; // Alice
    cout << rec({-1,-2,-3}) << endl; // Tie
    cout << endl;
    cout << tab({1,2,3,7}) << endl; // Bob
    cout << tab({1,2,3,-9}) << endl; // Alice
    cout << tab({1,2,3,6}) << endl; // Tie
    cout << tab({1,2,3,-1,-2-3,7}) << endl; // Alice
    cout << tab({-1,-2,-3}) << endl; // Tie
}
