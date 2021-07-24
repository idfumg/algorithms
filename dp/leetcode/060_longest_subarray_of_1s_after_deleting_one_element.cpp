#include "../../template.hpp"

int rec(const vi& arr, const int n, const int k, const int total) {
    if (n == 0) return total - k;
    if (arr[n - 1] == 0 and k > 1) return max({
            total - k,
            rec(arr, n - 1, 0, total),
            rec(arr, n - 1, k, 0)});
    if (arr[n - 1] == 0 and k == 0) return max(
        total - k,
        rec(arr, n - 1, k, 0));
    return rec(arr, n - 1, k, total + 1);
}

int rec(const vi& arr) {
    return rec(arr, arr.size(), 1, 0);
}

int rec2(const vi& arr, const int n, const int k) {
    if (n == 0) return -k;
    if (arr[n - 1] == 0 and k == 0) return 0;
    if (arr[n - 1] == 0 and k > 0) return rec2(arr, n - 1, k - 1);
    return rec2(arr, n - 1, k) + 1;
}

int rec2(const vi& arr) {
    int ans = 0;
    for (int i = 1; i <= arr.size(); ++i) {
        ans = max(ans, rec2(arr, i, 1));
    }
    return ans;
}

int tab(const vi& arr) {
    const int n = arr.size();
    vvi dp(n + 1, vi(2));
    dp[0][1] = -1;
    for (int i = 1; i <= n; ++i) {
        for (int k : {0, 1}) {
            if (arr[i - 1] == 0 and k == 0) dp[i][k] = 0;
            else if (arr[i - 1] == 0 and k > 0) dp[i][k] = dp[i - 1][k - 1];
            else dp[i][k] = dp[i - 1][k] + 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i][1]);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << rec({1,1,0,1}) << endl; // 3
    cout << rec({0,1,1,1,0,1,1,0,1}) << endl; // 5
    cout << rec({1,1,1}) << endl; // 2
    cout << rec({1,1,0,0,1,1,1,0,1}) << endl; // 4
    cout << rec({0,0,0}) << endl; // 0
    cout << endl;
    cout << rec2({1,1,0,1}) << endl; // 3
    cout << rec2({0,1,1,1,0,1,1,0,1}) << endl; // 5
    cout << rec2({1,1,1}) << endl; // 2
    cout << rec2({1,1,0,0,1,1,1,0,1}) << endl; // 4
    cout << rec2({0,0,0}) << endl; // 0
    cout << endl;
    cout << tab({1,1,0,1}) << endl; // 3
    cout << tab({0,1,1,1,0,1,1,0,1}) << endl; // 5
    cout << tab({1,1,1}) << endl; // 2
    cout << tab({1,1,0,0,1,1,1,0,1}) << endl; // 4
    cout << tab({0,0,0}) << endl; // 0
}
