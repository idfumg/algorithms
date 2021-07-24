#include "../../template.hpp"

int rec(const vi& arr, const int n, const int target) {
    if (target == 0) return 1;
    if (target < 0 or n == 0) return 0;
    return rec(arr, n - 1, target) or rec(arr, n - 1, target - arr[n - 1]);
}

int rec(const vi& arr) {
    int n = arr.size();
    int total = reduce(cbegin(arr), cend(arr), 0);
    int target = total / 2;
    if (2 * target != total) return 0;
    return rec(arr, n, target);
}

int tab(const vi& arr) {
    int n = arr.size();
    int total = reduce(cbegin(arr), cend(arr), 0);
    int target = total / 2;
    if (2 * target != total) return 0;
    vvi dp(n + 1, vi(target + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= target; ++j) {
            if (j == 0) dp[i][j] = 1;
            else if (i == 0) dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] or (j >= arr[i - 1] ? dp[i - 1][j - arr[i - 1]] : 0);
        }
    }
    return dp[n][target];
}

int main() { TimeMeasure _; __x();
    cout << rec({1,5,11,5}) << endl; // 1
    cout << rec({1,2,3,5}) << endl; // 0
    cout << endl;
    cout << tab({1,5,11,5}) << endl; // 1
    cout << tab({1,2,3,5}) << endl; // 0
}
