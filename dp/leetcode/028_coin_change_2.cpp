#include "../../template.hpp"

int rec(const vi& arr, const int target, const int n) {
    if (n == 0 or target < 0) return 0;
    if (target == 0) return 1;

    const int a = rec(arr, target - arr[n - 1], n);
    const int b = rec(arr, target, n - 1);
    return a + b;
}

int rec(const vi& arr, const int target) {
    return rec(arr, target, arr.size());
}

int tab(const vi& arr, const int target) {
    const int n = arr.size();
    vvi dp(target + 1, vi(n + 1));
    for (int j = 1; j <= n; ++j) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= target; ++i) {
        for (int j = 1; j <= n; ++j) {
            const int a = i - arr[j - 1] >= 0 ? dp[i - arr[j - 1]][j] : 0;
            const int b = dp[i][j - 1];
            dp[i][j] = a + b;
        }
    }
    return dp[target][n];
}

int main() { TimeMeasure _; __x();
    cout << rec({1,2,5}, 5) << endl; // 4
    cout << rec({2}, 3) << endl; // 0
    cout << rec({10}, 10) << endl; // 1
    cout << endl;
    cout << tab({1,2,5}, 5) << endl; // 4
    cout << tab({2}, 3) << endl; // 0
    cout << tab({10}, 10) << endl; // 1
}
