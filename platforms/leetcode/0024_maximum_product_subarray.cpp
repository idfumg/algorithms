#include "../../template.hpp"

// int rec(const vi& arr, const int n, const int total) {
//     if (n == 0) return total;
//     return max({
//             total,
//             rec(arr, n - 1, arr[n - 1]),
//             rec(arr, n - 1, arr[n - 1] * (total == -INF ? 1 : total))});
// }

// int rec(const vi& arr) {
//     return rec(arr, arr.size(), -INF);
// }

int rec(const vi& arr, const int n, vi& dp) {
    if (n == 0) return -INF;
    if (dp[n] != -INF) return dp[n];
    const int a = rec(arr, n - 1, dp);
    int total = arr[n - 1];
    int maxi = arr[n - 1];
    for (int k = n - 1; k >= 1; --k) {
        total *= arr[k - 1];
        maxi = max(maxi, total);
    }
    return dp[n] = max(maxi, a);
}

int rec(const vi& arr) {
    const int n = arr.size();
    vi dp(n + 1, -INF);
    return rec(arr, n, dp);
}

int tab(const vi& arr) {
    const int n = arr.size();
    vi dp(n + 1, -INF);
    for (int i = 1; i <= n; ++i) {
        int total = arr[i - 1];
        int maxi = arr[i - 1];
        for (int k = i - 1; k >= 1; --k) {
            total *= arr[k - 1];
            maxi = max(maxi, total);
        }
        dp[i] = max(maxi, dp[i - 1]);
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    cout << rec({2,3,-2,4}) << endl; // 6
    cout << rec({-2,0,-1}) << endl; // 0
    cout << rec({-2}) << endl; // -2
    cout << rec({-2,3,-4}) << endl; // 24
    cout << rec({-2,-3,-4}) << endl; // 12
    cout << rec({0,-1,4,-4,5,-2,-1,-1,-2,-3,0,-3,0,1,-1,-4,4,6,2,3,0,-5,2,1,-4,-2,-1,3,-4,-6,0,2,2,-1,-5,1,1,5,-6,2,1,-3,-6,-6,-3,4,0,-2,0,2}) << endl;
    cout << endl;
    cout << tab({2,3,-2,4}) << endl; // 6
    cout << tab({-2,0,-1}) << endl; // 0
    cout << tab({-2}) << endl; // -2
    cout << tab({-2,3,-4}) << endl; // 24
    cout << tab({-2,-3,-4}) << endl; // 12
    cout << tab({0,-1,4,-4,5,-2,-1,-1,-2,-3,0,-3,0,1,-1,-4,4,6,2,3,0,-5,2,1,-4,-2,-1,3,-4,-6,0,2,2,-1,-5,1,1,5,-6,2,1,-3,-6,-6,-3,4,0,-2,0,2}) << endl;
}
