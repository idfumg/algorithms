#include "../../template.hpp"

int rec(const vi& arr, const int n) {
    if (n <= 0) return 0;
    return max(rec(arr, n - 1), rec(arr, n - 2) + arr[n - 1]);
}

int rec(const vi& arr) {
    return rec(arr, arr.size());
}

int tab(const vi& arr) {
    const int n = arr.size();
    vi dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = max(dp[i - 1], arr[i - 1] + (i >= 2 ? dp[i - 2] : 0));
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    cout << rec({1,2,3,1}) << endl; // 4
    cout << rec({2,7,9,3,1}) << endl; // 12
    cout << endl;
    cout << tab({1,2,3,1}) << endl; // 4
    cout << tab({2,7,9,3,1}) << endl; // 12
}
