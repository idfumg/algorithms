#include "../../template.hpp"

int cadanes(const vi& arr) {
    const int n = arr.size();
    vi dp(n);
    dp[0] = arr[0];
    int ans = arr[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int cadanes2(const vi& arr) {
    const int n = arr.size();
    vi dp(2);
    dp[0] = arr[0];
    int ans = arr[0];
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        idx = i & 1;
        dp[idx] = max(arr[i], dp[1 - idx] + arr[i]);
        ans = max(ans, dp[idx]);
    }
    return ans;
}

int rec(const vi& arr, const int n, int& ans) {
    if (n == 0) return 0;
    const int res = max(arr[n - 1], arr[n - 1] + rec(arr, n - 1, ans));
    ans = max(ans, res);
    return res;
}

int rec(const vi& arr) {
    int ans = -INF;
    rec(arr, arr.size(), ans);
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << cadanes({-2,1,-3,4,-1,2,1,-5,4}) << endl; // 6
    cout << cadanes({1}) << endl; // 1
    cout << cadanes({5,4,-1,7,8}) << endl; // 23
    cout << endl;
    cout << cadanes2({-2,1,-3,4,-1,2,1,-5,4}) << endl; // 6
    cout << cadanes2({1}) << endl; // 1
    cout << cadanes2({5,4,-1,7,8}) << endl; // 23
    cout << endl;
    cout << rec({-2,1,-3,4,-1,2,1,-5,4}) << endl; // 6
    cout << rec({1}) << endl; // 1
    cout << rec({5,4,-1,7,8}) << endl; // 23
}
