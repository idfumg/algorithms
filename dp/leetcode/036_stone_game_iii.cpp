#include "../../template.hpp"

int rec(const vi& arr, const int n, const int one) {
    if (n >= arr.size()) return 0;
    if (one == 1) {
        int ans = -INF;
        int sum = 0;
        for (int k = 1; k <= 3 and n + k - 1 < arr.size(); ++k) {
            sum += arr[n + k - 1];
            ans = max(ans, sum + rec(arr, n + k, 0));
        }
        return ans;
    }
    int ans = INF;
    int sum = 0;
    for (int k = 1; k <= 3 and n + k - 1 < arr.size(); ++k) {
        sum += arr[n + k - 1];
        ans = min(ans, -sum + rec(arr, n + k, 1));
    }
    return ans;
}

string rec(const vi& arr) {
    const int res = rec(arr, 0, 1);
    if (res == 0) return "Tie";
    return res > 0 ? "Alice" : "Bob";
}

string tab(const vi& arr) {
    const int n = arr.size();
    vvi dp(n + 2, vi(2));
    for (int i = n - 1; i >= 0; --i) {
        for (int one : {0, 1}) {
            if (one == 1) {
                int ans = -INF;
                int sum = 0;
                for (int k = 1; k <= 3 and i + k - 1 < n; ++k) {
                    sum += arr[i + k - 1];
                    ans = max(ans, sum + dp[i + k][0]);
                }
                dp[i][one] = ans;
            }
            else {
                int ans = INF;
                int sum = 0;
                for (int k = 1; k <= 3 and i + k - 1 < n; ++k) {
                    sum += arr[i + k - 1];
                    ans = min(ans, -sum + dp[i + k][1]);
                }
                dp[i][one] = ans;
            }
        }
    }
    const int res = dp[0][1];
    if (res == 0) return "Tie";
    return res > 0 ? "Alice" : "Bob";
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
