#include "../../template.hpp"

int rec(const vi& arr, const int k, const int n) {
    if (n <= 0) return 0;
    int ans = -INF, maxi = -INF;
    for (int i = 1; i <= k and n - i >= 0; ++i) {
        maxi = max(maxi, arr[n - i]);
        ans = max(ans, maxi * i + rec(arr, k, n - i));
    }
    return ans;
}

int rec(const vi& arr, const int k) {
    return rec(arr, k, arr.size());
}

int tab(const vi& arr, const int k) {
    const int n = arr.size();
    vi dp(n + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
        int maxi = -INF;
        for (int count = 1; count <= k and i - count >= 0; ++count) {
            maxi = max(maxi, arr[i - count]);
            dp[i] = max(dp[i], maxi * count + dp[i - count]);
        }
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    cout << rec({1,15,7,9,2,5,10}, 3) << endl; // 84
    cout << rec({1,4,1,5,7,3,6,1,9,9,3}, 4) << endl; // 83
    cout << rec({1}, 1) << endl; // 1
    cout << endl;
    cout << tab({1,15,7,9,2,5,10}, 3) << endl; // 84
    cout << tab({1,4,1,5,7,3,6,1,9,9,3}, 4) << endl; // 83
    cout << tab({1}, 1) << endl; // 1
}
